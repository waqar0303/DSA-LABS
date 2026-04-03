#include<iostream>
#include<string>
using namespace std;

template <typename T>
class AbstractQueue
{
public:
    virtual void enQueue(T value) = 0;
    virtual T deQueue() = 0;
    virtual T front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T>
{
private:
    T* arr;
    int capacity;
    int frontindex;
    int rearindex;
    int count;

public:
    myQueue(int size)
    {
        capacity = size;
        arr = new T[capacity];
        frontindex = 0;
        rearindex = -1;
        count = 0;
    }

    ~myQueue()
    {
        delete[] arr;
    }

    void enQueue(T value) override
    {
        if (isFull())
        {
            cout << "Queue is Full." << endl;
            return;
        }
        rearindex = (rearindex + 1) % capacity;
        arr[rearindex] = value;
        count++;
    }

    T deQueue() override
    {
        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
            return T();   // return default value
        }
        T value = arr[frontindex];
        frontindex = (frontindex + 1) % capacity;
        count--;
        return value;
    }

    T front() const override
    {
        if (isEmpty())
        {
            cout << "Queue is Empty." << endl;
            return T();   // return default value
        }
        return arr[frontindex];
    }

    bool isEmpty() const override
    {
        return count == 0;
    }

    bool isFull() const override
    {
        return count == capacity;
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = 0; i < count; i++)
        {
            cout << arr[(frontindex + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter queue size: ";
    cin >> size;

    myQueue<int> q(size);

    int choice, value;

    do {
        cout << "\n--- Queue Menu ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Front" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enQueue(value);
            break;

        case 2:
            if (!q.isEmpty())
                cout << "Dequeued: " << q.deQueue() << endl;
            else
                cout << "Queue is Empty." << endl;
            break;

        case 3:
            if (!q.isEmpty())
                cout << "Front element: " << q.front() << endl;
            else
                cout << "Queue is Empty." << endl;
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Empty" << endl;
            else
                cout << "Not Empty" << endl;
            break;

        case 6:
            if (q.isFull())
                cout << "Full" << endl;
            else
                cout << "Not Full" << endl;
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}