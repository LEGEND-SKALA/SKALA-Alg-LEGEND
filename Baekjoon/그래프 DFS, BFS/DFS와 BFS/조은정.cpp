#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

int n, m, v, a, b, vis[1001];
vector<int> nd[1001];
queue<int> q;

void dfs(int u) {
    vis[u] = 1; cout << u << ' ';
    for(int i : nd[u]) if(!vis[i]) dfs(i);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m >> v; while(m--) cin >> a >> b, nd[a].push_back(b), nd[b].push_back(a);
    for(int i = 1; i <= n; ++i) sort(nd[i].begin(), nd[i].end());
    dfs(v); cout << '\n'; memset(vis, 0, sizeof(vis));
    q.push(v); vis[v] = 1; while(q.size()) {
        a = q.front(); q.pop(); cout << a << ' ';
        for(int i : nd[a]) if(!vis[i]) vis[i] = 1, q.push(i);
    }
}