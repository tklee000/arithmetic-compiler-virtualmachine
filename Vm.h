#pragma once

#include "Lexer.h"
#include "Node.h"


class VirtualMachine
{
public:

	VirtualMachine() {}
	long Excute(vector<Code>* CodeList);

private:
	vector<long> stack;
};
