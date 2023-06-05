#include "LexState_Number.h"
void LexState_Number::Tokenize(const char* sourceCode, int currentChar, std::string& token)
{
	int numDot = 0;
	int loc = currentChar;
	while ((sourceCode[loc] >= '0' && sourceCode[loc] <= '9') || sourceCode[loc] == '.')
	{
		token += sourceCode[loc];
	}

	if (token[token.size()] == '.')
	{
		// launch uncomplete float 
	}
	else if (token[0] == '.')
	{
		token.insert(token.cbegin(),'0');
		// put a 0 at the beggining
	}

	for (int i = 0; i < token.size(); ++i)
	{
		if (token[i] == '.')
		{
			++numDot;
		}
	}

	if (numDot > 1)
	{
		// launch unidentified number
	}
}