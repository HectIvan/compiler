#pragma once
#include <Windows.h>
#include "Lexer.h"
#include "LexState.h"

using namespace System;

namespace Compiler {
	public ref class Manager
	{
		// TODO: Agregue aquí los métodos de esta clase.
	public:
		// create implementation
		cli::array<String ^> ^compile(String^ sourceCode);
		Manager();
		~Manager();

	private:
		Lexer* m_lexer;
	};
}
