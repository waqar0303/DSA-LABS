#include<iostream>
#include<string>
using namespace std;

class Package
{
public:
    int id;
    string address;
    int startTime;
    int endTime;
    Package* next;

    Package(int i, string addr, int s, int e)
    {
        id = i;
        address = addr;
        startTime = s;
        endTime = e;
        next = nullptr;
    }
};

class Queue
{
    Package* frontNode;
    Package* rearNode;

public:
    Queue()
    {
        frontNode = rearNode = nullptr;
    }

    void enqueue(int id, string address, int start, int end)
    {
        Package* temp = new Package(id, address, start, end);

        if (rearNode == nullptr)
        {
            frontNode = rearNode = temp;
        }
        else
        {
            rearNode->next = temp;
            rearNode = temp;
        }

        cout << "Package " << id << " added to queue." << endl;
    }

    void dequeue()
    {
        if (frontNode == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Package* temp = frontNode;
        cout << "Delivered Package ID: " << temp->id << endl;

        frontNode = frontNode->next;

        if (frontNode == nullptr)
            rearNode = nullptr;

        delete temp;
    }

    void front()
    {
        if (frontNode == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Next Package -> ID: " << frontNode->id
            << ", Address: " << frontNode->address
            << ", Time Window: [" << frontNode->startTime
            << ", " << frontNode->endTime << "]" << endl;
    }

    void display()
    {
        if (frontNode == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Package* temp = frontNode;

        cout << "Packages in Queue:" << endl;
        while (temp != nullptr)
        {
            cout << "ID: " << temp->id
                << ", Address: " << temp->address
                << ", Time: [" << temp->startTime
                << ", " << temp->endTime << "]" << endl;
            temp = temp->next;
        }
    }

    void timeToDeliver(int currentTime)
    {
        while (frontNode != nullptr)
        {
            if (currentTime >= frontNode->startTime &&
                currentTime <= frontNode->endTime)
            {
                cout << "Package " << frontNode->id << " can be delivered now." << endl;
                dequeue();
                return;
            }
            else
            {
                cout << "Package " << frontNode->id << " expired. Skipping..." << endl;
                dequeue();
            }
        }

        cout << "No valid packages left." << endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(1, "Lahore", 9, 12);
    q.enqueue(2, "Karachi", 10, 14);
    q.enqueue(3, "Islamabad", 8, 10);

    q.display();

    cout << "Current Time: 11" << endl;
    q.timeToDeliver(11);

    q.front();
    q.display();

    return 0;
}