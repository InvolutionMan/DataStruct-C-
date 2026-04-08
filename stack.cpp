#include<iostream>
using namespace std;
#define MAX 10
class Stack
{
private:
    int data[MAX];
    int top;
public:
    Stack()
    {
        top=-1;
    }
    auto push(int x)
    {
        if(top==MAX-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        data[++top]=x;
    }
    auto pop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return; 
        }
        top--;
    }
    auto gettop()
    {
        if(top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        return data[top];

    }
    auto printall()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<data[i]<<" ";
        }
    }

};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.printall();
    cout<<"\n"<<endl;
    s.pop();
    s.printall();
}