#pragma once
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include "LexState.h"
class Lexer
{
public:
	Lexer();
	~Lexer();
	bool Tokenize(const char* sourceCode);
};

