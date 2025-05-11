#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

// DFS와 BFS (1260)
// https://www.acmicpc.net/problem/1260
/*
- Graph DFS/BFS Alg.
- 시간복잡도: O(mlogm)
- 공간복잡도: O(1)
*/
int n, m, v, from, to, visited[1001];
vector<int> arr[1001];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> m >> v;
    for(int i=0; i<m; i++) {
        cin >> from >> to;
        arr[from].push_back(to);
        arr[to].push_back(from);
    }
    // 정점 번호가 작은 것 부터 탐색하기 위한 정렬
    for(int i=1; i<=n; i++) sort(arr[i].begin(), arr[i].end());
    return;
}
// 깊이 우선 탐색
void dfs(int cur) {
    visited[cur] = 1;
    cout << cur << " ";
    for(int next : arr[cur]) {
        if(!visited[next]) dfs(next);
    }
    return;
}
// 너비 우선 탐색
void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    visited[cur] = 1;
    while(!q.empty()) {
        int now = q.front(); q.pop();
        cout << now << " ";
        for(int next : arr[now]) {
            if(!visited[next]) {
                q.push(next);
                visited[next] = 1;
            }
        }
    }
    cout << "\n";
    return;
}
int main() {
    fastIO();
    input();
    dfs(v);
    cout << "\n";
    memset(visited, 0, sizeof(visited));
    bfs(v);
    return 0;
}