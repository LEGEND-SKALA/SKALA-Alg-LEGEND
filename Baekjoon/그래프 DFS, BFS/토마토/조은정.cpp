#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int M, N, an, x, y, nx, ny;
int mp[1010][1010], vis[1010][1010], d[4]{-1, 1, 0, 0};
queue<pair<int, int>> q;

int main() {
    cin >> M >> N; memset(vis, -1, sizeof vis);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        cin >> mp[i][j];
        if (mp[i][j] == 1) q.push({ i,j }), vis[i][j] = 0;
    }
    while (q.size()) {
        x = q.front().second; y = q.front().first;
        for (int i = 0; i < 4; ++i) {
            nx = x + d[i]; ny = y + d[3 - i];
            if (nx < 0 || nx >= M || ny < 0 || ny >= N || mp[ny][nx] == -1 || vis[ny][nx] != -1) continue;
            vis[ny][nx] = vis[y][x] + 1; q.push({ ny,nx });
        }
        q.pop();
    }
    an = 0; for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
        if (mp[i][j] != -1 && vis[i][j] == -1) {
            cout << -1; return 0;
        }
        if (vis[i][j] > an) an = vis[i][j];
    }
    cout << an;
}