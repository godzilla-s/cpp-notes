//代理模式
#include <iostream>

using namespace std;

//基类:抽象类
class IKindWomen
{
public:
    IKindWomen(void);
    virtual ~IKindWomen(void);
    virtual void MakeEyesWithMan() = 0;
    virtual void HappyWithMan() = 0;
};

class CWangPo : public IKindWomen
{
public:
    CWangPo(IKindWomen *pKindWomen);
    ~CWangPo(void);
    void HappyWithMan(void);
    void MakeEyesWithMan(void);
private:
    IKindWomen *m_pKindWomen;
};

CWangPo::CWangPo(IKindWomen *pKindWomen)
{
    this->m_pKindWomen = pKindWomen;
}
CWangPo::~CWangPo(void)
{
    delete this->m_pKindWomen;
}
void CWangPo::HappyWithMan()
{
    this->m_pKindWomen->HappyWithMan();
}
void CWangPo::MakeEyesWithMan(void)
{
    this->m_pKindWomen->MakeEyesWithMan();
}

class CPanJinLian : public IKindWomen
{
public:
    CPanJinLian(void);
    ~CPanJinLian(void);
    void HappyWithMan(void);
    void MakeEyesWithMan(void);
};

CPanJinLian::CPanJinLian(void)
{

}

CPanJinLian::~CPanJinLian(void)
{

}

void CPanJinLian::HappyWithMan(void)
{
    cout << " 潘金莲和男人做那个... ... " << endl;
}

void CPanJinLian::MakeEyesWithMan(void)
{
    cout << " 潘金莲抛媚眼 " << endl;
}

class CJiaShi : public IKindWomen
{
public:
    CJiaShi(void);
    ~CJiaShi(void);
    void HappyWithMan(void);
    void MakeEyesWithMan(void);
};

CJiaShi::CJiaShi(void)
{

}

CJiaShi::~CJiaShi(void)
{

}

void CJiaShi::HappyWithMan(void)
{
    cout << " 贾氏和男人做那个... ... " << endl;
}
void CJiaShi::MakeEyesWithMan(void)
{
    cout << " 贾氏抛媚眼 " << endl;
}

//实现
void DoPanJinLian()
{
    CWangPo *pWangPo;
    // 西门庆想找潘金莲，让王婆来安排。
    pWangPo = new CWangPo(new CPanJinLian());
    pWangPo->MakeEyesWithMan();
    pWangPo->HappyWithMan();
    delete pWangPo;
}
void DoJiaShi()
{
    CWangPo *pWangPo;
    // 西门庆想找贾氏，让王婆来安排。
    pWangPo = new CWangPo(new CJiaShi());
    pWangPo->MakeEyesWithMan();
    pWangPo->HappyWithMan();
    delete pWangPo;
}

int main()
{
    // 西门庆想找潘金莲
    DoPanJinLian();

    // 西门庆想找贾氏
    DoJiaShi();

    return 0;
 }
