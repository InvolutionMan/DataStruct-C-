#include<iostream>
using namespace std;
//并查集
class USD
{
    private:
    vector<int> parent;
    vector<int> rank;
    public:
    USD(int n)
    {
        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    auto find(int x)
    {
        if(parent[x]==x) return x;
        else return parent[x]=find(parent[x]); //路径压缩,直接连接到根节点，下次查找为O(1)
    }
    auto Union(int x,int y)
    {
        int rootx=find(x);
        int rooty=find(y);
        if(rank[rootx]<rank[rooty]) parent[rootx]=rooty;
        else if(rank[rootx]>rank[rooty]) parent[rooty]=rootx;
        else{parent[rootx]=rooty; rank[rooty]+=1;} //rank[rootx]++ 两个高度相等的树合并会使树的高度+1
    }
};