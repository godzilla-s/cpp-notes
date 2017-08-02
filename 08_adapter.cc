//适配器
#include <iostream>

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
    COuterUserBaseInfo * GetUserBaseInfo();
    COuterUserHomeInfo * GetUserHomeInfo();
    COuterUserOfficeInfo * GetUserOfficeInfo();
};

class IOuterUser
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
