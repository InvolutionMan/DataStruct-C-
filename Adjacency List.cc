#include <iostream>
#include <vector>
using namespace std;
void DFS(int node,vector<vector<int>> &graph, vector<bool>& visited)
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

    return 0;
}