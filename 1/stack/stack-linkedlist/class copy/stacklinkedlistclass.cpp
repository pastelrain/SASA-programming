#include<cstdio>
#include<cstring>

class Node
{
    int no;
    char name[10];
    Node *link;
    
public:
    Node(int i=0,const char *inname=""){no=i;strcpy(name,inname);link=NULL;} //Node(){no=0;link=NULL};

    Node *getLink(){return link;}
    void setLink(Node *p){link=p;}
    void display(){printf("<%2d>: %s   ",no,name);}
};

class LinkedStack
{
    int count;
    Node *top;

public:
    LinkedStack(){count=0;top=NULL;}
    ~LinkedStack(){while(top!=NULL) delete pop();}

    int size(){return count;}
    void push(Node *p)
    {
        if(top==NULL) top=p;
        else
        {
            p->setLink(top); //p->link=top;
            top=p;
        }
        count++;
    }
    Node *pop()
    {
        if(top==NULL) return NULL;
        Node *p=top;
        top=p->getLink();
        return p;
        count--;
    }
    Node *peek()
    {
        if(top==NULL) return NULL;
        Node *p=top;
        for(int i=0;i<count;i++,p=p->getLink());
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
    Node *s1=new Node(1115,"ÇÑÁöÈÄ"); //s1->no=1;

    stack.push(s1);
    stack.display();

    Node *s2=new Node(1103,"±èÁø¿í");
    stack.push(s2);
    stack.display();

    stack.push(new Node(1104,"¹éÇÏºó"));
    stack.display();

    Node *node=stack.pop();
    delete node;
    stack.display();
}