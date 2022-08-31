#include <iostream>
#include "Vm.h"

long VirtualMachine::Excute(vector<Code>* CodeList)
{
	for (auto v = CodeList->begin(); v != CodeList->end(); v++)
	{
		switch ((*v).instruction)
		{
			case Instruction::PUSHINT:
			{
				stack.push_back(v->operand);
				break;
			}
			case Instruction::ADD:
			{
				long op2 = stack.back();
				stack.pop_back();
				long op1 = stack.back();
				stack.pop_back();

				long operand = op1 + op2;
				stack.push_back(operand);
				break;
			}
			case Instruction::SUB:
			{
				long op2 = stack.back();
				stack.pop_back();
				long op1 = stack.back();
				stack.pop_back();

				long operand = op1 - op2;
				stack.push_back(operand);
				break;
			}
			case Instruction::MUL:
			{
				long op2 = stack.back();
				stack.pop_back();
				long op1 = stack.back();
				stack.pop_back();

				long operand = op1 * op2;
				stack.push_back(operand);
				break;
			}
			case Instruction::DIV:
			{
				long op2 = stack.back();
				stack.pop_back();
				long op1 = stack.back();
				stack.pop_back();

				long operand = op1 / op2;
				stack.push_back(operand);
				break;
			}
		}
	}

	long ret = stack.back();
	stack.pop_back();

	return ret;
}