#include <iostream>
using namespace std;

struct Edge {
    int u, v, w;//开始，结束，权
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

int fa[100005];

int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
    int n, m;
    cin >> n >> m; 
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) 
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    sort(edges.begin(), edges.end());
    for (int i = 1; i <= n; i++) fa[i] = i; //初始化并查集
    int ans = 0, cnt = 0;
    for (auto &e : edges)  //枚举边
    {
        int fu = find(e.u), fv = find(e.v);//找到两个端点的根
        if (fu != fv) 
        {
            fa[fu] = fv; //合并两个集合
            ans += e.w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }

    if (cnt != n - 1) cout << -1 << endl; //判断是否连通
    else cout << ans << endl;

    return 0;
}