#include<cstdio>
struct Node
{
    int no;
    Node *link;

    Node(){no=0;link=NULL;}
};

struct LinkedStack
{
    Node *top;

    LinkedStack(){top=NULL;}
    ~LinkedStack(){while(top!=NULL) delete pop();}

    void push(Node *p)
    {
        if(top==NULL) top=p;
        else
        {
            p->link=top;
            top=p;
        }
    }
    Node *pop()
    {
        if(top==NULL) return NULL;
        else 
        {
            Node *p=top;
            top=p->link;
            return p;
        }
    }
    void display()
    {
        for(Node *p=top;p!=NULL;p=p->link)
            printf("<%2d>",p->no);
        printf("\n");
    }
};

int main()
{
    LinkedStack stack;
    Node *s1=new Node;
    s1->no=1;

    stack.push(s1);
    stack.display();

    Node *s2=new Node;
    s2->no=2;
    stack.push(s2);
    stack.display();

    Node *node=stack.pop();
    delete node;
    stack.display();
}