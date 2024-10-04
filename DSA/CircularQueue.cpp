#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue
{
private:
    int front, rear;
    int items[SIZE];

public:
    CircularQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    bool isEmpty()
    {
        return front == -1;
    }

    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full!\n";
            return;
        }
        else
        {
            if (front == -1)
                front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = value;
            cout << value << " enqueued to the queue.\n";
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!\n";
            return;
        }
        else
        {
            cout << items[front] << " dequeued from the queue.\n";
            if (front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front = (front + 1) % SIZE;
            }
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements are: ";
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
                cout << items[i] << " ";
        }
        else
        {
            for (int i = front; i < SIZE; i++)
                cout << items[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << items[i] << " ";
            
        }
        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, value;

    while (true)
    {
        cout << "\nSelect an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting program.\n";
            return false;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
