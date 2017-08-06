//装饰模式
#include <iostream>

using namespace std;

class ISchoolReport
{
public:
    ISchoolReport(void)
    {
    }
    virtual ~ISchoolReport(void)
    {
    }
    virtual void Report() = 0;
    virtual void Sign(string name) = 0;
};

class CFouthGradeSchoolReport : public ISchoolReport
{
public:
    CFouthGradeSchoolReport(void);
    ~CFouthGradeSchoolReport(void);
    void Report();
    void Sign(string name);
};

CFouthGradeSchoolReport::CFouthGradeSchoolReport(void)
{
}
CFouthGradeSchoolReport::~CFouthGradeSchoolReport(void)
{
}
void CFouthGradeSchoolReport::Report()
{
    cout << "尊敬的XXX家长：" << endl;
    cout << "......" << endl;
    cout << "语文62  数学65  体育98  自然63" << endl;
    cout << "......" << endl;
    cout << "                家长签名：" << endl;
}
void CFouthGradeSchoolReport::Sign(string name)
{
    cout << "家长签名为：" << name.c_str() << endl;
}

class CReportDecorator : public ISchoolReport
{
public:
    CReportDecorator(ISchoolReport *psr);
    virtual ~CReportDecorator(void);
    void Report();
    void Sign(string name);
private:
    ISchoolReport *m_pSchoolReport;
};

CReportDecorator::CReportDecorator(ISchoolReport *psr)
{
    this->m_pSchoolReport = psr;
}
CReportDecorator::~CReportDecorator(void)
{
}
void CReportDecorator::Report()
{
    this->m_pSchoolReport->Report();
}
void CReportDecorator::Sign( string name )
{
    this->m_pSchoolReport->Sign(name);
}

class CHighScoreDecorator : public CReportDecorator
{
public:
    CHighScoreDecorator(ISchoolReport *psr);
    ~CHighScoreDecorator(void);
    void Report();
private:
    void ReportHighScore();
};

CHighScoreDecorator::CHighScoreDecorator( ISchoolReport *psr ) : CReportDecorator(psr)
{
}
CHighScoreDecorator::~CHighScoreDecorator(void)
{
}
void CHighScoreDecorator::Report()
{
    this->ReportHighScore();
    this->CReportDecorator::Report();
}
void CHighScoreDecorator::ReportHighScore()
{
    cout << "这次考试语文最高是75， 数学是78， 自然是80" << endl;
}

class CSortDecorator : public CReportDecorator
{
public:
    CSortDecorator(ISchoolReport *psr);
    ~CSortDecorator(void);
    void Report();
private:
    void ReportSort();
};

CSortDecorator::CSortDecorator( ISchoolReport *psr ) : CReportDecorator(psr)
{
}
CSortDecorator::~CSortDecorator(void)
{
}
void CSortDecorator::ReportSort()
{
    cout << "我是排名第38名..." << endl;
}
void CSortDecorator::Report()
{
    this->CReportDecorator::Report();
    this->ReportSort();
}

void DoIt()
{
    ISchoolReport *psr = new CSugarFouthGradeSchoolReport();
    psr->Report();//看成绩单
    psr->Sign("老三");//很开心，就签字了
    delete psr;
}
void DoNew()
{
    cout << "----------分部分进行装饰----------" << endl;
    ISchoolReport *psr = new CFouthGradeSchoolReport();//原装成绩单
    //
    ISchoolReport *pssr = new CSortDecorator(psr);//又加了成绩排名的说明
    ISchoolReport *phsr = new CHighScoreDecorator(pssr);//加了最高分说明的成绩单
    phsr->Report();//看成绩单
    phsr->Sign("老三");//很开心，就签字了
    
    //先装饰哪个不重要，顺序已经在装饰内部确定好，但一定要调用最后一个装饰器的接口。
    //ISchoolReport *phsr = new CHighScoreDecorator(psr);//加了最高分说明的成绩单
    //ISchoolReport *pssr = new CSortDecorator(phsr);//又加了成绩排名的说明
    //pssr->Report();//看成绩单
    //pssr->Sign("老三");//很开心，就签字了

    delete pssr;
    delete phsr;
    delete psr;
}
int main(int argc, char* argv[])
{
    //在装饰之前，可以用继承的办法，来进行简单的修饰
    DoIt();

    //但如果需要修饰的项目太多呢？或者装饰的项目不是固定的，继承显然会变得更复杂
    DoNew();

    return 0;
}
