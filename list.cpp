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
Node *createListTail(int n)//尾插创建链表
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
 Node*createListHead(int n)//头插创建链表
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
Node*findNodeByIndex(Node*head,int index)//按索引查找节点
{
    if(index<0) return nullptr;
    int a=0;
    Node*cur=head;
    while(cur!=NULL )
    {
        if(a==index)
        {
            return cur;
        }
        cur=cur->next;
        a++;
    }
    return nullptr;
}
Node*insertNodeHead(Node*head,int val)//从头插入
{
    Node*newNode=new Node(val);
    newNode->next=head;
    return newNode;
}
Node*insertNodeTail(Node*head,int val)//从尾插入
{
    Node*newNode=new Node(val);
    if(head==NULL) return newNode;
    Node*cur=head;
    while(cur->next!=NULL)
    {
        cur=cur->next;

    }
    cur->next=newNode;
    return head;
}
Node*insertNode(Node*head,int index,int val)//插入节点
{
    if(index<=1) return insertNodeHead(head,val);
    Node*cur=head;
    int a=1;
    while(cur!=nullptr&&a<index-1)
    {
        cur=cur->next;
        a++;
    }
    if(cur==nullptr) return head;
    Node*newNode=new Node(val);
    newNode->next=cur->next;
    cur->next=newNode;
    return head;

}

int main()
{
    int n;
    cin>>n;
    Node*head=createListTail(n);
    printList(head);
    cout<<"长度是"<<length(head)<<endl;
    int data1;
    cout<<"请输入查找的数"<<endl;
    cin>>data1;
    Node*result=findNode(head,data1);
    if (result) {
        cout << "找到: " << result->data << endl;
    } else {
        cout << "未找到" << endl;
    }
    int data2;
    cout<<"请输入查找的索引"<<endl;
    cin>>data2;
    Node*result2=findNodeByIndex(head,data2);
    if (result2) {
        cout << "找到: " << result2->data << endl;
        cout<<"索引是"<<result2->data<<endl;

    } else {
        cout << "未找到" << endl;
    }
}