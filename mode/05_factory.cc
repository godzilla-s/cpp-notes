//工厂模式
#include <iostream>

using namespace std;

class IHuman
{
public:
    IHuman(void)
    {
    }
    virtual ~IHuman(void)
    {
    }
    virtual void Laugh() = 0;
    virtual void Cry() = 0;
    virtual void Talk() = 0;
};

class CYellowHuman : public IHuman
{
public:
    CYellowHuman(void);
    ~CYellowHuman(void);
    void Laugh();
    void Cry();
    void Talk();
};

CYellowHuman::CYellowHuman(void)
{
    
}

CYellowHuman::~CYellowHuman(void)
{
    
}

void CYellowHuman::Cry()
{
    cout << "黄色人种会哭" << endl;
}

void CYellowHuman::Laugh()
{
    cout << "黄色人种会大笑，幸福呀！" << endl;
}

void CYellowHuman::Talk()
{
    cout << "黄色人种会说话，一般说的都是双字节" << endl;
}

class CWhiteHuman : public IHuman
{
public:
    CWhiteHuman(void);
    ~CWhiteHuman(void);
    void Laugh();
    void Cry();
    void Talk();
};

CWhiteHuman::CWhiteHuman(void)
{
}

CWhiteHuman::~CWhiteHuman(void)
{
}

void CWhiteHuman::Cry()
{
    cout << "白色人种会哭" << endl;
}

void CWhiteHuman::Laugh()
{
    cout << "白色人种会大笑，侵略的笑声" << endl;
}

void CWhiteHuman::Talk()
{
    cout << "白色人种会说话，一般都是单字节" << endl;
}

class CBlackHuman : public IHuman
{
public:
    CBlackHuman(void);
    ~CBlackHuman(void);
    void Laugh();
    void Cry();
    void Talk();
};

CBlackHuman::CBlackHuman(void)
{
}

CBlackHuman::~CBlackHuman(void)
{
}

void CBlackHuman::Cry()
{
    cout << "黑人会哭" << endl;
}
void CBlackHuman::Laugh()
{
    cout << "黑人会笑" << endl;
}

void CBlackHuman::Talk()
{
    cout << "黑人可以说话，一般人听不懂" << endl;
}

//工厂
class IHumanFactory
{
public:
    IHumanFactory(void)
    {
    }
    virtual ~IHumanFactory(void)
    {
    }
    virtual IHuman * CreateHuman() = 0;
};

class CYellowHumanFactory : public IHumanFactory
{
public:
    CYellowHumanFactory(void);
    ~CYellowHumanFactory(void);
    virtual IHuman * CreateHuman(void);
};

CYellowHumanFactory::CYellowHumanFactory(void)
{
}

CYellowHumanFactory::~CYellowHumanFactory(void)
{
}

IHuman * CYellowHumanFactory::CreateHuman( void )
{
    return new CYellowHuman();
}

class CWhiteHumanFactory : public IHumanFactory
{
public:
    CWhiteHumanFactory(void);
    ~CWhiteHumanFactory(void);
    virtual IHuman * CreateHuman(void);
};

CWhiteHumanFactory::CWhiteHumanFactory(void)
{
}

CWhiteHumanFactory::~CWhiteHumanFactory(void)
{
}

IHuman * CWhiteHumanFactory::CreateHuman( void )
{
    return new CWhiteHuman();
}

class CBlackHumanFactory : public IHumanFactory
{
public:
    CBlackHumanFactory(void);
    ~CBlackHumanFactory(void);
    virtual IHuman * CreateHuman();
};

CBlackHumanFactory::CBlackHumanFactory(void)
{
}

CBlackHumanFactory::~CBlackHumanFactory(void)
{
}

IHuman * CBlackHumanFactory::CreateHuman()
{
    return new CBlackHuman();
}

// 实现
void DoFactoryMethod1()
{
    cout << "----------第一批人是这样的：黄种人工厂来生产黄种人" << endl;
    IHumanFactory *pHumanFactory = new CYellowHumanFactory();
    IHuman *pHuman = pHumanFactory->CreateHuman();
    pHuman->Cry();
    pHuman->Laugh();
    pHuman->Talk();
    delete pHuman;
    delete pHumanFactory;
}
void DoFactoryMethod2()
{
    cout << "----------第二批人是这样的：白种人工厂来生产白种人" << endl;
    IHumanFactory *pHumanFactory = new CWhiteHumanFactory();
    IHuman *pHuman = pHumanFactory->CreateHuman();
    pHuman->Cry();
    pHuman->Laugh();
    pHuman->Talk();
    delete pHuman;
    delete pHumanFactory;
}
void DoFactoryMethod3()
{
    cout << "----------第一批人是这样的：黑种人工厂来生产黑种人" << endl;
    IHumanFactory *pHumanFactory = new CBlackHumanFactory();
    IHuman *pHuman = pHumanFactory->CreateHuman();
    pHuman->Cry();
    pHuman->Laugh();
    pHuman->Talk();
    delete pHuman;
    delete pHumanFactory;
}
int main(int argc, char* argv[])
{
    //工厂方法
    cout << "----------工厂方法：" << endl;
    DoFactoryMethod1();
    DoFactoryMethod2();
    DoFactoryMethod3();
    
    return 0;
}
