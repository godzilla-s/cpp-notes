//桥梁模式，将抽象部分与它的实现部分分离，使它们都可以独立地变化。实现分离的办法就是增加一个类，
#include <iostream>

using namespace std;

class CNewCorp
{
public:
    CNewCorp(IProduct *pproduct);
    virtual ~CNewCorp(void);
    void MakeMoney();
private:
    IProduct *m_pProduct;
};

CNewCorp::CNewCorp( IProduct *pproduct )
{
    this->m_pProduct = pproduct;
}
CNewCorp::~CNewCorp(void)
{
}
void CNewCorp::MakeMoney()
{
    //每个公司都是一样，先生产
    this->m_pProduct->BeProducted();
    //然后销售
    this->m_pProduct->BeSelled();
}

class CNewHouseCorp :
    public CNewCorp
{
public:
    CNewHouseCorp(CHouse *pHouse);
    ~CNewHouseCorp(void);
    void MakeMoney();
};

CNewHouseCorp::CNewHouseCorp(CHouse *pHouse) : CNewCorp(pHouse)
{
}
CNewHouseCorp::~CNewHouseCorp(void)
{
}
void CNewHouseCorp::MakeMoney()
{
    this->CNewCorp::MakeMoney();
    cout << "房地产公司赚大钱了..." << endl;
}

class CShanZhaiCorp :
    public CNewCorp
{
public:
    CShanZhaiCorp(IProduct *pproduct);
    ~CShanZhaiCorp(void);
    void MakeMoney();
};

CShanZhaiCorp::CShanZhaiCorp(IProduct *pproduct) : CNewCorp(pproduct)
{
}
CShanZhaiCorp::~CShanZhaiCorp(void)
{
}
void CShanZhaiCorp::MakeMoney()
{
    this->CNewCorp::MakeMoney();
    cout << "我赚钱呀..." << endl;
}

class IProduct
{
public:
    IProduct(void)
    {
    }
    virtual ~IProduct(void)
    {
    }
    virtual void BeProducted() = 0;
    virtual void BeSelled() = 0;
};

class CHouse :
    public IProduct
{
public:
    CHouse(void);
    ~CHouse(void);
    void BeProducted();
    void BeSelled();
};

CHouse::CHouse(void)
{
}
CHouse::~CHouse(void)
{
}
void CHouse::BeProducted()
{
    cout << "生产出的房子是这个样子的..." << endl;
}
void CHouse::BeSelled()
{
    cout << "生产出的房子卖出去了..." << endl;
}

class CClothes :
    public IProduct
{
public:
    CClothes(void);
    ~CClothes(void);
    void BeProducted();
    void BeSelled();
};

CClothes::CClothes(void)
{
}
CClothes::~CClothes(void)
{
}
void CClothes::BeProducted()
{
    cout << "生产出的衣服是这个样子的..." << endl;
}
void CClothes::BeSelled()
{
    cout << "生产出的衣服卖出去了..." << endl;
}

class CIPod :
    public IProduct
{
public:
    CIPod(void);
    ~CIPod(void);
    void BeProducted();
    void BeSelled();
};

CIPod::CIPod(void)
{
}
CIPod::~CIPod(void)
{
}
void CIPod::BeProducted()
{
    cout << "生产出的ipod是这个样子的..." << endl;
}
void CIPod::BeSelled()
{
    cout << "生产出的ipod卖出去了..." << endl;
}

void DoNewRun1()
{
    cout << "----------房地产公司是这样运行的----------" << endl;
    CHouse house;
    CNewHouseCorp newHouseCorp(&house);
    newHouseCorp.MakeMoney();
    cout << endl;

    cout << "----------山寨公司是这样运行的----------" << endl;
    CClothes clothes;
    CShanZhaiCorp shanZhaiCorp(&clothes);
    shanZhaiCorp.MakeMoney();
    cout << endl;
}

void DoNewRun2()
{
    cout << "----------房地产公司是这样运行的----------" << endl;
    CHouse house;
    CNewHouseCorp newHouseCorp(&house);
    newHouseCorp.MakeMoney();
    cout << endl;

    cout << "----------山寨公司是这样运行的----------" << endl;
    CIPod ipod;
    CShanZhaiCorp shanZhaiCorp(&ipod);
    shanZhaiCorp.MakeMoney();
    cout << endl;
}

int main(int argc, char* argv[])
{
    //只有两家公司，一家是房地产公司，另一家公司是衣服赚钱就生产衣服
    DoNewRun1();

    //只有两家公司，一家是房地产公司，另一家公司是ipod赚钱就生产ipod
    DoNewRun2();

    return 0;
}


