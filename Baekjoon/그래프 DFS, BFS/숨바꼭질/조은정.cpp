#include <iostream>
#include <queue>
using namespace std;

int N, K, loc, cnt, vis[100010];
queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> N >> K; vis[N] = 1;
    q.push({ N,0 }); while (q.size()) {
        if (q.front().first == K) {
            cout << q.front().second; break;
        }
        loc = q.front().first; cnt = q.front().second + 1; q.pop();
        if (loc - 1 >= 0 && !vis[loc - 1])
            vis[loc - 1] = 1, q.push({ loc - 1,cnt });
        if (loc + 1 <= 100000 && !vis[loc + 1])
            vis[loc + 1] = 1, q.push({ loc + 1,cnt });
        if (loc * 2 <= 100000 && !vis[loc * 2])
            vis[loc * 2] = 1, q.push({ loc * 2,cnt });
    }
}