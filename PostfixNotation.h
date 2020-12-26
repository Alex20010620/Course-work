#ifndef reverse_H
#define reverse_H
#include <string>
#include "OperatorStack.h"
#include "NumberStack.h"

class reverse_Polish_Notation
{
public:
	reverse_Polish_Notation();
	~reverse_Polish_Notation();

	void input();
	double infixToPostfix();
	int getPriority(char Operator);
	void calculation(char Operator);
	std::string infix_string;

private:

	OperatorStack operators;
	NumberStack number;
	bool flag = true, flag1 = true, flag2 = false, space = false;
};
#endif