#include <iostream>
#include <vector>
using namespace std;
void DFS(int node,vector<vector<int>> &graph, vector<bool>& visited)//vector<vector<int>>表示二维，vector<vector<int>> &graph表示拷贝数组
{
    cout<<node<<" ";
    visited[node] = true;
    for(int neighbor : graph[node])//遍历当前节点的相邻节点
    {
        if (!visited[neighbor]) 
        {
            DFS(neighbor, graph, visited);
        }
    }
}
void BFS(int start, vector<vector<int>>& graph)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();
        cout << node << " ";
        for(int neighbor : graph[node])
        {
            if (!visited[neighbor]) 
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}
vector<int>BFS_MIN_DISTANCE(int start,int end, vector<vector<int>>& graph)
{
    vector<int> parent(graph.size(), -1);//记录路径
    vector<bool> visited(graph.size(), false); //判断是否访问过，graph.size()表示节点个数
    queue<int> q;  //创建队列
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(node==end) break;
        for(int neighbor : graph[node])
        {
            if(!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor]=true;
                parent[neighbor] = node;
            }
        }
    }
    if (!visited[end]) return {};//不可达
    //获取路径
    vector<int> path;
    for(int v=end;v!=-1;v=parent[v])
    {
        path.push_back(v);

    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    int n = 4; // 4个节点
    vector<vector<int>> graph(n);

    // 无向图加边（双向）
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[0].push_back(2);
    graph[2].push_back(0);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(3);
    graph[3].push_back(2);

    // 输出邻接表
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int v : graph[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
    cout << "\nDFS遍历：" << endl;
    vector<bool> visited(n, false);
    DFS(0, graph, visited);

    // ---------- BFS ----------
    cout << "\n\nBFS遍历：" << endl;
    BFS(0, graph);

    cout << "\n\n最短路径 (0 -> 3):" << endl;
    vector<int> path = BFS_MIN_DISTANCE(0, 3, graph);

    for (int x : path)
    {
        cout << x << " ";
    }
        cout << endl;
    
    return 0;
}