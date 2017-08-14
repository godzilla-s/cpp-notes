#include <iostream>
#include <string>

using namespace std;

class IWomen
{
public:
    IWomen(void)
    {
    }
    virtual ~IWomen(void)
    {
    }
    virtual int GetType() = 0;
    virtual string GetRequest() = 0;
};

class CWomen :
    public IWomen
{
public:
    CWomen(int _type, string _request);
    ~CWomen(void);
    int GetType();
    string GetRequest();
private:
    int m_type;
    string m_request;
};

CWomen::CWomen( int _type, string _request )
{
    this->m_type = _type;
    switch (this->m_type)
    {
    case 1:
        this->m_request.append("女儿的请求是：");
        this->m_request.append(_request);
        break;
    case 2:
        this->m_request.append("妻子的请求是：");
        this->m_request.append(_request);
        break;
    case 3:
        this->m_request.append("母亲的请求是：");
        this->m_request.append(_request);
        break;
    }
}
CWomen::~CWomen(void)
{
}
int CWomen::GetType()
{
    return m_type;
}
string CWomen::GetRequest()
{
    return m_request;
}

class CHandler
{
public:
    CHandler(int _level);
    virtual ~CHandler(void);
    void HandleMessage(IWomen *pwomen);
    void SetNext(CHandler *phandler);
    virtual void Response(IWomen *pwomen) = 0;
private:
    int m_level;
    CHandler *m_pNextHandler;
};

CHandler::CHandler(int _level ) : m_level(_level)
{
    m_pNextHandler = NULL;
}
CHandler::~CHandler(void)
{
}
void CHandler::HandleMessage( IWomen *pwomen )
{
    if (pwomen->GetType() == this->m_level)
    {
        this->Response(pwomen);
    }
    else
    {
        if(this->m_pNextHandler != NULL)
            this->m_pNextHandler->HandleMessage(pwomen);
        else
            cout << "----------没地方请示了，不做处理！----------" << endl;
    }
}
void CHandler::SetNext( CHandler *phandler )
{
    m_pNextHandler = phandler;
}

class CFather :
    public CHandler
{
public:
    CFather(void);
    ~CFather(void);
    void Response(IWomen *pwomen);
};

//Father.cpp

#include "StdAfx.h"
#include "Father.h"
#include <iostream>
using std::cout;
using std::endl;
CFather::CFather(void) : CHandler(1)
{
}
CFather::~CFather(void)
{
}
void CFather::Response( IWomen *pwomen )
{
    cout << "女儿向父亲请示：" << endl;
    cout << pwomen->GetRequest().c_str() << endl;
    cout << "父亲的答复是：同意" << endl;
}

class CHusband :
    public CHandler
{
public:
    CHusband(void);
    ~CHusband(void);
    void Response(IWomen *pwomen);
};

//Husband.cpp

#include "StdAfx.h"
#include "Husband.h"
#include <iostream>
using std::cout;
using std::endl;
CHusband::CHusband(void) : CHandler(2)
{
}
CHusband::~CHusband(void)
{
}
void CHusband::Response( IWomen *pwomen )
{
    cout << "妻子向丈夫请示：" << endl;
    cout << pwomen->GetRequest().c_str() << endl;
    cout << "丈夫的答复是：同意" << endl;
}

class CSon :
    public CHandler
{
public:
    CSon(void);
    ~CSon(void);
    void Response(IWomen *pwomen);
};

//Son.cpp

#include "StdAfx.h"
#include "Son.h"
#include <iostream>
using std::cout;
using std::endl;
CSon::CSon(void) : CHandler(3)
{
}
CSon::~CSon(void)
{
}
void CSon::Response( IWomen *pwomen )
{
    cout << "母亲向儿子请示：" << endl;
    cout << pwomen->GetRequest().c_str() << endl;
    cout << "儿子的答复是：同意" << endl;
}

void DoIt()
{
    cout << "----------原来的处理方式----------" << endl;
    //INormalWomen.h, NormalWomen.h, INormalHandler.h, NormalFather.h, NormalHusband.h, NormalSon.h
    INormalWomen *pwomen = new CNormalWomen(1, "我要出去逛街");
    INormalHandler *pfather = new CNormalFather();
    INormalHandler *phusband = new CNormalHusband();
    INormalHandler *pson = new CNormalSon();
    if (pwomen->GetType() == 1)
    {
        cout << "女儿向父亲请示：" << endl;
        pfather->HandleMessage(pwomen);
    }
    else if (pwomen->GetType() == 2)
    {
        cout << "妻子向丈夫请示：" << endl;
        phusband->HandleMessage(pwomen);
    }
    else if (pwomen->GetType() == 3)
    {
        cout << "母亲向儿子请示：" << endl;
        pson->HandleMessage(pwomen);
    }
    else
    {
        //什么也不做
    }
    delete pwomen;
    delete pfather;
    delete phusband;
    delete pson;
}

void DoNew()
{
    cout << "----------使用模式后的处理方式----------" << endl;
    //Handler.h, Handler.cpp, IWomen.h, Women.h, Women.cpp, Father.h, Father,cpp, Husband.h, Husband.cpp, Son.h, Son.cpp
    IWomen *pwomen1 = new CWomen(1, "我要出去逛街");
    IWomen *pwomen2 = new CWomen(2, "我要出去吃饭");
    IWomen *pwomen3 = new CWomen(3, "我也要出去吃饭");
    IWomen *pwomen4 = new CWomen(4, "我也要出去逛街");

    CHandler *pfather = new CFather();
    CHandler *phusband = new CHusband();
    CHandler *pson = new CSon();

    pfather->SetNext(phusband);
    phusband->SetNext(pson);

    pfather->HandleMessage(pwomen1);
    pfather->HandleMessage(pwomen2);
    pfather->HandleMessage(pwomen3);
    pfather->HandleMessage(pwomen4);

    delete pfather;
    delete phusband;
    delete pson;
    delete pwomen1;
    delete pwomen2;
    delete pwomen3;
    delete pwomen4;
}

int main(int argc, char * argv[])
{
    //反面
    DoIt();
    //要实现逻辑判断，即女性的请求先发送到父亲类，父亲类一看是自己要处理的，就回应进行处理。如果女儿已经出嫁了，那就把这个请求转发到女婿类来处理。依此类推，形成了一个责任链。
    DoNew();
    return 0;
}
