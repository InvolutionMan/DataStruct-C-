#include<iostream>
using namespace std;

const int MAXv=100;//最大顶点数
const int INF=0x3f3f3f3f;
struct MGraph
{
    int vexNUm; //顶点数
    int arcNum[MAXv][MAXv]; //邻接矩阵
};
int minDist(MGraph G,int dist[],bool visted[])
{ 
    int min=INF;
    int index=-1;
    for(int i=0;i<G.vexNUm;i++)
    {
        if(!visted[i]&&dist[i]<min)
        {
            min=dist[i];
            index=i;
        }
    }
    return index;
}
void Dijkstra(MGraph G,int src)
{
    int dist[MAXv];
    bool visted[MAXv];
    int parent[MAXv];
    for(int i=0;i<G.vexNUm;i++)
    {
        dist[i]=INF;
        visted[i]=false;
        parent[i]=-1;
    }
    dist[src]=0;
    for(int i=1;i<G.vexNUm;i++)
    {
        int u=minDist(G,dist,visted); //找到距离源点最近的顶点u
        if (u==-1)  break;
        visted[u]=true;
        for(int v=0;v<G.vexNUm;v++)
        {
            if(visted[v]==false&&
                G.arcNum[u][v]!=INF&& //存在边
                dist[u]+G.arcNum[u][v]<dist[v])
                {
                    dist[v]=dist[u]+G.arcNum[u][v]; //更新距离
                    parent[v]=u; //更新前驱节点
                }
        }
    }
    // 输出最短距离
    cout << "源点 " << src << " 到各点的最短距离：" << endl;
     for (int i = 0; i < G.vexNUm; i++) {
        if (dist[i] == INF) cout << "到 " << i << " : INF" << endl;
        else cout << "到 " << i << " : " << dist[i] << endl;
    }
     // 输出前驱数组
    cout << "\nparent 数组：" << endl;
    for (int i = 0; i < G.vexNUm; i++) {
        cout << "parent[" << i << "] = " << parent[i] << endl;
    }
}
int main() {
    MGraph G;
    G.vexNUm = 5;

    // 初始化邻接矩阵
    for (int i = 0; i < G.vexNUm; i++) {
        for (int j = 0; j < G.vexNUm; j++) {
            if (i == j) G.arcNum[i][j] = 0;
            else G.arcNum[i][j] = INF;
        }
    }

    // 加边
    G.arcNum[0][1] = 10;
    G.arcNum[0][3] = 5;
    G.arcNum[1][2] = 1;
    G.arcNum[1][3] = 2;
    G.arcNum[2][4] = 4;
    G.arcNum[3][1] = 3;
    G.arcNum[3][2] = 9;
    G.arcNum[3][4] = 2;
    G.arcNum[4][0] = 7;
    G.arcNum[4][2] = 6;

    Dijkstra(G, 0);

    return 0;
}








