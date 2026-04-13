#include<iostream>
#include<vector>
using namespace std;
const int INF = 1e9;
auto Prim(int n,vector<vector<int>> &G)
{
   vector<int> dist(n+1,INF);
   vector<bool> vis(n+1,false);
   dist[1]=0;
   int count=0;
   for(int i=1;i<=n;i++)
   {
      int u=-1;//源点
      int min=INF;
      for(int j=1;j<=n;j++)
      {
         if(!vis[j]&&dist[j]<min)
         {
            min=dist[j];
            u=j;
         }
      }
      if(u==-1) return -1;
      vis[u]=true;
      count=count+min;
      for(int v=1;v<=n;v++)
      {
        if(!vis[v]&&G[u][v]<dist[v]) dist[v]=G[u][v];
      }
    }
   return count;
}
int main() {
    int n, m;
    cout << "请输入图的顶点数和边数：" << endl;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 重边取最小值
        graph[u][v] = min(graph[u][v], w);
        graph[v][u] = min(graph[v][u], w);
    }

    int ans = Prim(n, graph);

    if (ans == -1) {
        cout << "图不连通，无法生成最小生成树" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}