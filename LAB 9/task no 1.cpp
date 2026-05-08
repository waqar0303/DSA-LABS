#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value)
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node* head;

public:
    DoublyLinkedList()
    {
        head = nullptr;
    }

    void insertAtStart(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value)
    {
        Node* newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int value, int position)
    {
        if (position <= 1)
        {
            insertAtStart(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < position - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Invalid Position!" << endl;
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }

        temp->next = newNode;
    }

    void deleteByValue(int value)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp != nullptr && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Value not found!" << endl;
            return;
        }

        if (temp == head)
        {
            head = head->next;

            if (head != nullptr)
            {
                head->prev = nullptr;
            }

            delete temp;
            return;
        }

        if (temp->prev != nullptr)
        {
            temp->prev->next = temp->next;
        }

        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void displayForward()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        cout << "Forward Traversal: ";

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    void displayReverse()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        cout << "Reverse Traversal: ";

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }

    ~DoublyLinkedList()
    {
        Node* temp;

        while (head != nullptr)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.insertAtStart(5);

    list.insertAtPosition(15, 3);

    cout << "List after insertion:" << endl;
    list.displayForward();
    list.displayReverse();

    list.deleteByValue(5);
    list.deleteByValue(30);

    cout << "\nList after deletion:" << endl;
    list.displayForward();
    list.displayReverse();

    return 0;
}