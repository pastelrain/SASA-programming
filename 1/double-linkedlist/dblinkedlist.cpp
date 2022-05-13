#include<cstdio>

class Node2
{
	int data;
	Node2 *prev,*next;

public:
	Node2(int val=0): data(val),prev(NULL),next(NULL) {}
	Node2 *getPrev(){return prev;}
	Node2 *getNext(){return next;}

	void setPrev(Node2 *p){prev=p;}
	void serNext(Node2 *p){next=p;}
	void display(){printf(" <%2d>",data);}
	bool hadData(int val){return data==val;}

	void insertNext(Node2 *p)
	{
		if(p!=NULL)
		{
			p->prev=this;
			p->next=next;
			if(next!=NULL) next->prev=p;
			next=p;
		}
	}

	Node2 *remove()
	{
		if(prev!=NULL) prev->next=next;
		if(next!=NULL) next->prev=prev;
		return this;
	}
};

class dblinkedlist
{
	Node2 org;

public:
	dblinkedlist(): org(0){}
	~dblinkedlist(){clear();}

	void clear(){while(!isEmpty()) delete remove(0);}
	Node2 *getHead(){return org.getNext();}
	bool isEmpty(){return getHead()==NULL;}

	int size()
	{
		int count=0;
		for(Node2 *p=getHead();p!=NULL;p=p->getNext()) count++;
		return count;
	}

	Node2 *getEntry(int pos)
	{
		Node2 *p=&org;
		for(int i=-1;i<pos;i++,p=p->getNext())
			if(p==NULL) break;
		return p;
	}

	void *insert(int pos,Node2 *p)
	{
		Node2 *prev=getEntry(pos-1);
		if(prev!=NULL)
			prev->insertNext(p);
	}

	Node2 *remove(int pos)
	{
		Node2 *p=getEntry(pos);
		return p->remove();
	}

};

int main()
{
	dblinkedlist list;

	list.insert(0,new Node2(10));
	list.insert(0,new Node2(20));
	list.insert(1,new Node2(30));
	list.insert(list.size(),new Node2(40));
	
}