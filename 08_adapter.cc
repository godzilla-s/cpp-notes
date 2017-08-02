//适配器
#include <iostream>
#include <string>

unsing namespace std;

class IUserInfo
{
public:
    IUserInfo(void)
    {
    }
    virtual ~IUserInfo(void)
    {
    }
    virtual string GetUserName() = 0;
    virtual string GetHomeAddress() = 0;
    virtual string GetMobileNumber() = 0;
    virtual string GetOfficeTelNumber() = 0;
    virtual string GetJobPosition() = 0;
    virtual string GetHomeTelNumber() = 0;
};

class CUserInfo : public IUserInfo
{
public:
    CUserInfo(void);
    ~CUserInfo(void);
    string GetUserName();
    string GetHomeAddress();
    string GetMobileNumber();
    string GetOfficeTelNumber();
    string GetJobPosition();
    string GetHomeTelNumber();
};

CUserInfo::CUserInfo(void)
{
}

CUserInfo::~CUserInfo(void)
{
}

string CUserInfo::GetUserName()
{
    cout << "姓名叫做..." << endl;
    return "0";
}
string CUserInfo::GetHomeAddress()
{
    cout << "这里是员工的家庭地址..." << endl;
    return "0";
}
string CUserInfo::GetMobileNumber()
{
    cout << "这个人的手机号码是0000..." << endl;
    return "0";
}
string CUserInfo::GetOfficeTelNumber()
{
    cout << "办公室电话是..." << endl;
    return "0";
}
string CUserInfo::GetJobPosition()
{
    cout << "这个人的职位是BOSS..." << endl;
    return "0";
}
string CUserInfo::GetHomeTelNumber()
{
    cout << "员工的家庭电话是..." << endl;
    return "0";
}

class IOuterUser
{
public:
    IOuterUser(void)
    {
    }
    ~IOuterUser(void)
    {
    }
    virtual COuterUserBaseInfo * GetUserBaseInfo() = 0;
    virtual COuterUserHomeInfo * GetUserHomeInfo() = 0;
    virtual COuterUserOfficeInfo * GetUserOfficeInfo() = 0;
};

class COuterUser
{
public:
    IOuterUser(void)
    {
    }
    ~IOuterUser(void)
    {
    }
    COuterUserBaseInfo * GetUserBaseInfo();
    COuterUserHomeInfo * GetUserHomeInfo();
    COuterUserOfficeInfo * GetUserOfficeInfo();
};

COuterUser::COuterUser(void)
{
}

COuterUser::~COuterUser(void)
{
}

COuterUserBaseInfo * COuterUser::GetUserBaseInfo()
{
    return new COuterUserBaseInfo();
}

COuterUserHomeInfo * COuterUser::GetUserHomeInfo()
{
    return new COuterUserHomeInfo();
}

COuterUserOfficeInfo * COuterUser::GetUserOfficeInfo()
{
    return new COuterUserOfficeInfo();
}

class COuterUserBaseInfo
{
public:
    COuterUserBaseInfo(void)
    {
    }
    ~COuterUserBaseInfo(void)
    {
    }
    string GetUserName()
    {
        cout << "姓名叫做..." << endl;
        return "0";
    }
    string GetMobileNumber()
    {
        cout << "这个人的手机号码是0001..." << endl;
        return "0";
    }
};

class COuterUserHomeInfo
{
public:
    COuterUserHomeInfo(void)
    {
    }
    ~COuterUserHomeInfo(void)
    {
    }
    string GetHomeAddress()
    {
        cout << "这里是员工的家庭地址..." << endl;
        return "0";
    }
    string GetHomeTelNumber()
    {
        cout << "员工的家庭电话是..." << endl;
        return "0";
    }
};

class COuterUserOfficeInfo
{
public:
    COuterUserOfficeInfo(void)
    {
    }
    ~COuterUserOfficeInfo(void)
    {
    }
    string GetOfficeTelNumber()
    {
        cout << "办公室电话是..." << endl;
        return "0";
    }
    string GetJobPosition()
    {
        cout << "这个人的职位是BOSS..." << endl;
        return "0";
    }
};

class COuterUserInfo : public IUserInfo
{
public:
    COuterUserInfo(void);
    ~COuterUserInfo(void);
    string GetUserName();
    string GetHomeAddress();
    string GetMobileNumber();
    string GetOfficeTelNumber();
    string GetJobPosition();
    string GetHomeTelNumber();
private:
    COuterUser *m_pOuterUser;
};

COuterUserInfo::COuterUserInfo(void)
{
    m_pOuterUser = new COuterUser();
}
COuterUserInfo::~COuterUserInfo(void)
{
    delete m_pOuterUser;
}
string COuterUserInfo::GetUserName()
{
    COuterUserBaseInfo *pBaseInfo = m_pOuterUser->GetUserBaseInfo();
    pBaseInfo->GetUserName();
    delete pBaseInfo;
    pBaseInfo = NULL;
    return "0";
}
string COuterUserInfo::GetHomeAddress()
{
    COuterUserHomeInfo *pHomeInfo = m_pOuterUser->GetUserHomeInfo();
    pHomeInfo->GetHomeAddress();
    delete pHomeInfo;
    pHomeInfo = NULL;
    return "0";
}
string COuterUserInfo::GetMobileNumber()
{
    COuterUserBaseInfo *pBaseInfo = m_pOuterUser->GetUserBaseInfo();
    pBaseInfo->GetMobileNumber();
    delete pBaseInfo;
    pBaseInfo = NULL;
    return "0";
}
string COuterUserInfo::GetOfficeTelNumber()
{
    COuterUserOfficeInfo *pOfficeInfo = m_pOuterUser->GetUserOfficeInfo();
    pOfficeInfo->GetOfficeTelNumber();
    delete pOfficeInfo;
    pOfficeInfo = NULL;
    return "0";
}
string COuterUserInfo::GetJobPosition()
{
    COuterUserOfficeInfo *pOfficeInfo = m_pOuterUser->GetUserOfficeInfo();
    pOfficeInfo->GetJobPosition();
    delete pOfficeInfo;
    pOfficeInfo = NULL;
    return "0";
}
string COuterUserInfo::GetHomeTelNumber()
{
    COuterUserHomeInfo *pHomeInfo = m_pOuterUser->GetUserHomeInfo();
    pHomeInfo->GetHomeTelNumber();
    delete pHomeInfo;
    pHomeInfo = NULL;
    return "0";
}

void DoIt()
{
    IUserInfo *pYourGirl = new CUserInfo();
    for(int i = 0; i < 101; i += 20)
    {
        pYourGirl->GetMobileNumber();
    }
    delete pYourGirl;
}
void NowDoIt()
{
    IUserInfo *pYourGirl = new COuterUserInfo();

    for(int i = 0; i < 101; i += 20)
    {
        pYourGirl->GetMobileNumber();
    }

    delete pYourGirl;
}
int main(int argc, char* argv[])
{
    DoIt();
    
    NowDoIt();
    
    return 0;
}
