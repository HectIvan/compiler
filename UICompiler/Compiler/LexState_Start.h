#pragma once
class LexState_Start :
    public LexState
{
public:
    LexState_Start();
    ~LexState_Start();

    virtual void Tokenize(const char* sourceCode, int currentChar);
};

