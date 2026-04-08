#include <iostream>
using namespace std;

// 1. 定义节点
struct Node
{
    int data;
    Node*next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};
Node *createListTail(int n)//尾插
    {
        if(n<=0) return NULL;
        int x;
        cin>>x;
        Node*head=new Node(x);
        Node*tail=head;
        for(int i=1;i<n;i++)
        {
            cin>>x;
            Node*newNode=new Node(x);
            tail->next=newNode;
            tail=newNode;
        }
        return head;
    }
 Node*createListHead(int n)//头插
    {
        Node*head=NULL;
        for (int i=1;i<n;i++)
        {
            int x;
            cin>>x;
            Node*newNode=new Node(x);
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
    auto length(Node*head)//长度
    {
        int len=0;
        while(head!=NULL)
        {
            head=head->next;
            len++;
        }
        return len;
    }
void printList(Node*head)//打印链表
    {
        Node*temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
auto reverseList(Node*head)//反转链表
    {
        Node*pre=NULL;
        Node*cur=head;
        while(cur!=NULL)
        {
            Node*next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
Node*findNode(Node*head,int target)//按值查找节点
    {
        Node*cur=head;
        while(cur!=NULL)
        {
            if(cur->data==target)
            {
                return cur;            
            }
            cur=cur->next;
        }
        return nullptr;
    }
int main()
{
    int n;
    cin>>n;
    Node*head=createListTail(n);
    printList(head);
    cout<<"长度是"<<length(head)<<endl;
    Node*result=findNode(head,5);
    if (result) {
        cout << "找到: " << result->data << endl;
    } else {
        cout << "未找到" << endl;
    }
}