#include <iostream>

using namespace std;

class IHuman
{
public:
    IHuman(void) { }

    virtual ~IHuman(void) { }

    virtual void Laugh() = 0;
    virtual void Cry() = 0;
    virtual void Talk() = 0;
    virtual void Sex() = 0;
};

class CYellowHuman : public IHuman
{
public:
    CYellowHuman(void) { }

    ~CYellowHuman(void) { }

    void Laugh()
    {
        cout << "黄色人种会大笑，幸福呀！" << endl;
    }

    void Cry()
    {
        cout << "黄色人种会哭" << endl;
    }

    void Talk()
    {
        cout << "黄色人种会说话，一般说的都是双字节" << endl;
    }
    virtual void Sex() = 0;
};

class CYellowFemaleHuman : public CYellowHuman
{
public:
    CYellowFemaleHuman(void)
    {
    }
    ~CYellowFemaleHuman(void)
    {
    }
    void Sex()
    {
        cout << "该黄种人的性别为女..." << endl;
    }
};

class CYellowMaleHuman : public CYellowHuman
{
public:
    CYellowMaleHuman(void)
    {
    }
    ~CYellowMaleHuman(void)
    {
    }
    void Sex()
    {
        cout << "该黄种人的性别为男..." << endl;
    }
};

class CWhiteHuman : public IHuman
{
public:
    CWhiteHuman(void)
    {
    }
    ~CWhiteHuman(void)
    {
    }
    void Laugh()
    {
        cout << "白色人种会大笑，侵略的笑声" << endl;
    }
    void Cry()
    {
        cout << "白色人种会哭" << endl;
    }
    void Talk()
    {
        cout << "白色人种会说话，一般都是单字节" << endl;
    }
    virtual void Sex() = 0;
};

class CWhiteFemaleHuman : public CWhiteHuman
{
public:
    CWhiteFemaleHuman(void)
    {
    }
    ~CWhiteFemaleHuman(void)
    {
    }
    void Sex()
    {
        cout << "该白种人的性别为女..." << endl;
    }
};

class CWhiteMaleHuman : public CWhiteHuman
{
public:
    CWhiteMaleHuman(void)
    {
    }
    ~CWhiteMaleHuman(void)
    {
    }
    void Sex()
    {
        cout << "该白种人的性别为男..." << endl;
    }
};

class CBlackHuman : public IHuman
{
public:
    CBlackHuman(void)
    {
    }
    ~CBlackHuman(void)
    {
    }
    void Laugh()
    {
        cout << "黑人会笑" << endl;
    }
    void Cry()
    {
        cout << "黑人会哭" << endl;
    }
    void Talk()
    {
        cout << "黑人可以说话，一般人听不懂" << endl;
    }

    virtual void Sex() = 0;
};

class CBlackFemaleHuman : public CBlackHuman
{
public:
    CBlackFemaleHuman(void)
    {
    }
    ~CBlackFemaleHuman(void)
    {
    }
    void Sex()
    {
        cout << "该黑种人的性别为女..." << endl;
    }
};

class CBlackMaleHuman :  public CBlackHuman
{
public:
    CBlackMaleHuman(void)
    {
    }
    ~CBlackMaleHuman(void)
    {
    }
    void Sex()
    {
        cout << "该黑种人的性别为男..." << endl;
    }
};

class IHumanFactory
{
public:
    IHumanFactory(void)
    {
    }
    virtual ~IHumanFactory(void)
    {
    }
    virtual IHuman * CreateYellowHuman() = 0;
    virtual IHuman * CreateWhiteHuman() = 0;
    virtual IHuman * CreateBlackHuman() = 0;
};

// 下面使用人种的模板
template<class T>
class CStandardHumanFactory : public IHumanFactory
{
public:
    CStandardHumanFactory(void)
    {
    }

    ~CStandardHumanFactory(void)
    {
    }

    IHuman *CreateHuman()
    {
        return new T;
    }
};

template<class T>
class CMaleHumanFactory : public CStandardHumanFactory<T>
{
public:
    CMaleHumanFactory(void);
    ~CMaleHumanFactory(void);
    IHuman * CreateYellowHuman();
    IHuman * CreateWhiteHuman();
    IHuman * CreateBlackHuman();
};

template<class T>
CMaleHumanFactory<T>::CMaleHumanFactory(void)
{
}

template<class T>
CMaleHumanFactory<T>::~CMaleHumanFactory(void)
{
}

template<class T>
IHuman * CMaleHumanFactory<T>::CreateYellowHuman()
{
    return CreateHuman();
}

template<class T>
IHuman * CMaleHumanFactory<T>::CreateWhiteHuman()
{
    return CreateHuman();
}

template<class T>
IHuman * CMaleHumanFactory<T>::CreateBlackHuman()
{
    return CreateHuman();
}

template<class T>
class CFemaleHumanFactory : public CStandardHumanFactory<T>
{
public:
    CFemaleHumanFactory(void)
    {
    }
    ~CFemaleHumanFactory(void)
    {
    }
    IHuman * CreateYellowHuman()
    {
        return CreateHuman();
    }
    IHuman * CreateWhiteHuman()
    {
        return CreateHuman();
    }
    IHuman * CreateBlackHuman()
    {
        return CreateHuman();
    }
};

void DoIt()
{
    IHumanFactory *pFemaleHumanFactory = new CFemaleHumanFactory<CYellowFemaleHuman>();
    IHuman *pYellowFemaleHuman = pFemaleHumanFactory->CreateYellowHuman();
    pYellowFemaleHuman->Cry();
    pYellowFemaleHuman->Laugh();
    pYellowFemaleHuman->Talk();
    pYellowFemaleHuman->Sex();
    delete pYellowFemaleHuman;
    delete pFemaleHumanFactory;

    IHumanFactory *pMaleHumanFactory = new CMaleHumanFactory<CYellowMaleHuman>();
    IHuman *pYellowMaleHuman = pMaleHumanFactory->CreateYellowHuman();
    pYellowMaleHuman->Cry();
    pYellowMaleHuman->Laugh();
    pYellowMaleHuman->Talk();
    pYellowMaleHuman->Sex();
    delete pYellowMaleHuman;
    delete pMaleHumanFactory;
}
int main(int argc, char* argv[])
{
    DoIt();
    return 0;
}
