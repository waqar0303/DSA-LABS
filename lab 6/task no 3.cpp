#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
    Node* head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    void insertAtPosition(int value, int pos)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (pos == 1)
        {
            newNode->next = head;
            head = newNode;
            cout << "Inserted at position 1" << endl;
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Inserted at position " << pos << endl;
    }

    void deleteAtPosition(int pos)
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;

        if (pos == 1)
        {
            head = head->next;
            delete temp;
            cout << "Deleted from position 1" << endl;
            return;
        }

        Node* prev = nullptr;
        for (int i = 1; i < pos && temp != nullptr; i++)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "Invalid position!" << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;

        cout << "Deleted from position " << pos << endl;
    }

    void search(int key)
    {
        Node* temp = head;
        int pos = 1;

        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                cout << "Element found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }

        cout << "Element not found!" << endl;
    }

    void countNodes()
    {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        cout << "Total nodes: " << count << endl;
    }

    void display()
    {
        Node* temp = head;

        if (temp == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        cout << "List: ";
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    int choice, value, pos;

    do
    {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Insert at position" << endl;
        cout << "2. Delete at position" << endl;
        cout << "3. Search element" << endl;
        cout << "4. Count nodes" << endl;
        cout << "5. Display list" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertAtPosition(value, pos);
            break;

        case 2:
            cout << "Enter position to delete: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 4:
            list.countNodes();
            break;

        case 5:
            list.display();
            break;

        case 0:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);

    return 0;
}