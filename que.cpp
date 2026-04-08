#include<iostream>
using namespace std;
#define MAX 100

class Que
{
private:
    int data[MAX];
    int front,rear;

public:
    Que()
    {
        front=rear=0;

    }
    auto push(int x)
    {
        if(rear==MAX)
        {
            cout<<"Queue is full"<<endl;
            return -1;
        }
        data[rear++]=x;
    }
    auto pop()
    {
        if(front==rear) 
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        front++;
    }
    auto printque()
    {
        for(int i=front;i<rear;i++)
        {
            cout<<data[i]<<" ";
        }
    }

};

class CircularQue
{
private:
    int data[MAX];
    int front,rear;
public:
    CircularQue()
    {
        front=rear=0;
    }
    bool isEmpty()
    {
        return (front==rear);
    }
    bool isFull()
    {
        return ((rear+1)%MAX==front);
    }
    auto push(int x)
    {
        if(isFull())
        {
            cout<<"Queue is full"<<endl;
            return -1;
        }
        data[rear]=x;
        rear=(rear+1)%MAX;//回到头指针
    }
    auto pop()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        front=(front+1)%MAX;//回到头指针
    }

    auto printCircleque()
    {
        for(int i=front;i<rear;i++)
        {
            cout<<data[i]<<" ";
        }
    }
};
int main()
{
    Que q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.printque();
    cout<<'\n';
    CircularQue cq;
    cq.push(1);
    cq.push(2);
    cq.push(3);
    cq.push(4);
    cq.push(5);
    cq.push(6);
    cq.pop();
    cq.printCircleque();
}