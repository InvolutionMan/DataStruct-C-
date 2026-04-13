#include<iostream>
using namespace std;

const int N=1000;
vector<int> adj[N];
int indegree[N];
int n,m; //点数、边数

void topological_sort()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0;// 记录排序个数
    while (!q.empty())
    {
       int u=q.front();
       q.pop();
       cout<<u<<" ";  
       cnt++;
       for (int v:adj[u])
       {
          indegree[v]--;
          if(indegree[v]==0) q.push(v);
       }
    }
    if(cnt!=n) cout<<"有环，无法排序"<<endl;
}

int main() {
    cin >> n >> m;

    // 输入边
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;  // u -> v
        adj[u].push_back(v);
        indegree[v]++;
    }

    topological_sort();

    return 0;
}