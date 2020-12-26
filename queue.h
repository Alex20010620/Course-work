#ifndef queue_H
#define queue_H
class Queue
{
private:
	class queueElement {
	public:
		char data;
		queueElement* next;

		queueElement(char data , queueElement* next = nullptr)
		{
			this->data = data;
			this->next = next;
		};
		~queueElement()
		{

		}
	};

public:
	queueElement* head;
	queueElement* tail;
	unsigned int size;

	Queue() 
	{
		tail = nullptr;
		head = nullptr;
		size = 0;
	}

	~Queue() 
	{
		clear();
	}

	void clear() 
	{
		while (size != 0)
		{
			pop();
		}
	}

	void push(char data) 
	{
		if (size == 0) {
			head = new queueElement(data);
			tail = head;
		}
		else {
			tail->next = new queueElement(data);
			tail = tail->next;
		}
		size++;
	}

	void pop() 
	{
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			queueElement* current = head;
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