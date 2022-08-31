#pragma once
#include <iostream>
#include "Lexer.h"
#include "Instruction.h"

class Node
{
public:
	virtual long Generate(vector<Code> *CodeList) = 0;
	virtual void Release() = 0;
};

class BinaryNode : Node
{
public:

	Node* Left;
	Token Operator;
	Node* Right;

	BinaryNode(Node* _Left, Token _Operator, Node* _Right)
	{
		Left = _Left;
		Operator = _Operator;
		Right = _Right;
	}

	long Generate(vector<Code>* CodeList)
	{
		Left->Generate(CodeList);
		Right->Generate(CodeList);

		Code code;

		switch (Operator.type)
		{
			case TokenType::Plus:
				//std::cout << "ADD" << endl;
				code.instruction = Instruction::ADD;
				break;
			case TokenType::Minus:
				//std::cout << "SUB" << endl;
				code.instruction = Instruction::SUB; 
				break;
			case TokenType::Mul:
			//	std::cout << "MUL" << endl;
				code.instruction = Instruction::MUL; 
				break;
			case TokenType::Div:
				//std::cout << "DIV" << endl;
				code.instruction = Instruction::DIV; 
				break;
		}

		code.operand = 0;
		CodeList->push_back(code);

		return 0;
	}

	void Release() {
		delete this;
	}
};

class IntegerNode : Node
{
public:

	Token Integer;

	IntegerNode(Token integerToken)
	{
		Integer = integerToken;
	}

	long Generate(vector<Code>* CodeList) {
		

		Code code;
		code.instruction = Instruction::PUSHINT;
		code.operand = Integer.integer;
		CodeList->push_back(code);

		//std::cout << "PUSH (" << to_string(Integer.integer) << ")" << endl;

		return 0;
	}
	void Release() {
		delete this;
	}
};
