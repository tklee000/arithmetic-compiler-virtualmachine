#include <crtdbg.h>
#include <iostream>
#include <string>
#include "Lexer.h"
#include "Parser.h"
#include "Vm.h"

using namespace std;

int main()
{
	_CrtMemState CrtMem1, CrtMem2, CrtMem3;
	_CrtMemCheckpoint(&CrtMem1);
	{
		string input = "10+2+40+((1+2)*3)/3+10";

		Lexer lexer(input);
		vector<Token> Tokens = lexer.GetTokens();
		Parser parser(&Tokens);
		vector<Code> CodeList;
		VirtualMachine vm;

		for (int i = 0; i < Tokens.size(); i++)
		{
			switch (Tokens[i].type)
			{
			case TokenType::Integer:
			{
				std::cout << to_string(Tokens[i].integer);
				break;
			}
			case TokenType::Plus:
			{
				std::cout << "+";
				break;
			}
			case TokenType::Minus:
			{
				std::cout << "-";
				break;
			}
			case TokenType::Mul:
			{
				std::cout << "*";
				break;
			}
			case TokenType::Div:
			{
				std::cout << "/";
				break;
			}
			case TokenType::LeftParens:
			{
				std::cout << "(";
				break;
			}
			case TokenType::RightParens:
			{
				std::cout << ")";
				break;
			}
			}
		}
		std::cout << endl;

		parser.Scan()->Generate(&CodeList);
		long ret = vm.Excute(&CodeList);

		std::cout << "=" << to_string(ret) << endl;
	}

	_CrtMemCheckpoint(&CrtMem2);
	if (_CrtMemDifference(&CrtMem3, &CrtMem1, &CrtMem2))
	{
		_CrtMemDumpStatistics(&CrtMem3);
		_CrtMemDumpAllObjectsSince(NULL);
	}

	return 0;
}
