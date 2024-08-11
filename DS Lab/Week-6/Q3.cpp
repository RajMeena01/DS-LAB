#include <iostream>
using namespace std;
class queue
{
public:
    int front, rear, size, capacity;
    int *arr;
    queue(int capacity)
    {
        this->capacity = capacity;
        front = 0;
        rear = capacity - 1;
        size = 0;
        arr = new int[capacity];
    }
    int isEmpty()
    {
        return size == 0;
    }
    int isFull()
    {
        return size == capacity;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return __INT_MAX__;
        }
        return arr[front];
    }
    void enqueue(int data)
    {
        if (isFull())
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = data;
        size++;
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow" << endl;
            return __INT_MAX__;
        }
        int data = arr[front];
        front = (front + 1) % capacity;
        size--;
        return data;
    }
    ~queue()
    {
        delete[] arr;
    }
};
int main()
{
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << "Size:" << q.size << endl;
}