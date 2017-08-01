//门面模式
#include <iostream>

class ILetterProcess
{
public:
    ILetterProcess(void);
    virtual ~ILetterProcess(void);
    virtual void WriteContext(string context) = 0;
    virtual void FillEnvelope(string address) = 0;
    virtual void LetterIntoEnvelope() = 0;
    virtual void SendLetter() = 0;
};

ILetterProcess::ILetterProcess(void)
{
}

ILetterProcess::~ILetterProcess(void)
{
}

class CLetterProcessImpl : public ILetterProcess
{
public:
    CLetterProcessImpl(void);
    ~CLetterProcessImpl(void);

    void WriteContext(string context);
    void FillEnvelope(string address);
    void LetterIntoEnvelope();
    void SendLetter();
};

CLetterProcessImpl::CLetterProcessImpl(void)
{
}

CLetterProcessImpl::~CLetterProcessImpl(void)
{
}

void CLetterProcessImpl::WriteContext(string context)
{
    cout << "填写信的内容... ..." << endl;
}

void CLetterProcessImpl::FillEnvelope(string address)
{
    cout << "填写收件人地址及姓名... ..." << endl;
}

void CLetterProcessImpl::LetterIntoEnvelope()
{
    cout << "把信放到信封中..." << endl;
}

void CLetterProcessImpl::SendLetter()
{
    cout << "邮递信件..." << endl;
}

class CModenPostOffice
{
public:
    CModenPostOffice(void);
    ~CModenPostOffice(void);
    void SendLetter(string context, string address);
private:
    ILetterProcess *m_pLetterProcess;
    CLetterPolice *m_pLetterPolice;
};

CModenPostOffice::CModenPostOffice(void)
{
    this->m_pLetterProcess = new CLetterProcessImpl();
    this->m_pLetterPolice = new CLetterPolice();
}

CModenPostOffice::~CModenPostOffice(void)
{
    delete m_pLetterProcess;
    delete m_pLetterPolice;
}

void CModenPostOffice::SendLetter( string context, string address )
{
    //帮忙写信
    m_pLetterProcess->WriteContext(context);
    //写好信封
    m_pLetterProcess->FillEnvelope(address);
    //警察要检查信件了
    m_pLetterPolice->CheckLetter(m_pLetterProcess);
    //把信放到信封中
    m_pLetterProcess->LetterIntoEnvelope();
    //邮递信件
    m_pLetterProcess->SendLetter();
}

class CLetterPolice
{
public:
    CLetterPolice(void);
    ~CLetterPolice(void);
    void CheckLetter(ILetterProcess *pLetterProcess);
};

CLetterPolice::CLetterPolice(void)
{
}

CLetterPolice::~CLetterPolice(void)
{
}

void CLetterPolice::CheckLetter( ILetterProcess *pLetterProcess )
{
    cout << "Check Letter\n";
    return;
}

// 测试
void DoItByPostOffice()
{
    CModenPostOffice modenPostOffice;
    string context = "Hello, It's me, do you know who I am? I'm your old lover. I'd like to ... ...";
    string address = "Happy Road No. 666, Beijing City, China";
    modenPostOffice.SendLetter(context, address);
}
void DoItYourself()
{
    ILetterProcess *pLetterProcess = new CLetterProcessImpl();
    pLetterProcess->WriteContext("Hello, It's me, do you know who I am? I'm your old lover. I'd like to ... ...");
    pLetterProcess->FillEnvelope("Happy Road No. 666, Beijing City, China");
    pLetterProcess->LetterIntoEnvelope();
    pLetterProcess->SendLetter();
    delete pLetterProcess;
}
int main(int argc, char* argv[])
{
    //现在的调用方式。对于客户来说确实简单多了。
    //如需要增加逻辑，例如让警察来检查邮件。可以在邮局里完成这项工作。
    DoItByPostOffice();
    
    //原来的调用方式。
    DoItYourself();

    return 0;
}
