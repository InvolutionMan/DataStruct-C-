#include<iostream>
using namespace std;
//顺序存储/数组存储
class ArrayBinaryTree
{
private:
    vector<char> tree;
public:
    ArrayBinaryTree(vector<char> t)
    {
        tree=t;
    }
    void preorder(int i)//i就是当前正在访问的节点在数组中的下标
    {
        if(i>=tree.size()||tree[i]=='#') return; //'#'判空节点
        cout << tree[i] << " ";
        preorder(2 * i + 1);
        preorder(2 * i + 2);
    }
    void inorder(int i)
    {
        if(i>=tree.size()||tree[i]=='#') return;
        inorder(2 * i + 1);
        cout << tree[i] << " ";
        inorder(2 * i + 2);
    }
    void postorder(int i)
    {
        if(i>=tree.size()||tree[i]=='#') return;
        postorder(2 * i + 1);
        postorder(2 * i + 2);
        cout << tree[i] << " ";
    }
};



//链式存储
struct treeList
{
    char val;
    treeList*left;
    treeList*right;
    treeList(char x) 
    {
        val = x;
        left = NULL;
        right = NULL;
    }
    void preorderList(treeList*t)
    {
        if(t!=NULL)
        {
            cout << t->val << " ";
            preorderList(t->left);
            preorderList(t->right);
        }
        return;
    }
    void inorderList(treeList*t)
    {
        if(t!=NULL)
        {
            inorderList(t->left);
            cout << t->val << " ";
            inorderList(t->right);

        }
         return;
    }
    void postorderList(treeList*t)
    {
        if(t!=NULL)
        {
            postorderList(t->left);
            postorderList(t->right);
            cout << t->val << " ";
        }
        return;
    }
};
//层次遍历
void LevelOrder(treeList*t)
{
    queue<treeList*> q;
    q.push(t);
    if(t==NULL) return;
    while(!q.empty())
    {
        treeList*t=q.front();
        q.pop();
        cout << t->val << " ";
        if(t->left!=NULL) q.push(t->left);
        if(t->right!=NULL) q.push(t->right);
    }
     
}



int main()
{//----------------------遍历--------------------------
    //数组
    vector<char> tree={'a','b','c','d','e','f','g','h','i','j'};
    ArrayBinaryTree t(tree);
    cout << "数组方式前序遍历: ";
    t.preorder(0);
    cout<<"\n";
    cout << "数组方式中序遍历: ";
    t.inorder(0);
    cout<<"\n";
    cout << "数组方式后序遍历: ";
    t.postorder(0);
    cout << endl;
    //链式
    treeList*A=new treeList('a');
    treeList*B=new treeList('b');
    treeList*C=new treeList('c');
    treeList*D=new treeList('d');
    A->left=B;
    A->right=C;
    B->left=D;
    cout << "链表方式的前序遍历: ";
    A->preorderList(A);
    cout<<"\n";
    cout << "链表方式的中序遍历: ";
    A->inorderList(A);
    cout<<"\n";
    cout << "链表方式的后序遍历: ";
    A->postorderList(A);
    cout<<"\n";
    cout << endl;
    cout << "层次遍历: ";
    LevelOrder(A);
    cout << endl;
}

