#include <iostream>

//
class IStrategy
{
public:
    IStrategy(void);
    virtual ~IStrategy(void);
    virtual void Operate(void) = 0;
};

//
class CContext
{
public:
    CContext(IStrategy *pStrategy);
    ~CContext(void);
    void Operate(void);
private:
    IStrategy *m_pStrategy;
};

CContext::CContext(IStrategy *pStrategy)
{
    this->m_pStrategy = pStrategy;
}
CContext::~CContext(void)
{
    delete this->m_pStrategy;
}
void CContext::Operate(void)
{
    this->m_pStrategy->Operate();
}

