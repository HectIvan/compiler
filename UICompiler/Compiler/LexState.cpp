#include "pch.h"
#include "LexState.h"
#include "LexState_Start.h"

LexState::LexState()
{
	
}

LexState::~LexState()
{
}

void LexState::Tokenize(const char* sourceCode)
{
	LexState_Start lexStateStart;
	if (nullptr != sourceCode)
	{
		lexStateStart.Tokenize(sourceCode, *m_currentChar);
	}
	return;
}

bool LexState::ValidCharacter(char character)
{
	if ((character >= 'a' && character <= 'z') ||
		(character >= 'A' && character <= 'Z') ||
		('0' <= character && '9' >= character) ||
		'_' == character ||																									    // lower_line
		'&' == character || '|' == character || '!' == character ||															    // logic
		'+' == character || '-' == character || '/' == character || '*' == character || '%' == character || '^' == character || // arithmetic
		'<' == character || '=' == character ||	'>' == character ||																			    // relations
		'(' == character || ')' == character || '{' == character || '}' == character ||										    // groups
		',' == character || ';' == character || ':' == character ||	'.' == character ||										    // limits
		'[' == character || ']' == character)																				    // dimensions
	{
		return true;
	}
	return false;
}

bool LexState::IsCharacter(const char* sourceCode, int currentChar)
{
	if ((sourceCode[currentChar] >= 'a' && sourceCode[currentChar] <= 'z') ||
		(sourceCode[currentChar] >= 'A' && sourceCode[currentChar] <= 'Z'))
	{
		return true;
	}
	return false;
}

bool LexState::IsNumber(std::string number, int currentChar)
{
	if ('0' <= number[currentChar] && '9' >= number[currentChar])
	{
		return true;
	}
	return false;
}

bool LexState::IsReserved(std::string string)
{
	if ("var" == string ||																					     // var declaration
		"int" == string || "float" == string || "string" == string || "bool" == string || "void" == string ||    // value type
		"function" == string || "main" == string ||															     // functions
		"for" == string || "while" == string || "switch" == string || "case" == string || "default" == string || // loops
		"if" == string || "else" == string ||																	 // logic
		"cin" == string || "read" == string || "cout" == string || "print" == string ||
		"return" == string || "true" == string || "false" == string || "inc" == string || "dec" == string)
	{
		return true;
	}
	return false;
}

bool LexState::IsOperator(const char* sourceCode, int currentChar)
{
	if ('_' == sourceCode[currentChar] ||																									  // lower_line
		'&' == sourceCode[currentChar] || '|' == sourceCode[currentChar] || '!' == sourceCode[currentChar] ||																	  // logic
		'+' == sourceCode[currentChar] || '-' == sourceCode[currentChar] || '/' == sourceCode[currentChar] || '*' == sourceCode[currentChar] || '%' == sourceCode[currentChar] || '^' == sourceCode[currentChar] ||				  // arithmetic
		'<' == sourceCode[currentChar] || '=' == sourceCode[currentChar] ||																					  // relations
		'(' == sourceCode[currentChar] || ')' == sourceCode[currentChar] || '{' == sourceCode[currentChar] || '}' == sourceCode[currentChar] ||													  // groups
		',' == sourceCode[currentChar] || ';' == sourceCode[currentChar] || ';' == sourceCode[currentChar] ||																	  // limits
		'[' == sourceCode[currentChar] || ']' == sourceCode[currentChar] ||// dimensions
		'+' == sourceCode[currentChar] || '-' == sourceCode[currentChar] || '/' == sourceCode[currentChar] || '*' == sourceCode[currentChar] || '%' == sourceCode[currentChar] || '^' == sourceCode[currentChar] ||
		'<' == sourceCode[currentChar] || '=' == sourceCode[currentChar] || '>' == sourceCode[currentChar])
	{
		return true;
	}
	return false;
}
