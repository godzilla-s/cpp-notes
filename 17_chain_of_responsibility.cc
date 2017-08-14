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

