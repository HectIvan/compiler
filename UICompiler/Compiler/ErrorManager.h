#pragma once
#include "Lexer.h"
class ErrorManager
{
public:
	std::map<int, std::string> m_errorMap;
	ErrorManager();
	~ErrorManager();
};

