#include <iostream>
#include <string>

using namespace std;

class CCommonEmployee;
class CManager;
class IVisitor
{
public:

    IVisitor(void)
    {
    }

    virtual ~IVisitor(void)
    {
    }
    virtual void Visit(CCommonEmployee commonEmployee) = 0;
    virtual void Visit(CManager manager) = 0;
    virtual int GetTotalSalary() = 0;
};

class CBaseVisitor :
    public IVisitor
{
public:
    CBaseVisitor(void);
    ~CBaseVisitor(void);
    void Visit(CCommonEmployee commonEmployee);
    void Visit(CManager manager);
    int GetTotalSalary();
private:
    string GetBasicInfo(CEmployee *pemployee);
    string GetManagerInfo(CManager manager);
    string GetCommonEmployee(CCommonEmployee employee);
    static const int MANAGER_COEFFICENT = 5;
    static const int COMMONEMPLOYEE_COEFFICENT = 2;
    int m_commonTotal;
    int m_managerTotal;
    void CalCommonSalary(int salary);
    void CalManagerSalary(int salary);
};

CBaseVisitor::CBaseVisitor(void)
{
    m_commonTotal = 0;
    m_managerTotal = 0;
}

CBaseVisitor::~CBaseVisitor(void)
{
}

void CBaseVisitor::Visit(CCommonEmployee commonEmployee)
{
    cout << this->GetCommonEmployee(commonEmployee).c_str() << endl;
    this->CalCommonSalary(commonEmployee.GetSalary());
}

void CBaseVisitor::Visit(CManager manager)
{
    cout << this->GetManagerInfo(manager).c_str() << endl;
    this->CalManagerSalary(manager.GetSalary());
}

string CBaseVisitor::GetBasicInfo(CEmployee *pemployee)
{
    string info = "";
    info.append("姓名：");
    info.append(pemployee->GetName());
    info.append("\t");
    info.append("性别：");
    info.append(CConvert::ToString(pemployee->GetSex()));
    info.append("\t");
    info.append("薪水：");
    info.append(CConvert::ToString(pemployee->GetSalary()));
    info.append("\t");
    return info;
}

string CBaseVisitor::GetManagerInfo(CManager manager)
{
    string basicInfo = this->GetBasicInfo(&manager);
    string otherInfo = "";
    otherInfo.append("业绩：");
    otherInfo.append(manager.GetPerformance());
    otherInfo.append("\t");
    basicInfo.append(otherInfo);
    return basicInfo;
}

string CBaseVisitor::GetCommonEmployee(CCommonEmployee employee)
{
    string basicInfo = this->GetBasicInfo(&employee);
    string otherInfo = "";
    otherInfo.append("工作：");
    otherInfo.append(employee.GetJob());
    otherInfo.append("\t");
    basicInfo.append(otherInfo);
    return basicInfo;
}

int CBaseVisitor::GetTotalSalary()
{
    return this->m_commonTotal + this->m_managerTotal;
}

void CBaseVisitor::CalCommonSalary(int salary)
{
    this->m_commonTotal += salary;
}

void CBaseVisitor::CalManagerSalary(int salary)
{
    this->m_managerTotal += salary;
}

class CEmployee
{
public:
  static int MALE;
  static int FEMALE;
  CEmployee(void);
  virtual ~CEmployee(void);
  string GetName();
  void SetName(string name);
  int GetSalary();
  void SetSalary(int v);
  int GetSex();
  void SetSex(int v);
  virtual void Accept(IVisitor *pVisitor) = 0;
private:
  string m_name;
  int m_salary;
  int m_sex;
};

int CEmployee::MALE = 0;
int CEmployee::FEMALE = 1;

CEmployee::CEmployee(void)
{
}

CEmployee::~CEmployee(void)
{
}

string CEmployee::GetName()
{
return m_name;
}

void CEmployee::SetName( string name )
{
m_name = name;
}

int CEmployee::GetSalary()
{
return m_salary;
}

void CEmployee::SetSalary( int v )
{
m_salary = v;
}

int CEmployee::GetSex()
{
return m_sex;
}

void CEmployee::SetSex( int v )
{
m_sex = v;
}

class CManager :
public CEmployee
{
public:
CManager(void);
~CManager(void);
string GetPerformance();
void SetPerformance(string per);
void Accept(IVisitor *pVisitor);
protected:
string GetOtherInfo();
private:
string m_performance;
};

CManager::CManager(void)
{
this->m_performance = "";
}

CManager::~CManager(void)
{
}

string CManager::GetPerformance()
{
return m_performance;
}

void CManager::SetPerformance(string per)
{
this->m_performance = per;
}

string CManager::GetOtherInfo()
{
string info = "";
info.append("业绩：");
info.append(this->m_performance);
info.append("\t");
return info;
}

void CManager::Accept(IVisitor *pVisitor)
{
pVisitor->Visit(*this);
}

void MockEmployee(vector<CEmployee*> *pvce)
{
CCommonEmployee *pZhangSan = new CCommonEmployee();
pZhangSan->SetJob("编写Java程序，绝对的蓝领、苦工加搬运工");
pZhangSan->SetName("张三");
pZhangSan->SetSalary(1800);
pZhangSan->SetSex(CEmployee::MALE);
pvce->push_back(pZhangSan);

CCommonEmployee *pLiSi = new CCommonEmployee();
pLiSi->SetJob("页面美工，审美素质太不流行了！");
pLiSi->SetName("李四");
pLiSi->SetSalary(1900);
pLiSi->SetSex(CEmployee::FEMALE);
pvce->push_back(pLiSi);

CManager *pWangWu = new CManager();
pWangWu->SetPerformance("基本上是负值，但是我会拍马屁呀");
pWangWu->SetName("王五");
pWangWu->SetSalary(1900);
pWangWu->SetSex(CEmployee::FEMALE);
pvce->push_back(pWangWu);
}

void DoIt()
{
vector<CEmployee*> vce;
MockEmployee(&vce);
vector<CEmployee*>::const_iterator readIt = vce.begin();

CBaseVisitor visitor;
for (; readIt != vce.end(); readIt ++)
{
(*readIt)->Accept(&visitor);
}
cout << "本公司的月工资总额是：" << CConvert::ToString(visitor.GetTotalSalary()).c_str() << endl;

vector<CEmployee*>::reverse_iterator delIt = vce.rbegin();
for (; delIt != vce.rend(); delIt++)
{
delete (*delIt);
(*delIt) = NULL;
}
vce.clear();
}

int main(int argc, char * argv[])
{
DoIt();
return 0;
}
