#include <iostream>

using namespace std;

class CInvoker
{
public:
    CInvoker(void);
    ~CInvoker(void);
    void SetCommand(ICommand *pcommand);
    void Action();
private:
    ICommand *m_pCommand;
};

CInvoker::CInvoker(void)
{
}
CInvoker::~CInvoker(void)
{
}
void CInvoker::SetCommand( ICommand *pcommand )
{
    this->m_pCommand = pcommand;
}
void CInvoker::Action()
{
    this->m_pCommand->Execute();
}

class IGroup
{
public:
    IGroup(void)
    {
    }
    virtual ~IGroup(void)
    {
    }
    virtual void Find() = 0;
    virtual void Add() = 0;
    virtual void Delete() = 0;
    virtual void Change() = 0;
    virtual void Plan() = 0;
};

class CRequirementGroup : public IGroup
{
public:
    CRequirementGroup(void);
    ~CRequirementGroup(void);
    void Find();
    void Add();
    void Delete();
    void Change();
    void Plan();
};

CRequirementGroup::CRequirementGroup(void)
{
}

CRequirementGroup::~CRequirementGroup(void)
{
}

void CRequirementGroup::Find()
{
    cout << "找到需求组..." << endl;
}

void CRequirementGroup::Add()
{
    cout << "客户要求增加一项需求..." << endl;
}

void CRequirementGroup::Delete()
{
    cout << "要求删除一项需求..." << endl;
}

void CRequirementGroup::Change()
{
    cout << "客户要求修改一项需求..." << endl;
}

void CRequirementGroup::Plan()
{
    cout << "客户要求需求变更计划..." << endl;
}

class CPageGroup : public IGroup
{
public:
    CPageGroup(void);
    ~CPageGroup(void);
    void Find();
    void Add();
    void Delete();
    void Change();
    void Plan();
};

CPageGroup::CPageGroup(void)
{
}
CPageGroup::~CPageGroup(void)
{
}
void CPageGroup::Find()
{
    cout << "找到美工组..." << endl;
}
void CPageGroup::Add()
{
    cout << "客户要求增加一个页面..." << endl;
}
void CPageGroup::Delete()
{
    cout << "客户要求删除一个页面..." << endl;
}
void CPageGroup::Change()
{
    cout << "客户要求修改一个页面..." << endl;
}
void CPageGroup::Plan()
{
    cout << "客户要求页面变更计划..." << endl;
}

class CCodeGroup : public IGroup
{
public:
    CCodeGroup(void);
    ~CCodeGroup(void);
    void Find();
    void Add();
    void Delete();
    void Change();
    void Plan();
};

CCodeGroup::CCodeGroup(void)
{
}
CCodeGroup::~CCodeGroup(void)
{
}
void CCodeGroup::Find()
{
    cout << "找到代码组..." << endl;
}
void CCodeGroup::Add()
{
    cout << "客户要求增加一项功能..." << endl;
}
void CCodeGroup::Delete()
{
    cout << "客户要求删除一项功能..." << endl;
}
void CCodeGroup::Change()
{
    cout << "客户要求修改一项功能..." << endl;
}
void CCodeGroup::Plan()
{
    cout << "客户要求代码变更计划..." << endl;
}

class ICommand
{
public:
    ICommand(void)
    {
        m_prg = new CRequirementGroup();
        m_ppg = new CPageGroup();
        m_pcg = new CCodeGroup();
    }
    virtual ~ICommand(void)
    {
        delete m_prg;
        delete m_ppg;
        delete m_pcg;
    }
    virtual void Execute() = 0;
protected:
    CRequirementGroup *m_prg;
    CPageGroup *m_ppg;
    CCodeGroup *m_pcg;
};

class CAddRequirementCommand : public ICommand
{
public:
    CAddRequirementCommand(void);
    ~CAddRequirementCommand(void);
    void Execute();
};

CAddRequirementCommand::CAddRequirementCommand(void)
{
}
CAddRequirementCommand::~CAddRequirementCommand(void)
{
}
void CAddRequirementCommand::Execute()
{
    //执行增另一项需求的命令
    this->ICommand::m_prg->Find();

    //增加一份需求
    this->ICommand::m_prg->Add();

    //给出计划
    this->ICommand::m_prg->Plan();
}

class CDeletePageCommand : public ICommand
{
public:
    CDeletePageCommand(void);
    ~CDeletePageCommand(void);
    void Execute();
};

CDeletePageCommand::CDeletePageCommand(void)
{
}
CDeletePageCommand::~CDeletePageCommand(void)
{
}
void CDeletePageCommand::Execute()
{
    //执行增另一项需求的命令
    this->ICommand::m_ppg->Find();

    //增加一份需求
    this->ICommand::m_ppg->Delete();

    //给出计划
    this->ICommand::m_ppg->Plan();
}

void DoIt()
{
    cout << "----------客户想增加一个需求----------" << endl;
    IGroup *rg = new CRequirementGroup();
    rg->Find();
    rg->Add();
    rg->Plan();
    delete rg;
    cout << endl;

    cout << "----------客户又想修改一个页面----------" << endl;
    IGroup *pg = new CPageGroup();
    pg->Find();
    pg->Add();
    pg->Plan();
    delete pg;
    cout << endl;

    cout << "----------客户又想删除一个功能----------" << endl;
    IGroup *cg = new CCodeGroup();
    cg->Find();
    cg->Add();
    cg->Plan();
    delete cg;
    cout << endl;
}

void DoNew()
{
    cout << "----------客户觉得烦了，希望只找一个人，并告诉他要做什么----------" << endl;
    cout << "----------客户要求增加一项需求----------" << endl;
    CInvoker gary;
    ICommand *pcommand = new CAddRequirementCommand();
    gary.SetCommand(pcommand);
    gary.Action();
    delete pcommand;
    cout << endl;

    //客户想要改动只需要找CInvoker就可以了。
    cout << "----------客户要求删除一个页面----------" << endl;
    CInvoker ricky;
    ICommand *pcommand2 = new CDeletePageCommand();
    ricky.SetCommand(pcommand2);
    ricky.Action();
    delete pcommand2;
    cout << endl;
}

int main(int argc, char* argv[])
{
    //客户原来的运行流程
    DoIt();

    DoNew();

    return 0;
}
