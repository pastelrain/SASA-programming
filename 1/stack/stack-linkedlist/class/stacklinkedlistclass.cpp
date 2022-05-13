#include<cstdio>

class Node
{
    int no;
    Node *link;
    
public:
    Node(int i=0){no=i;link=NULL;} //Node(){no=0;link=NULL};

    Node *getLink(){return link;}
    void setLink(Node *p){link=p;}
    void display(){printf("<%2d>",no);}
};

class LinkedStack
{
    Node *top;

public:
    LinkedStack(){top=NULL;}
    ~LinkedStack(){while(top!=NULL) delete pop();}

    void push(Node *p)
    {
        if(top==NULL) top=p;
        else
        {
            p->setLink(top); //p->link=top;
            top=p;
        }
    }
    Node *pop()
    {
        if(top==NULL) return NULL;
        Node *p=top;
        top=p->getLink();
        return p;
    }
    void display()
    {
        for(Node *p=top;p!=NULL;p=p->getLink())
            p->display();
        printf("\n");
    }
};

int main()
{
    LinkedStack stack;
    Node *s1=new Node(1); //s1->no=1;

    stack.push(s1);
    stack.display();

    Node *s2=new Node(2);
    stack.push(s2);
    stack.display();

    stack.push(new Node(3));
    stack.display();

    Node *node=stack.pop();
    delete node;
    stack.display();
}