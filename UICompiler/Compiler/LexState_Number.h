#pragma once
#include "Lexer.h"
class LexState_Number :
    public LexState
{
public:
    virtual void Tokenize(const char* sourceCode, int currentChar, std::string& token);
};