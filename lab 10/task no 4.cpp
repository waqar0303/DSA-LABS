#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* next;
};

class list
{

	
public:
	node* head;
	list()
	{
		head = nullptr;
	}
	void linklist(int value)
	{
		node* temp = new node;
		temp->data = value;
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;

		}
		else
		{
			node* curr = head;
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = temp;
		}
	}
	void display(node* head)
	{
		if (head == nullptr)
		{
			return;
		}
		cout << head->data << " ";
		display(head->next);
	}

};
int main()
{
	list l;
	l.linklist(5);
	l.linklist(10);
	l.linklist(15);
	l.linklist(20);

	l.display(l.head);
	return 0;
}