#include<cstdio>
#define MAX_QUEUE_SIZE 100

class Queue
{
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];

public:
    Queue(){front=rear=-1;}
    bool isEmpty(){return front==rear;}
    bool isFull(){return rear==MAX_QUEUE_SIZE-1;}

    void enqueue(int val)
    {
        if(isFull()) return;

        data[++rear]=val;
    }

    int dequeue()
    {
        if(isEmpty()) return -1;

        return data[++front];
    }

    int peek()
    {
        if(isEmpty()) return -1;
        
        return data[front+1];
    }

    void display()
    {
        printf("< ");
        for(int i=front+1;i<=rear;i++) printf("[%2d]",data[i]);
        printf(">\n");
    }
};

int main()
{
    Queue q;
    for(int i=1;i<10;i++) q.enqueue(i);

    q.display();
    q.dequeue(); q.dequeue(); q.dequeue();
    q.display();
    q.enqueue(2);
    q.display();
    printf("peek: %d\n",q.peek());
    q.display();
}