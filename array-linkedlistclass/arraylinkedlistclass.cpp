#include<cstdio>
class Node
{
	int data;
	Node *link;

public:
	Node(int val=0){data=val,link=NULL;}

	Node *getLink(){return link;}
	void setlink(Node* p){link=p;}
	void display(){printf("<%2d>",data);}
};

class LinkedList
{
	Node org;

public:
	LinkedList():org(0){} //org.data=0; org.link=NULL;
	~LinkedList(){while(org.getLink()) delete remove(0)}

	Node *getEntry(int pos)
	{
		Node *n=&org;
		for(int i=-1;i<pos;i++,n-n->getLink());
		return n;
	}

	void insert(Node *n)
	{
		
	}

	Node *remove()
	{

	}
};