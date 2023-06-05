#include "pch.h"
#include "LexState_Start.h"
#include "Lexer.h"

LexState_Start::LexState_Start()
{
}

LexState_Start::~LexState_Start()
{
}

void LexState_Start::Tokenize(const char* sourceCode, int currentChar)
{
	*m_currentChar = currentChar;
	std::string token;
	while (*m_currentChar < strlen(sourceCode))
	{
		if (ValidCharacter(sourceCode[*m_currentChar]))
		{
			if (IsCharacter(sourceCode, *m_currentChar))
			{
				LexState_ID id;
				if (sourceCode[*m_currentChar] != ' ' && (IsCharacter(sourceCode, *m_currentChar) || IsNumber(sourceCode, *m_currentChar) || '_' == sourceCode[*m_currentChar]))
				{
					id.Tokenize(sourceCode, *m_currentChar, token);
				}
				else
				{
					if (IsReserved(token))
					{
						// is a reserved word
						m_mapToken.insert(std::make_pair(NM_HEADER::RESERVED, token));
						token = "";
					}
					else
					{
						// is an ID
						m_mapToken.insert(std::make_pair(NM_HEADER::ID, token));
						token = "";
					}
				}
			}
			else if (IsNumber(sourceCode, *m_currentChar))
			{
				LexState_Number number;
				if (sourceCode[*m_currentChar] != ' ' && IsNumber(sourceCode, *m_currentChar))
				{
					number.Tokenize(sourceCode, *m_currentChar, token);
				}
				else
				{
					// check for uncomplete float
					if ('.' == token[token.size()])
					{
						//launch error
					}
					
					// check for multiple dots
					int dotCount = 0;
					for (int i = 0; i < token.size(); ++i)
					{
						if ('.' == token[i]) { ++dotCount; }
					}
					if (dotCount > 1) {
						// launch error
					}

					// save the number
					if (dotCount != 0)
					{
						m_mapToken.insert(std::make_pair(NM_HEADER::FLOAT, token));
						token = "";
					}
					else
					{
						m_mapToken.insert(std::make_pair(NM_HEADER::NUMBER, token));
						token = "";
					}
				}
			}
			else if (IsOperator(sourceCode, *m_currentChar))
			{
				token = sourceCode[*m_currentChar];
				m_mapToken.insert(std::make_pair(NM_HEADER::OPERATOR, token));
				token = "";
			}
		}
		else
		{
			std::string token;
			token += sourceCode[*m_currentChar];
			m_error.m_errorMap.insert(std::make_pair(*m_currentChar, token));
			std::cout << "Non_valid character " << sourceCode[*m_currentChar] << std::endl;
		}
		++* m_currentChar;
	}
	/*
	std::string token;
	for (int i = 0; i < strlen(sourceCode); ++i)
	{
		if (sourceCode[i] != ' ')
		{
			token += sourceCode[i];
		}
		else
		{
			// check token type
			if (IsReserved(token))
			{
				//LexState
				m_mapToken.insert(std::make_pair(NM_HEADER::RESERVED, token));
				token.clear();
			}
			else if (IsOperator(token)) {
				m_mapToken.insert(std::make_pair(NM_HEADER::OPERATOR, token));
				token.clear();
			}
			else if (ValidNumber(token))
			{
				m_mapToken.insert(std::make_pair(NM_HEADER::NUMBER, token));
				token.clear();
			}
			else {
				m_mapToken.insert(std::make_pair(NM_HEADER::NAME, token));
				token.clear();
			}
		}
	}*/
	// create lexstate_identifier variable
	// call tokenize function like from lexer.cpp
}
