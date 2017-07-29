#include <iostream>

using std::cout;
using std::endl;

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

class CBackDoor : public IStrategy
{
public:
    CBackDoor(void);
    ~CBackDoor(void);
    void Operate(void);
};

CBackDoor::CBackDoor(void)
{
}
CBackDoor::~CBackDoor(void)
{
}
void CBackDoor::Operate(void)
{
    cout << "找乔国老帮忙，让吴国太给孙权施加压力" << endl;
}

class CGivenGreenLight : public IStrategy
{
public:
    CGivenGreenLight(void);
    ~CGivenGreenLight(void);
    void Operate(void);
};

CGivenGreenLight::CGivenGreenLight(void)
{
}
CGivenGreenLight::~CGivenGreenLight(void)
{
}
void CGivenGreenLight::Operate(void)
{
    cout << "求吴国太开个绿灯，放行！" << endl;
}

class CBlockEnemy : public IStrategy
{
public:
    CBlockEnemy(void);
    ~CBlockEnemy(void);
    void Operate(void);
};

CBlockEnemy::CBlockEnemy(void)
{
}

CBlockEnemy::~CBlockEnemy(void)
{
}

void CBlockEnemy::Operate()
{
    cout << "孙夫人断后，挡住追兵" << endl;
}

int main()
{
    CContext *pContext;

    cout << "\14\n\n\n\n\17" << endl;
    cout << "----------刚刚到吴国的时候拆第一个----------" << endl;
    pContext = new CContext(new CBackDoor());
    pContext->Operate();
    delete pContext;

    cout << "\14\n\n\n\n\17" << endl;
    cout << "----------刘备乐不思蜀了，拆第二个了----------" << endl;
    pContext = new CContext(new CGivenGreenLight());
    pContext->Operate();
    delete pContext;

    cout << "\14\n\n\n\n\17" << endl;
    cout << "----------孙权的小兵追了，咋办？拆第三个----------" << endl;
    pContext = new CContext(new CBlockEnemy());
    pContext->Operate();
    delete pContext;

    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
    _CrtDumpMemoryLeaks();
    return 0;   
}
