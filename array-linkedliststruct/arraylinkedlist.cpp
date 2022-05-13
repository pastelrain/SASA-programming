//단일연결리스트. Node와 연결리스트 클래스 모두 struct로 구현 
//Node.h: 연결 리스트로 구현된 리스트를 위한 노드 클래스
#include <cstdio>
class Node{
	int data;
	Node *link;

public:
	Node(int val=0){	data=val; link=NULL;	}
	Node *getLink(){ return link; }
	void display(){ printf("<%2d>",data); }
}; 

//LinkedList.h
//#include "Node.h"
class LinkedList{
	Node org;

public:
	LinkedList(){	org.data=0; org.link=NULL;	}
	~LinkedList(){		}
	
	Node *getEntry(int pos){
		Node *n=&org;
        for(int i=-1;i<pos && n;i++,n=n->link);

        return n;
	}
	
	void insert(int pos, Node *n){
		Node *prev = getEntry(pos-1);
		if(prev)
		{
			n->link=prev->link;
      		prev->link=n;
		}
	}
	
	Node *remove(int pos){
		Node *prev = getEntry(pos-1);
		Node *removed=prev->link;
		if(removed) prev->link=removed->link;
		return removed;
	} 
	
	void display(){
        for(Node *n=org.link;n;n=n->link) printf("<%2d>",n->data);
		printf("\n");
	} 	
};

//LinkedList.cpp
//#include "LinkedList.h"
int main(){
	LinkedList list;
	Node *n1=new Node(1);
	list.insert(0, n1);
	list.display();
	
	list.insert(0, new Node(2));
	list.insert(0, new Node(3));
	list.display();
	
	list.insert(1, new Node(4));
	list.display();
	
	list.remove(0);
	list.display();
}