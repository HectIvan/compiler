#include "pch.h"

#include "Compiler.h"

Compiler::Manager::Manager()
{
    m_lexer = new Lexer();
}

Compiler::Manager::~Manager()
{
    delete m_lexer;
    m_lexer = nullptr;
}

cli::array<String^>^ Compiler::Manager::compile(String^ sourceCode)
{
    cli::array<String^>^ arr = gcnew cli::array<String^>(sizeof(sourceCode));
    m_lexer->Tokenize((const char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sourceCode).ToPointer());
    arr[0] = gcnew String(sourceCode);
    return arr;
}