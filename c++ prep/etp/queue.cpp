#include<iostream>
using namespace std;

class Queue
{
    int arr[5];
    int front, rear;

public:

    Queue()
    {
        front = 0;
        rear = -1;
    }

    void enqueue(int value)
    {
        if(rear == 4)
        {
            cout << "Queue Overflow\n";
        }
        else
        {
            rear++;
            arr[rear] = value;
        }
    }

    void dequeue()
    {
        if(front > rear)
        {
            cout << "Queue Underflow\n";
        }
        else
        {
            cout << "Deleted: " << arr[front] << endl;
            front++;
        }
    }

    void display()
    {
        for(int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    cout << endl;

    q.dequeue();

    return 0;
}