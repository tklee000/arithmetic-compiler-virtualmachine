#pragma once


enum class Instruction {
	ADD,
	SUB,
	MUL,
	DIV,
	PUSHINT
};

typedef struct _Code
{
	Instruction instruction;
	long operand;
} Code;
