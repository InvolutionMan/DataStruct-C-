#include<iostream>
using namespace std;
class Btree
{
    public:
    vector<int> keys; //关键字
    vector<Btree> children; //子节点
    bool leaf; //是否有叶子节点
    int t; //最小度数
    Btree(int _t,bool _leaf)
    {
        t = _t;//最小度数
        leaf = _leaf;//是否是叶子节点
    }

    void inorder() //中序遍历
    {
        int i; //索引
        for(i = 0;i < keys.size();i++) //key.size 表示当前节点存放关键字的数目
        {
            if(!leaf)
            children[i].inorder();
            cout<<keys[i]<<" ";
        }
        if(!leaf)
        children[i].inorder();
    }
    Btree*search(int key)
    {
        int i = 0;
        while(i < keys.size() && key > keys[i]) i++;
        if(i< keys.size() && keys[i] == key) return this;
        if(leaf) return nullptr;
        return children[i].search(key);
    }
    void insertNonFull(int k);
    void splitChild(int i, Btree* y);
};
