#ifndef stack_H
#define stack_H
#include "queue.h"
class OperatorStack
{
private:
	class stackElement {
	public:
		char data;
		Queue Queue;
		stackElement* next;

		stackElement(char data, stackElement* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		~stackElement()
		{

		}

	};
public:
	stackElement* head;
	stackElement* tail;
	unsigned int size;

	OperatorStack() 
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~OperatorStack() 
	{
		clear();
	}

	void clear() 
	{
		while (size != 0)
		{
			pop_front();
		}
	}

	void push(char data) 
	{
		if (size == 0) {
			head = new stackElement(data);
			tail = head;
		}
		else {
			head = new stackElement(data, head);
		}
		size++;
	}

	void pop_front() {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			stackElement* current = head;
			head = head->next;
			delete current;
		}
		size--;

	}

	void reset_list()
	{
		head = nullptr;
		tail = nullptr;
	}

};
#endif
