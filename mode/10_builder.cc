#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CCarModel
{
public:
    CCarModel(void);
    virtual ~CCarModel(void);
    void Run();
    void SetSequence(vector<string> *pSeq);
protected:
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Alarm() = 0;
    virtual void EngineBoom() = 0;
private:
    vector<string> * m_pSequence;
};

CCarModel::CCarModel(void)
{
}

CCarModel::~CCarModel(void)
{
}

void CCarModel::SetSequence(vector<string> *pSeq)
{
    m_pSequence = pSeq;
}
void CCarModel::Run()
{
    vector<string>::const_iterator it = m_pSequence->begin();
    for (; it < m_pSequence->end(); ++it)
    {
        string actionName = *it;
        if(actionName.compare("start") == 0)
        {
            Start();
        }
        else if(actionName.compare("stop") == 0)
        {
            Stop();
        }
        else if(actionName.compare("alarm") == 0)
        {
            Alarm();
        }
        else if(actionName.compare("engine boom") == 0)
        {
            EngineBoom();
        }
    }
}

class CBenzModel : public CCarModel
{
public:
    CBenzModel(void);
    ~CBenzModel(void);
protected:
    void Start();
    void Stop();
    void Alarm();
    void EngineBoom();
};

CBenzModel::CBenzModel(void)
{
}

CBenzModel::~CBenzModel(void)
{
}

void CBenzModel::Start()
{
    cout << "奔驰发动..." << endl;
}

void CBenzModel::Stop()
{
    cout << "奔驰停车..." << endl;
}

void CBenzModel::Alarm()
{
    cout << "奔驰鸣笛" << endl;
}
void CBenzModel::EngineBoom()
{
    cout << "奔驰引擎声音是这样...." << endl;
}

class CBMWModel : public CCarModel
{
public:
    CBMWModel(void);
    ~CBMWModel(void);
protected:
    void Start();
    void Stop();
    void Alarm();
    void EngineBoom();
};

CBMWModel::CBMWModel(void)
{
}

CBMWModel::~CBMWModel(void)
{
}

void CBMWModel::Start()
{
    cout << "宝马发动..." << endl;
}
void CBMWModel::Stop()
{
    cout << "宝马停车..." << endl;
}
void CBMWModel::Alarm()
{
    cout << "宝马鸣笛" << endl;
}
void CBMWModel::EngineBoom()
{
    cout << "宝马引擎声音是这样...." << endl;
}

class ICarBuilder
{
public:
    ICarBuilder(void)
    {
    }
    virtual ~ICarBuilder(void)
    {
    }
    virtual void SetSequence(vector<string> *pseq) = 0;
    virtual CCarModel * GetCarModel() = 0;
};

class CBenzBuilder : public ICarBuilder
{
public:
    CBenzBuilder(void);
    ~CBenzBuilder(void);
    void SetSequence(vector<string> *pSeq);
    CCarModel * GetCarModel();
private:
    CCarModel *m_pBenz;
};

CBenzBuilder::CBenzBuilder(void)
{
    m_pBenz = new CBenzModel();
}
CBenzBuilder::~CBenzBuilder(void)
{
    delete m_pBenz;
}
void CBenzBuilder::SetSequence(vector<string> *pSeq)
{
    m_pBenz->SetSequence(pSeq);
}
CCarModel * CBenzBuilder::GetCarModel()
{
    return m_pBenz;
}

class CBMWBuilder : public ICarBuilder
{
public:
    CBMWBuilder(void);
    ~CBMWBuilder(void);
    void SetSequence(vector<string> *pSeq);
    CCarModel * GetCarModel();
private:
    CCarModel *m_pBMW;
};

CBMWBuilder::CBMWBuilder(void)
{
    m_pBMW = new CBMWModel();
}
CBMWBuilder::~CBMWBuilder(void)
{
    delete m_pBMW;
}
void CBMWBuilder::SetSequence( vector<string> *pSeq )
{
    m_pBMW->SetSequence(pSeq);
}
CCarModel * CBMWBuilder::GetCarModel()
{
    return m_pBMW;
}

class CDirector
{
public:
    CDirector(void);
    ~CDirector(void);
    CBenzModel * GetABenzModel();
    CBenzModel * GetBBenzModel();
    CBMWModel * GetCBMWModel();
    CBMWModel * GetDBMWModel();
private:
    vector<string> * m_pSeqence;
    CBenzBuilder * m_pBenzBuilder;
    CBMWBuilder * m_pBMWBuilder;
};

CDirector::CDirector(void)
{
    m_pBenzBuilder = new CBenzBuilder();
    m_pBMWBuilder = new CBMWBuilder();
    m_pSeqence = new vector<string>();
}
CDirector::~CDirector(void)
{
    delete m_pBenzBuilder;
    delete m_pBMWBuilder;
    delete m_pSeqence;
}
CBenzModel * CDirector::GetABenzModel()
{
    m_pSeqence->clear();
    m_pSeqence->push_back("start");
    m_pSeqence->push_back("stop");
    m_pBenzBuilder->SetSequence(m_pSeqence);
    return dynamic_cast<CBenzModel*>(m_pBenzBuilder->GetCarModel());
}
CBenzModel * CDirector::GetBBenzModel()
{
    m_pSeqence->clear();
    m_pSeqence->push_back("engine boom");
    m_pSeqence->push_back("start");
    m_pSeqence->push_back("stop");
    m_pBenzBuilder->SetSequence(m_pSeqence);
    return dynamic_cast<CBenzModel*>(m_pBenzBuilder->GetCarModel());
}
CBMWModel * CDirector::GetCBMWModel()
{
    m_pSeqence->clear();
    m_pSeqence->push_back("alarm");
    m_pSeqence->push_back("start");
    m_pSeqence->push_back("stop");
    m_pBMWBuilder->SetSequence(m_pSeqence);
    return static_cast<CBMWModel*>(m_pBMWBuilder->GetCarModel());
}
CBMWModel * CDirector::GetDBMWModel()
{
    m_pSeqence->clear();
    m_pSeqence->push_back("start");
    m_pBenzBuilder->SetSequence(m_pSeqence);
    return dynamic_cast<CBMWModel*>(m_pBMWBuilder->GetCarModel());
}

// 测试
void DoBenzRun()		//没有使用模式时，需要把步骤一条一条的传入模型。
{
    cout << "----------生成奔驰模型----------" << endl;
    CBenzModel *pBenz = new CBenzModel();
    vector<string> seq;
    seq.push_back("engine boom");		//客户要求run的时候先发动引擎
    seq.push_back("start");				//启动起来
    seq.push_back("stop");				//开了一段就停下来

    pBenz->SetSequence(&seq);
    pBenz->Run();
    delete pBenz;
}


void DoBuilder()		//使用模式后，由benzBuilder和bmwBuilder来生成，并且使用同样的创建顺序。
{
    cout << "----------用同一个顺序，生成模型----------" << endl;
    vector<string> seq;
    seq.push_back("engine boom");
    seq.push_back("start");
    seq.push_back("stop");

    CBenzBuilder benzBuilder;
    benzBuilder.SetSequence(&seq);
    CBenzModel *pBenz = dynamic_cast<CBenzModel*>(benzBuilder.GetCarModel());
    pBenz->Run();

    CBMWBuilder bmwBuilder;
    bmwBuilder.SetSequence(&seq);
    CBMWModel *pBmw = dynamic_cast<CBMWModel*>(bmwBuilder.GetCarModel());
    pBenz->Run();
}
void DoDirector()		//使用指导者来封装创建的逻辑，把创建的顺序内聚在指导者类里面。
{
    cout << "----------批量生成模型----------" << endl;
    CDirector director;

    //1W辆A类型的奔驰车
    for(int i = 0; i < 2; i++)
        director.GetABenzModel()->Run();

    //100W辆B类型的奔驰车
    for(int i = 0; i < 2; i++)
        director.GetBBenzModel()->Run();

    //1000W辆C类型的宝马车
    for(int i = 0; i < 2; i++)
        director.GetCBMWModel()->Run();
}

int main(int argc, char* argv[])
{
    DoBenzRun();

    DoBuilder();

    DoDirector();

    return 0;
}
