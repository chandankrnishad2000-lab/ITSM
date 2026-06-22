#include<iostream>
using namespace std;

class Stack
{
    int arr[5];
    int top;

public:

    Stack()
    {
        top = -1;
    }

    void push(int value)
    {
        if(top == 4)
        {
            cout << "Stack Overflow\n";
        }
        else
        {
            top++;
            arr[top] = value;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow\n";
        }
        else
        {
            cout << "Deleted: " << arr[top] << endl;
            top--;
        }
    }

    void display()
    {
        for(int i = top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();

    return 0;
}