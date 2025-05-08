#include <iostream>
using namespace std;

int n, q, l, tmp, cnt, sz;
pair<int, int> p[4100];
int a[70][70], vis[70][70], d[4] {-1, 1, 0, 0};

void dfs(int u, int v) {
    vis[u][v] = 1; ++tmp;
    for(int i = 0; i < 4; ++i) {
        int nu = u + d[i], nv = v + d[3 - i];
        if(nu < 0 || nu >= n || nv < 0 || nv >= n || !a[nu][nv] || vis[nu][nv]) continue;
        dfs(nu, nv);
    }
}

void sol(int u, int v, int sz) {
    if(sz < 2) return;
    for(int i = 1; i < sz - 1; ++i)
        tmp = a[u][v + i], a[u][v + i] = a[u + sz - 1 - i][v], a[u + sz - 1 - i][v] = tmp;
    for(int i = 1; i < sz - 1; ++i)
        tmp = a[u + i][v], a[u + i][v] = a[u + sz - 1 - i][v + sz - 1], a[u + sz - 1 - i][v + sz - 1] = tmp;
    for(int i = 1; i < sz - 1; ++i)
        tmp = a[u + i][v], a[u + i][v] = a[u + sz - 1][v + i], a[u + sz - 1][v + i] = tmp;
    tmp = a[u][v]; a[u][v] = a[u + sz - 1][v]; a[u + sz - 1][v] = a[u + sz - 1][v + sz - 1]; a[u + sz - 1][v + sz - 1] = a[u][v + sz - 1]; a[u][v + sz - 1] = tmp;
    sol(u + 1, v + 1, sz - 2);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> q; n = (1 << n);
    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) cin >> a[i][j];
    while(q--) {
        cin >> l; l = (1 << l);
        for(int i = 0; i < n; i += l) for(int j = 0; j < n; j += l) sol(i, j, l);
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
            cnt = 0;
            for(int k = 0; k < 4; ++k) {
                int ni = i + d[k], nj = j + d[3 - k];
                if(ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                cnt += (a[ni][nj] != 0);
            }
            if(cnt < 3 && a[i][j]) p[sz++] = {i, j};
        }
        while(sz) --a[p[sz - 1].first][p[sz - 1].second], --sz;
    }
    cnt = sz = 0; for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
        cnt += a[i][j];
        if(!vis[i][j] && a[i][j]) tmp = 0, dfs(i, j), sz = (sz < tmp ? tmp : sz);
    }
    cout << cnt << '\n' << sz;
}