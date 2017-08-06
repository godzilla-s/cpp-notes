//迭代器
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class IProject
{
public:
    IProject(void)
    {
    }
    virtual ~IProject(void)
    {
    }
    virtual void Add(string name, int num, int cost) = 0;
    virtual string GetProjectInfo() = 0;
    virtual IProjectIterator* GetIterator() = 0;
    virtual void Erase() = 0;
};

class CProject : public IProject
{
public:
    CProject(void);
    CProject(string name, int num, int cost);
    ~CProject(void);
    string GetProjectInfo();
    void Add(string name, int num, int cost);
    IProjectIterator * GetIterator();
    void Erase();
private:
    string m_name;
    int m_num;
    int m_cost;
    vector<IProject*> m_projectList;
};

CProject::CProject( void )
{
    m_name = "";
    m_num = 0;
    m_cost = 0;
}
CProject::CProject(string name, int num, int cost) :m_name(name), m_num(num), m_cost(cost)
{
}
CProject::~CProject(void)
{
}
string CProject::GetProjectInfo()
{
    string info = "";
    info.append("项目名称是：");
    info.append(this->m_name);
    info.append("\t项目人数：");
    info.append(CConvert::ToString(m_num));
    info.append("\t项目费用：");
    info.append(CConvert::ToString(m_cost));
    return info;
}
void CProject::Add( string name, int num, int cost )
{
    this->m_projectList.push_back(new CProject(name, num, cost));
}
IProjectIterator * CProject::GetIterator()
{
    return new CProjectIterator(this->m_projectList);
}
void CProject::Erase()
{
    vector<IProject*>::reverse_iterator projectDelIt = m_projectList.rbegin();
    for (; projectDelIt != m_projectList.rend(); projectDelIt++)
    {
        delete (*projectDelIt);
        (*projectDelIt) = NULL;
    }
    m_projectList.clear();
}

class IProject;
class IIterator
{
public:
    IIterator(void)
    {
    }
    virtual ~IIterator(void)
    {
    }
    virtual bool HasNext() = 0;
    virtual IProject * Next() = 0;
};

class IProject;
class IProjectIterator : public IIterator
{
public:
    IProjectIterator(void)
    {
    }
    virtual ~IProjectIterator(void)
    {
    }
    virtual bool HasNext() = 0;
    virtual IProject * Next() = 0;
};

class CProjectIterator : public IProjectIterator
{
public:
    CProjectIterator(vector<IProject *> pl);
    ~CProjectIterator(void);
    bool HasNext();
    IProject * Next();
private:
    vector<IProject *> m_projectList;
    size_t m_currentItem;
};

CProjectIterator::CProjectIterator(vector<IProject *> pl) : m_projectList(pl)
{
    m_currentItem = 0;
}
CProjectIterator::~CProjectIterator(void)
{
}
bool CProjectIterator::HasNext()
{
    bool b = true;
    if (m_currentItem >= m_projectList.size())
        b = false;
    return b;
}
IProject * CProjectIterator::Next()
{
    IProject *pp = m_projectList.at(m_currentItem ++);
    return pp;
}

void DoIt()
{
    cout << "----------未使用迭代模式----------" << endl;
    vector<IProject*> projectList;

    projectList.push_back(new CProject("星球大战项目", 10, 100000));
    projectList.push_back(new CProject("扭转时空项目", 100, 10000000));
    projectList.push_back(new CProject("超人改造项目", 10000, 1000000000));

    for (int i = 4; i < 6; i ++)
    {
        string name = "";
        name.append("第");
        name.append(CConvert::ToString(i));
        name.append("个项目");
        projectList.push_back(new CProject(name, i * 5, i * 1000000));
    }

    vector<IProject*>::const_iterator projectIt = projectList.begin();
    for (; projectIt != projectList.end(); projectIt++)
        cout << (*projectIt)->GetProjectInfo().c_str() << endl;

    vector<IProject*>::reverse_iterator projectDelIt = projectList.rbegin();
    for (; projectDelIt != projectList.rend(); projectDelIt++)
    {
        delete (*projectDelIt);
        (*projectDelIt) = NULL;
    }
    projectList.clear();
}

void DoNew()
{
    cout << "----------使用迭代模式----------" << endl;
    IProject *pproject = new CProject();
    pproject->Add("星球大战项目", 10, 100000);
    pproject->Add("扭转时空项目", 100, 10000000);
    pproject->Add("超人改造项目", 10000, 1000000000);

    for (int i = 4; i < 6; i ++)
    {
        string name = "";
        name.append("第");
        name.append(CConvert::ToString(i));
        name.append("个项目");
        pproject->Add(name, i * 5, i * 1000000);
    }

    IProjectIterator *pprojectIt = pproject->GetIterator();
    while(pprojectIt->HasNext())
    {
        IProject *p = dynamic_cast<IProject*>(pprojectIt->Next());
        cout << p->GetProjectInfo().c_str() << endl;
    }
    delete pprojectIt;
    pprojectIt = NULL;
    pproject->Erase();
    delete pproject;
    pproject = NULL;
}

int main(int argc, char* argv[])
{
    //使用Iterator模式之前
    DoIt();

    //使用Iterator
    DoNew();

    return 0;
}
