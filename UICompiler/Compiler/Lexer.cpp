#include "pch.h"
#include "Lexer.h"

Lexer::Lexer()
{
}

Lexer::~Lexer()
{
}

bool Lexer::Tokenize(const char* sourceCode)
{
	LexState lexState;
	if (nullptr != sourceCode)
	{
		lexState.Tokenize(sourceCode, 0);
	}
	return false;
}
