#include<cstdio>

class Node
{
    int data;
    Node *link;

public:
    Node(int val=0){data=val;link=NULL;}
    Node *getLink(){return link;}
    void setlink(Node *n){link=n;}
    void display(){printf(" [%d]",data);}
};

class LinkedQueue
{
    Node *front;
    Node *rear;

public:
    LinkedQueue(){front=NULL;rear=NULL;}
    ~LinkedQueue(){while(!isEmpty()) delete dequeue();}

    bool isEmpty(){return front==NULL;}

    void enqueue(Node *p)
    {
        if(isEmpty()) front=rear=p;
        else
        {
            rear->setlink(p);
            rear=p;
        }
    }

    Node *dequeue()
    {
        if(isEmpty()) return NULL;

        Node *p=front;
        front=front->getLink();

        if(!front) rear=NULL;
        return p;
    }

    Node *peek(){return front;}
    void display()
    {
        printf("<");
        for(Node *p=front;p;p=p->getLink()) p->display();
        printf(" >\n");
    }
};

int main()
{
    LinkedQueue q;

    for(int i=1;i<10;i++) q.enqueue(new Node(i));
    q.display();
    delete q.dequeue();
    delete q.dequeue();
    delete q.dequeue();
    q.display();
}