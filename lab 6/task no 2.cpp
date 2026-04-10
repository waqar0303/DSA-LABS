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
	
	void insertatbeginning(int value)
	{
		
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		head = temp;
	}
	void insertatend(int value)
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
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = temp;


		}

	}
	void deleted(int pos)
	{
		node* curr = head;
		node* prev = head;

		for (int i = 1; i < pos; i++)
		{
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
	}
	
	void display()
	{
		node* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
		
};
int main()
{
	list l;
	l.insertatend(10);
	l.insertatend(20);
	l.insertatend(30);
	l.insertatbeginning(1);
	l.display();
	l.deleted(2);
	l.display();
}