#include "PostfixNotation.h"
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

reverse_Polish_Notation::reverse_Polish_Notation() 
{

}

void reverse_Polish_Notation::input() 
{
	getline(cin,infix_string);
}

reverse_Polish_Notation::~reverse_Polish_Notation() 
{

}

double reverse_Polish_Notation::infixToPostfix()
{
	int size = infix_string.length(), prioritet, prioret_stack;;
	for (int i = 0; i < size; i++) {
		if (infix_string[i] == '0' || infix_string[i] == '1'
			|| infix_string[i] == '2' || infix_string[i] == '3'
			|| infix_string[i] == '4' || infix_string[i] == '5'
			|| infix_string[i] == '6' || infix_string[i] == '7'
			|| infix_string[i] == '8' || infix_string[i] == '9' || infix_string[i] == '.') {
			cout << infix_string[i];
			if (infix_string[i] == '.') {
				number.head->flag = true;
			}
			if (flag1) {
				flag1 = false;
				number.push(0);
			}
			number.head->numb += infix_string[i];
			number.head->data = atof(number.head->numb.c_str());
		}
		else if (infix_string[i] == 'p') {
			cout << infix_string[i];
			if (infix_string[i + 1] == 'i') {
				cout << infix_string[i + 1];
				number.push(acos(-1.0));
				i++;
			}
			else
			{
				cout << "Input error in " << i + 1 << " position";
				return -1;
			}
		}
		else if (infix_string[i] == 'e'){
			cout << infix_string[i];
			number.push(exp(1));
			}
		else {
			if (!flag1) {
				flag1 = true;
				if (space) {
					cout << " ";
				}
				space = true;
			}
			prioritet = getPriority(infix_string[i]);
			if (prioritet == 1) {
				operators.push(infix_string[i]);
			}
			else if (prioritet == 0) {
				while(getPriority(operators.head->data) != 1) {
					if (operators.head->data == 'F') {
						if (space) {
							cout << " ";
						}
						space = true;
						calculation(operators.head->data);
						for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
							cout << operators.head->Queue.head->data;
						}

					}
					else {
						if (space) {
							cout << " ";
						}
						space = true;
						calculation(operators.head->data);
						cout << operators.head->data;
					}
					cout << " ";
					operators.pop_front();
				}
				operators.pop_front();
			}
			else if (prioritet == 2 || prioritet == 3 || (prioritet == 4 && flag)) {
				if (operators.head != nullptr) {
					while(operators.head != nullptr &&  getPriority(operators.head->data) != 1 &&  getPriority(operators.head->data) >= prioritet) {
						if (space) {
							cout << " ";
						}
						space = true;
						if (operators.head->data == 'F') {
							calculation(operators.head->data);
							for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
								cout << operators.head->Queue.head->data;
							}
						}
						else {
							calculation(operators.head->data);
							cout << operators.head->data;
						}
						cout << " ";
						operators.pop_front();
					}
				}
				operators.push(infix_string[i]);
			}
			else if (prioritet == 4 && !flag) {
				if (space) {
					cout << " ";
				}
				space = true;
				flag = true;
				operators.push('F');
				if (infix_string[i] == 'c') {
					if (infix_string[i + 1] == 'o' || infix_string[i + 2] == 's') {
						for (int j = i; j < i + 3; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 2;
					}
					else if (infix_string[i + 1] == 't' || infix_string[i + 2] == 'g') {
						for (int j = i; j < i + 3; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 2;
					}
					else
					{
						cout << "Input error in " << i + 1 << " position";
						return -1;
					}
				}
				else if (infix_string[i] == 'l') {
					if (infix_string[i + 1] == 'o' || infix_string[i + 2] == 'g') {
						for (int j = i; j < i + 3; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 2;
					}
					else if (infix_string[i + 1] == 'n') {

						for (int j = i; j < i + 2; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 1;
					}
					else
					{
						cout << "Input error in " << i + 1 << " position";
						return -1;
					}
				}
				else if (infix_string[i] == 's') {
					if (infix_string[i + 1] == 'i' || infix_string[i + 2] == 'n') {
						for (int j = i; j < i + 3; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 2;
					}
					else if (infix_string[i + 1] == 'q' || infix_string[i + 2] == 'r' || infix_string[i + 3] == 't') {
						for (int j = i; j < i + 4; ++j)
							operators.head->Queue.push(infix_string[j]);
						i += 3;
					}
					else if (infix_string[i + 1] == 'h') {
						for (int j = i; j < i + 2; ++j)
							operators.head->Queue.push(infix_string[j]);
						i++;
					}
					else
					{
						cout << "Input error in " << i + 1 << " position";
						return -1;
					}
				}
				else if (infix_string[i] == 't') {
					for (int j = i; j < i + 2; ++j)
						operators.head->Queue.push(infix_string[j]);
					i += 1;
				}

			}
			else {
				cout << "Input error in " << i + 1 << " position";
				return -1;
			}
		}
	}

	if (operators.size != 0) {
		while(operators.head != nullptr) {
				cout << " ";
			if (operators.head->data == 'F') {
				calculation(operators.head->data);
				for (int j = 0; j < operators.head->Queue.size; operators.head->Queue.pop()) {
					cout << operators.head->Queue.head->data;
				}
				
			}
			else {
				calculation(operators.head->data);
				cout << operators.head->data;
			}
			operators.pop_front();
		}
	}
	cout << endl << "result: " << number.head->data;
	return number.head->data;
}

int reverse_Polish_Notation::getPriority(char Operator)
{
	switch (Operator)
	{
	case '^':
	case 'F':
		return 4;
	case '*':
	case '/':
		return 3;

	case '-':
	case '+':
		return 2;

	case '(':
		return 1;
	case ')':
		return 0;
	default:
		flag = false;
		return 4;

	}
}

void reverse_Polish_Notation::calculation(char Operator) 
{
	double result;
	switch (Operator)
	{
	case '^': {
		result = pow(number.head->next->data, number.head->data);
		number.pop_front();
		number.pop_front();
		number.push(result);
		break;
	}
	case '*':
	{
		result = number.head->next->data * number.head->data;
		number.pop_front();
		number.pop_front();
		number.push(result);
		break;
	}
	case '/':
	{
		result = number.head->next->data / number.head->data;
		number.pop_front();
		number.pop_front();
		number.push(result);
		break;
	}
	case '-':
	{
		result = number.head->next->data - number.head->data;
		number.pop_front();
		number.pop_front();
		number.push(result);
		break;
	}
	case '+':
	{
		result = number.head->next->data + number.head->data;
		number.pop_front();
		number.pop_front();
		number.push(result);
		break;
	}
	case 'F': 
	{
		if (operators.head->Queue.head->data == 'c') {
				if (operators.head->Queue.head->next->data == 'o') {
					result = cos(number.head->data);
					number.pop_front();
					number.push(result);
				}
				else {
					result = 1/tan(number.head->data);
					number.pop_front();
					number.push(result);
				}
		}
		else if (operators.head->Queue.head->data == 'l') {
				if (operators.head->Queue.head->next->data == 'o') {
					result = log10(number.head->data);
					number.pop_front();
					number.push(result);
				}
				else  {
					result = log(number.head->data);
					number.pop_front();
					number.push(result);
				}
		}
		else if (operators.head->Queue.head->data == 's') {
				if (operators.head->Queue.head->next->data == 'h') {
					result = (pow(exp(1), number.head->data) - pow(exp(1), -number.head->data)) / 2;
					number.pop_front();
					number.push(result);
				}
				else if (operators.head->Queue.head->next->data == 'i') {
					result = sin(number.head->data);
					number.pop_front();
					number.push(result);
				}
				else  {
					result = sqrt(number.head->data);
					number.pop_front();
					number.push(result);
				}
		}
		else if (operators.head->Queue.head->data == 't') {
			result = tan(number.head->data);
			number.pop_front();
			number.push(result);
		}

	}
	default:
		break;
	}
}
