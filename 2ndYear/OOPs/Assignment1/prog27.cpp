#include <iostream>
using namespace std;

class Queue
{

    int rear, front;

    int size;
    int *data;

public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        data = new int[s];
    }

    void add(int value);
    int remove();
    void disp();
};

void Queue::add(int value)
{
    if ((front == 0 && rear == size - 1) ||
        (rear == (front - 1) % (size - 1)))
    {
        printf("Queue is Full \n");
        return;
    }

    else if (front == -1)
    {
        front = rear = 0;
        data[rear] = value;
    }

    else if (rear == size - 1 && front != 0)
    {
        rear = 0;
        data[rear] = value;
    }

    else
    {
        rear++;
        data[rear] = value;
    }
}

int Queue::remove()
{
    if (front == -1)
    {
        printf("Queue is Empty \n");
        return -1;
    }

    int val = data[front];
    data[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
        front = 0;
    else
        front++;

    return val;
}

void Queue::disp()
{
    if (front == -1)
    {
        printf("Queue is Empty \n");
        return;
    }
    printf("Circular Queue : ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ", data[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", data[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", data[i]);
    }
    printf("\n");
}

int main()
{
    const int MAX=10;
    Queue q(MAX);

    for (int i = 2; i <= 5; i++)
    {
        printf("Add : %d \n", i);
        q.add(i);
        q.disp();
    }

    for (int i = 1; i <= 2; i++)
    {
        printf("Pop \n");
        printf("Deleted value = %d \n", q.remove());
        q.disp();
    }

    return 0;
}