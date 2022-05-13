#include<cstdio>
#define MAX_STACK_SIZE 20

struct ArrayStack
{
    int top;
    int data[MAX_STACK_SIZE];

    ArrayStack(){top=-1;}

    int push(int val)
    {
        if(top==MAX_STACK_SIZE-1) printf("스택 포화 에러");
        else
        {
            top++;
            data[top]=val; //data[++top]=val;
        }
    }

    int pop()
    {
        if(top==-1) return -1;
        else return data[--top];
    }

    void display()
    {
        printf("[스택 항목의 수 = %2d] ==> ",top+1);
        for(int i=0;i<=top;i++) printf("<%2d>",data[i]);
        printf("\n");
    }
};

int main()
{
    ArrayStack stack;
    for(int i=1;i<10;i++) stack.push(i);

    stack.display();
    for(int i=0;i<3;i++) stack.pop();
    stack.display();
}