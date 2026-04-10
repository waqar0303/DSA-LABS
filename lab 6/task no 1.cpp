#include<iostream>
using namespace std;

class node
{
public:
	node* next;
	int data;
	
};
class list
{
	node* head;
public:
	list()
	{
		head = nullptr;
	}
	void createnode(int value)
	{
		node* temp = new node;
		node* curr = head;
		temp->data = value;
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;
		}
		else
		{
			while (curr->next!=nullptr)
			{
				curr = curr->next;
			}
			curr->next = temp;
		
			
		}

	}
	void display()
	{
		node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

		
};
int main()
{
	list l;
	l.createnode(10);
	l.createnode(20);
	l.createnode(30);
	l.display();
}