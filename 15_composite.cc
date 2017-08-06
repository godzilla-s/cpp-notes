//组合模式
#include <iostream>
#include <string>

using namespace std;

class CCorpNode
{
public:
    CCorpNode();
    CCorpNode(string _name, string _pos, int _salary);
    virtual ~CCorpNode(void);
    virtual string GetInfo();
    void SetParent(CCorpNode *_pParent);
    CCorpNode * GetParent();
    virtual bool IsLeaf() = 0;
private:
    string m_name;
    string m_position;
    int m_salary;
protected:
    bool m_isLeaf;
    CCorpNode *m_pParent;
};

CCorpNode::CCorpNode(void)
{
    m_name = "";
    m_position = "";
    m_salary = 0;
}
CCorpNode::CCorpNode(string _name, string _pos, int _salary) : m_name(_name), m_position(_pos), m_salary(_salary)
{
}
CCorpNode::~CCorpNode(void)
{
}
string CCorpNode::GetInfo()
{
    string info = "";
    info.append("姓名：");
    info.append(this->m_name);
    info.append("\t职位：");
    info.append(this->m_position);
    info.append("\t薪水：");
    info.append(CConvert::ToString(this->m_salary));
    return info;
}
void CCorpNode::SetParent( CCorpNode *_parent )
{
    this->m_pParent = _parent;
}
CCorpNode * CCorpNode::GetParent()
{
    return this->m_pParent;
}

class CBranchNode : public CCorpNode
{
public:
    CBranchNode(void);
    CBranchNode(string name, string pos, int salary);
    ~CBranchNode(void);
    void Add(CCorpNode *pcorpNode);
    vector<CCorpNode*> GetSubordinateInfo();
    bool IsLeaf();
private:
    vector<CCorpNode*> m_subordinateList;
};

CBranchNode::CBranchNode(void)
{
    m_isLeaf = false;
}
CBranchNode::CBranchNode( string name, string pos, int salary ) : CCorpNode(name, pos, salary)
{
    m_isLeaf = false;
}
CBranchNode::~CBranchNode(void)
{
}
void CBranchNode::Add( CCorpNode *pcorpNode )
{
    pcorpNode->SetParent(this);
    m_subordinateList.push_back(pcorpNode);
}
vector<CCorpNode*> CBranchNode::GetSubordinateInfo()
{
    return this->m_subordinateList;
}
bool CBranchNode::IsLeaf()
{
    return m_isLeaf;
}

class CLeafNode : public CCorpNode
{
public:
    CLeafNode(void);
    CLeafNode(string name, string pos, int salary);
    ~CLeafNode(void);
    bool IsLeaf();
};

CLeafNode::CLeafNode(void)
{
    m_isLeaf = true;
}
CLeafNode::CLeafNode( string name, string pos, int salary ) : CCorpNode(name, pos, salary)
{
    m_isLeaf = true;
}
CLeafNode::~CLeafNode(void)
{
}
bool CLeafNode::IsLeaf()
{
    return m_isLeaf;
}

