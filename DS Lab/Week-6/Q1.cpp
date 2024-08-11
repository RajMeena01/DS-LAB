#include <iostream>
using namespace std;
class Stack
{
private:
    int arr[100];
    int counter = 0;
    int pointer = -1;
public:
    void push(int data)
    {
        if (counter == 100)
        {
            cout << "Stack is Overflowing..." << endl;
            return;
        }
        pointer++;
        arr[pointer] = data;
        counter++;
    }
    int pop()
    {
        if (counter == 0)
        {
            cout << "Stack is Empty..." << endl;
            return -1;
        }
        pointer--;
        counter--;
        return arr[pointer + 1];
    }
    int top()
    {
        if (counter == 0)
        {
            cout << "Stack is Empty..." << endl;
            return -1;
        }
        return arr[pointer];
    }
    int peep(int index)
    {
        if (index > counter)
        {
            cout << "Poistion is out of bound..." << endl;
            return -1;
        }
        return arr[index - 1];
    }
    bool isEmpty()
    {
        if (counter == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int size()
    {
        return counter;
    }
    void print()
    {
        for (int i = 0; i < counter; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    Stack obj1;
    obj1.push(1);
    obj1.push(2);
    obj1.push(3);
    obj1.push(4);
    obj1.push(5);
    obj1.print();
    cout << obj1.pop() << endl;
    cout << obj1.top() << endl;
    cout << obj1.peep(2) << endl;
    obj1.isEmpty() ? cout << "Stack is not empty." << endl : cout << "Stack is empty." << endl;
    cout << obj1.size() << endl;
    obj1.print();
}