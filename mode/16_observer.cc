#include <iostream>
#include <string>

using namespace std;

class IObservable
{
public:
    IObservable(void)
    {
    }
    virtual ~IObservable(void)
    {
    }
    virtual void AddObserver(IObserver *pObserver) = 0;
    virtual void DeleteObserver(IObserver *pObserver) = 0;
    virtual void NotifyObservers(string context) = 0;
};

class CHanFeiziObservable : public IObservable
{
public:
    CHanFeiziObservable(void);
    ~CHanFeiziObservable(void);
    void AddObserver(IObserver *pObserver);
    void DeleteObserver(IObserver *pObserver);
    void NotifyObservers(string context);
    void HaveBreakfast();
    void HaveFun();
private:
    vector<IObserver*> m_observerList;
    typedef vector<IObserver*>::const_iterator ObserverList_C_iterator;
};

CHanFeiziObservable::CHanFeiziObservable(void)
{
}
CHanFeiziObservable::~CHanFeiziObservable(void)
{
}
void CHanFeiziObservable::AddObserver( IObserver *pObserver )
{
    m_observerList.push_back(pObserver);
}
void CHanFeiziObservable::DeleteObserver( IObserver *pObserver )
{
    ObserverList_C_iterator it = m_observerList.begin();
    for (; it != m_observerList.end(); it++)
    {
        string name = (*it)->GetName();
        if (name.compare(pObserver->GetName()) == 0)
        {
            //找到了删除。
        }
    }
}
void CHanFeiziObservable::NotifyObservers( string context )
{
    ObserverList_C_iterator it = m_observerList.begin();
    for (; it != m_observerList.end(); it ++)
    {
        (*it)->Update(context);
    }
}
void CHanFeiziObservable::HaveBreakfast()
{
    cout << "韩非子：开始吃饭了..." << endl;

    this->NotifyObservers("韩非子在吃饭");
}
void CHanFeiziObservable::HaveFun()
{
    cout << "韩非子：开始娱乐了..." << endl;

    this->NotifyObservers("韩非子在娱乐");
}

class IObserver
{
public:
    IObserver(string _name)
    {
        this->m_name = _name;
    }
    virtual ~IObserver(void)
    {
    }
    virtual void Update(string context) = 0;
    virtual string GetName() = 0;//为c++单独增加的函数，用于删除时查找观察者。
protected:
    string m_name;
};

class CLiSiObserver : public IObserver
{
public:
    CLiSiObserver(void);
    ~CLiSiObserver(void);
    void Update(string context);
    string GetName();
private:
    void ReportToQinShiHuang(string report);
};

CLiSiObserver::CLiSiObserver(void) : IObserver("李斯")
{
}
CLiSiObserver::~CLiSiObserver(void)
{
}
void CLiSiObserver::Update( string context )
{
    cout << "李斯：观察到韩非子活动，开始向老板汇报了..." << endl;
    this->ReportToQinShiHuang(context);
    cout << "李斯：汇报完毕，秦老板赏给他两个萝卜吃吃..." << endl;
}
void CLiSiObserver::ReportToQinShiHuang( string report )
{
    cout << "李斯：报告，秦老板！韩非子有活动了--->" << report.c_str() << endl;
}
string CLiSiObserver::GetName()
{
    return m_name;
}

class CZhouSiObserver : public IObserver
{
public:
    CZhouSiObserver(void);
    ~CZhouSiObserver(void);
    void Update(string context);
    string GetName();
private:
    void Cry(string report);
};

CZhouSiObserver::CZhouSiObserver(void) : IObserver("周斯")
{
}
CZhouSiObserver::~CZhouSiObserver(void)
{
}
void CZhouSiObserver::Update( string context )
{
    cout << "周斯：观察到韩非子活动，自己也开始活动了..." << endl;
    this->Cry(context);
    cout << "周斯：真真的哭列了..." << endl;
}
void CZhouSiObserver::Cry( string report )
{
    cout << "周斯：为因" << report.c_str() << ", ————所以我悲伤呀！" << endl;
}
string CZhouSiObserver::GetName()
{
    return m_name;
}

void DoNew()
{
    //IHanFeiZi.h, HanFeiZiNew.h, ILiSi.h, LiSi.h
   // cout << "----------用新的方法试试----------" << endl;

    //CHanFeiZiNew hanfeizi;

    //hanfeizi.HaveBreakfast();

    //hanfeizi.HaveFun();
}


void DoNewNew()
{
    //IObservable.h, HanfeiziObservable.h, IObserver.h, LiSiObserver.h
    cout << "----------用更新的方法再试试----------" << endl;
    IObserver *pLiSi = new CLiSiObserver();
    IObserver *pZhouSi = new CZhouSiObserver();

    CHanFeiziObservable *pHanFeiZi = new CHanFeiziObservable();

    pHanFeiZi->AddObserver(pLiSi);
    pHanFeiZi->AddObserver(pZhouSi);
    pHanFeiZi->HaveBreakfast();

    delete pLiSi;
    pLiSi = NULL;
    delete pHanFeiZi;
    pHanFeiZi = NULL;
}


int _tmain(int argc, _TCHAR* argv[])
{
    //比较原始的方法，用线程来观察。
    //DoIt();

    //把李斯这个类聚集到韩非子这个类上，这样的话耦合度太高了，还是用更抽象的方式。
    DoNew();

    //更抽象的方式，想要观察韩非子的人多了去了，不可能只允许李斯观察。
    DoNewNew();

    return 0;
}

