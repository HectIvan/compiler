#pragma once
#include "LexState_ID.h"
#include "LexState_Number.h"
#include "LexState_Operator.h"
#include "LexState_Start.h"
class LexState
{
public:
	// headers for map
	enum NM_HEADER
	{
		RESERVED = 0,
		ID,
		OPERATOR,
		NUMBER,
		FLOAT
	};

	// variables
	int* m_currentChar;
	std::string m_buffer;
	ErrorManager m_error;
	std::map<NM_HEADER, std::string> m_mapToken;

	LexState();
	~LexState();

	virtual void Tokenize(const char* sourceCode);
	bool ValidCharacter(char character);
	bool IsCharacter(const char* sourceCode, int currentChar);
	bool IsNumber(std::string number, int currentChar);
	bool IsReserved(std::string string);
	bool IsOperator(const char* sourceCode, int currentChar);
};

