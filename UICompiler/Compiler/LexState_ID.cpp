#include "LexState_ID.h"
void LexState_ID::Tokenize(const char* sourceCode, int currentChar, std::string& token)
{
	token += sourceCode[currentChar];
}