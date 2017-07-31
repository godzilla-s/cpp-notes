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
