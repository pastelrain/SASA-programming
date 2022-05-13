#include<cstdio>
#include<cstring>
#define MAX_STRING 100

class Student
{
    int id;
    char name[MAX_STRING];

public:
    Student(int i=0,char *n="")
    {
        id=i;
        strcpy(name,n);
    }
    void display(){printf("학번:%d 성명:%s\n",id,name);}
};

#define MAX_STACK_SIZE 100

class StudentStack
{
    int top;
    Student data[MAX_STACK_SIZE];
public:
    StudentStack(){top=-1;}

    int push(Student val)
    {
        if(top==MAX_STACK_SIZE-1) return -1;
        data[++top]=val;
        return 0;
    }

    Student pop()
    {
        if(top==-1) printf("스택 공백 에러");
        return data[top--];
    }

    void display()
    {
        printf("[전체 학생의 수 = %2d\n",top+1);
        for(int i=0;i<=top;i++)
            data[i].display();
        printf("\n");
    }
};

int main()
{
    StudentStack stack;

    stack.push({0523,"ass"});
    stack.display();

    stack.push({518,"magic"});
    stack.display();

    stack.pop();
    stack.display();
}