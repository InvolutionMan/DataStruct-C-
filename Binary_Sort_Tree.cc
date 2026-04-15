#include<iostream>
using namespace std;
#include <queue>
class Node
{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val)
    {
        data=val;
        left=nullptr;
        right=nullptr;
    }
};
Node*create_BTS(Node*root,int key)
{
    if(root==NULL) return new Node(key);
    if(key<root->data) root->left=create_BTS(root->left,key);
    else root->right=create_BTS(root->right,key);
    return root;
}
Node*search_BTS(Node*root,int key)
{
    if(root==NULL||root->data==key) return root;
    if(key<root->data) return search_BTS(root->left,key);
    else return search_BTS(root->right,key);
};
Node*insert_BTS(Node*root,int key)
{
    if(root==NULL) return new Node(key);
    if(key<root->data) root->left=insert_BTS(root->left,key);
    else root->right=insert_BTS(root->right,key);
    return root;
}
Node*delete_BTS(Node*root,int key)
{
    if(root==NULL) return root;
    if(key<root->data) root->left=delete_BTS(root->left,key);
    else if(key>root->data) root->right=delete_BTS(root->right,key);
    return root;
}


void LevelOrder(Node*root)
{
    queue<Node*> q;
    q.push(root);
    if(root==NULL) return;
    while(!q.empty())
    {
        Node*root=q.front();
        q.pop();
        cout << root->data << " ";
        if(root->left!=NULL) q.push(root->left);
        if(root->right!=NULL) q.push(root->right);
    }
     
}


int main() {
    Node* root = NULL;
    int arr[] = {45, 24, 53, 12, 37, 93};
    int n = sizeof(arr) / sizeof(arr[0]);
    // 构造BST
    for (int i = 0; i < n; i++) {
        root = create_BTS(root, arr[i]);
    }
    // 输出
    cout << "层序遍历：";
    LevelOrder(root);
    cout << endl;
// 查找
    Node*res=search_BTS(root,37);
    if(res!=NULL)
    cout<<"找到37"<<endl;
    else
    cout<<"未找到37"<<endl;
    //插入

    Node*res1=insert_BTS(root,37);
    if(res1!=NULL)
    {   cout<<"插入成功"<<endl;
        cout<<"层序遍历为：";
        LevelOrder(root);
        cout<<endl;
    }
    else
    cout<<"插入失败"<<endl;
    //删除
    Node*res2=delete_BTS(root,37);
    if(res2!=NULL)
    { 
        cout<<"删除成功"<<endl;
        cout<<"层序遍历为：";
        LevelOrder(root);
        cout<<endl;
    }
    else
    cout<<"删除失败"<<endl;
}