#include <cstdio>
class Node{
    int data;
    Node *link;

public:
    Node(int val=0):data(val),link(NULL){}
    Node *getLink(){return link;}
    void setLink(Node* next){link=next;}
    void display(){printf("<%2d>",data);}
    bool hasData(int val){return data==val;}

    void insertNext(Node *n){
        if(n!=NULL){
            n->link=link;
            link=n;
        }
    }

    Node*removeNext(){
        Node*removed=link;
        if(removed!=NULL) link=removed->link;
        return removed;
    }
};

class LinkedList{
    Node org;

public:
    LinkedList():org(0){}
    ~LinkedList(){clear();}
    void clear(){while(!isEmpty()) delete remove(0);}
    Node*getHead(){return org.getLink();}
    bool isEmpty(){return getHead()==NULL;}

    Node*getEntry(int pos){
        Node *n=&org;
        for(int i=-1;i<pos;i++,n=n->getLink()){
            if(n==NULL) break;
        }
        return n;
    }

    void insert(int pos,Node*n){
        Node*prev=getEntry(pos-1);
        if(prev!=NULL)prev->insertNext(n);
    }

    Node *remove(int pos){
        Node*prev=getEntry(pos-1);
        return prev-> removeNext();
    }

    Node*find(int val){
        for(Node*p=getHead();p!=NULL;p=p->getLink()){
            if(p->hasData(val))return p;
        }
        return NULL;
    }

    void reverse(){
        Node *prev=getEntry(-1);
        Node *n=prev->getLink();
        Node *next=new Node;
        
        prev->setLink(NULL);

        while(n!=NULL){
            next=n->getLink();
            this->display();
            prev->insertNext(n);
            n=next;
        }
    } 
    void replace(int pos,Node*n){
        Node*prev=getEntry(pos-1);
        if(prev!=NULL){
            delete prev->removeNext();
            prev->insertNext(n);
        }
    }

    int size(){
        int count=0;
        for(Node*p=getHead();p!=NULL;p=p->getLink()){
            count++;
        }
        return count;
    }

    int display(){
        printf("[전체 항목 수=%2d]:",size());
        for(Node*p=getHead();p!=NULL;p=p->getLink()){
            p->display();
        }
        printf("\n");
    }
};

int main(){
    LinkedList list;

    list.insert(0,new Node(10));
    list.insert(0,new Node(20));
    list.insert(1,new Node(30));
    list.insert(list.size(),new Node(40));
    list.insert(2,new Node(50));
    list.display();

    list.remove(2);
    list.remove(list.size()-1);
    list.remove(0);
    list.replace(1,new Node(90));
    list.display();
    list.clear();
    list.display();
}