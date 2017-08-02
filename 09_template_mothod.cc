#include <iostream>

using namespace std;

class CHummerModel
{
public:
    CHummerModel(void);
    virtual ~CHummerModel(void);
    void Run();
protected:
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Alarm() = 0;
    virtual void EngineBoom() = 0;
    virtual bool IsAlarm();
};

CHummerModel::CHummerModel(void) { }

CHummerModel::~CHummerModel(void) { }

void CHummerModel::Run()
{
    Start();
    EngineBoom();
    if(IsAlarm())
        Alarm();

    Stop();
}

bool CHummerModel::IsAlarm()
{
    return true;
}

class CHummerH1Model : public CHummerModel
{
public:
    CHummerH1Model(void);
    ~CHummerH1Model(void);
    void SetAlarm(bool tag);
    void Start();
    void Stop();
    void Alarm();
    void EngineBoom();
    bool IsAlarm();
private:
    bool m_isAlarm;
};

CHummerH1Model::CHummerH1Model(void)
{
    m_isAlarm = true;
}
CHummerH1Model::~CHummerH1Model(void)
{
}
void CHummerH1Model::Start()
{
    cout << "悍马H1发动..." << endl;
}

void CHummerH1Model::Stop()
{
    cout << "悍马H1停车..." << endl;
}
void CHummerH1Model::Alarm()
{
    cout << "悍马H1鸣笛" << endl;
}
void CHummerH1Model::EngineBoom()
{
    cout << "悍马H1引擎声音是这样...." << endl;
}
bool CHummerH1Model::IsAlarm()
{
    return this->m_isAlarm;
}
void CHummerH1Model::SetAlarm( bool tag )
{
    this->m_isAlarm = tag;
}

class CHummerH2Model : public CHummerModel
{
public:
    CHummerH2Model(void);
    ~CHummerH2Model(void);
    void Start();
    void Stop();
    void Alarm();
    void EngineBoom();
    bool IsAlarm();
};

CHummerH2Model::CHummerH2Model(void) { }

CHummerH2Model::~CHummerH2Model(void) { }

void CHummerH2Model::Start()
{
    cout << "悍马H2发动..." << endl;
}

void CHummerH2Model::Stop()
{
    cout << "悍马H2停车..." << endl;
}

void CHummerH2Model::Alarm()
{
    cout << "悍马H2鸣笛" << endl;
}

void CHummerH2Model::EngineBoom()
{
    cout << "悍马H2引擎声音是这样...." << endl;
}

bool CHummerH2Model::IsAlarm()
{
    return false;
}

int main(int args, char *argv[])
{
    CHummerModel *ph1 = new CHummerH1Model();
    ph1->Run();
    delete ph1;

    CHummerModel *ph2 = new CHummerH2Model();
    ph2->Run();
    delete ph2;

    CHummerH1Model *ph11 = new CHummerH1Model();
    ph11->SetAlarm(false);
    ph11->Run();
    delete ph11;

    return 0;
}
