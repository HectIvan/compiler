#pragma once
#include "Lexer.h"
class LexState_Operator :
    public LexState
{
public:
    virtual void Tokenize(const char* sourceCode, int currentChar);
};

