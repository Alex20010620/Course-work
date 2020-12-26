#ifndef NumberStack_H
#define NumberStack_H
#include "queue.h"

class NumberStack
{
private:
	class stackElement {
	public:
		double data;
		std::string numb;
		stackElement* next;
		bool flag;
		stackElement(double data, stackElement* next = nullptr)
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

	NumberStack() 
	{
		head = nullptr;
		tail = nullptr;
		size = 0;
	}

	~NumberStack() 
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

	void push(double data)
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

	void pop_front() 
	{
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
