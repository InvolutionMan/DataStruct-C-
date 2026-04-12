#include<iostream>
using namespace std;
const int MAX = 100;
const int INF=1e9; //无穷大，在创建无向图时，用INF表示无边
int n,m;
int adj[MAX][MAX]; //邻接矩阵
bool visited[MAX]; //访问数组标记
auto init(bool weighted=false)//weighted为否为有权图
{
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(weighted) adj[i][j]=INF;
            else adj[i][j]=0;  //表示无边，不连通
        }
    }
        for(int i=1;i<=n;i++) adj[i][i]=0; //自己到自己的距离为0

}
void add_edge(int u=1,int v=1,int w=1,bool undirected=false)
{
    adj[u][v]=w;
    if (undirected)
    {
        adj[v][u]=w;
    }
}
auto print_marrix()
{
    cout << "邻接矩阵：" << endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(adj[i][j]==INF) cout << "INF";
            else cout << adj[i][j]<<" ";
        }
    }
}
//DFS遍历
void DFS(int s)
{
    cout<<s<<" ";
    visited[s]=true; //标记为已访问
    for (int i=1;i<=n;i++)
    {
        if(adj[s][i]!=0&&!visited[i]&&adj[s][i]!=INF)
        {
            DFS(i);
        }
    }
}
auto BFS(int s)
{
    queue<int> q;
    memset(visited,false,sizeof(visited));
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int i=1;i<=n;i++) //遍历u的邻居
        {
            if(!visited[i]&&adj[u][i]!=0&&adj[u][i]!=INF)
            {
                visited[i]=true;
                q.push(i);
            }
        }
    }
}
int main()
{
    cout<<"请输入图的顶点数和边数："<<endl;
    cin>> n >> m;
    bool weighted = false; // 是否带权 
    bool undirected = true; // 是否无向图
    init(weighted);
    for(int i=1;i<m;i++)
    {
        int u, v, w = 1;
        if (weighted) cin >> u >> v >> w;
        else cin >> u >> v;
        add_edge(u, v, w, undirected);
    }
    print_marrix();
    cout<<"深度优先遍历："<<endl;
    memset(visited, false, sizeof(visited));
    DFS(1);
    cout<<"广度优先遍历："<<endl;
    BFS(1);
    return 0;
}
