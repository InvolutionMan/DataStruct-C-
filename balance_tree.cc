#include<iostream>
#include <queue>
#include <algorithm>
using namespace std;
class AVL_Tree
{
public:
    struct Node
    {
        int val;
        int height;
        Node *left;
        Node *right;
        Node(int x):val(x),height(1),left(nullptr),right(nullptr){}
    };
    Node *root=nullptr;
    int getHeight(Node *node)
    {
        if(node!=nullptr) return node->height;
        else return 0;
    }
    int getbalance(Node*node)
    {
        if(node!=nullptr) return getHeight(node->left)-getHeight(node->right);
        else return 0;
    }
    void updateheight(Node *node)//更新后高度
    {
        if(node!=nullptr) node->height=1+max(getHeight(node->left),getHeight(node->right));
    }   
    Node*rightRotate(Node*y)
    {
        Node*x=y->left;
        Node*T2=x->right; //y 为失衡点，x 为左孩子，T2 为子树
        x->right=y;
        y->left=T2;
        updateheight(y);
        updateheight(x);
        return x;
    }
    Node*leftRotate(Node*x)
    {
        Node*y=x->right;
        Node*T2=y->left;
        y->left=x;
        x->right=T2;
        updateheight(x);
        updateheight(y);
        return y;
    }
    Node*insert(Node*node,int key)
    {
        if(node==nullptr) return new Node(key);
        if(key<node->val) node->left=insert(node->left,key);
        else if(key>node->val) node->right=insert(node->right,key);
        else return node;//不允许重复
        updateheight(node);
        int balance=getbalance(node);
        //LL
        if(balance>1&&key<node->left->val) return rightRotate(node);
        //RR
        if(balance<-1&&key>node->right->val) return leftRotate(node);
        //RL
        if(balance<-1&&key<node->right->val)
        {
            node->right=rightRotate(node->right);
            return leftRotate(node);
        }
        //LR
        if(balance>1&&key>node->left->val)
        {
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
        return node;
    }
    Node*minValueNode(Node*node)
    {
        Node*current=node;
        while(current->left!=nullptr) current=current->left;
        return current;
    }
    Node*remove(Node*node,int key)
    {
        if(node==nullptr) return node;
        if(key<node->val)
        {
            node->left=remove(node->left,key);
        }else if(key>node->val)
        {
            node->right=remove(node->right,key);
        }else 
        {
            if(!node->left||!node->right) 
            {
                Node*temp=node->left?node->left:node->right;
                if(!temp)
                {
                    temp=node;
                    node=nullptr;
                }else *node=*temp;
                delete temp;

            } else 
            {
                Node*temp=minValueNode(node->right);
                node->val=temp->val;
                node->right=remove(node->right,temp->val);
            }
        }
        if(!node) return node;
        updateheight(node);
        int balance=getbalance(node);
        //LL
        if(balance>1&&getbalance(node->left)>=0) return rightRotate(node);
        //RR
        if(balance<-1&&getbalance(node->right)<=0) return leftRotate(node);
        //RL
        if(balance<-1&&getbalance(node->right)>0) 
        {
            node->right=rightRotate(node->right);
            return leftRotate(node);
        } 
        //LR
        if(balance>1&&getbalance(node->left)<0)
        {
            node->left=leftRotate(node->left);
            return rightRotate(node);
        }
        return node;
    }
        bool search(Node*node,int key)
        {
            if(node==nullptr) return false;
            if(node->val==key) return true;
            if(key<node->val) return search(node->left,key);
            return search(node->right,key);
        }
        void LevelOrder(Node*root)
        {
            if(root==NULL) return;
            queue<Node*> q;
            q.push(root);
            while(!q.empty())
            {
                Node*root=q.front();
                q.pop();
                cout << root->val << " ";
                if(root->left!=NULL) q.push(root->left);
                if(root->right!=NULL) q.push(root->right);
            }
     
        }
        void destroy(Node* node)
        {
            if (!node) return;
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
        public:
    ~AVL_Tree() {
        destroy(root);
    }

    void insert(int key) {
        root = insert(root, key);
    }

    void remove(int key) {
        root = remove(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void LevelOrder() {
        LevelOrder(root);
        cout << endl;
    }
};
int main() {
    AVL_Tree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << " 层序遍历：";
    tree.LevelOrder();

    cout << "查找 25: " << (tree.search(25) ? "存在" : "不存在") << endl;
    cout << "查找 15: " << (tree.search(15) ? "存在" : "不存在") << endl;

    tree.remove(30);
    cout << "删除 30 后层序遍历：";
    tree.LevelOrder();

    return 0;
}
