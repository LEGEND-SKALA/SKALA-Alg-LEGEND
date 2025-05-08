#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;

int n, k, w, u, v, dst[200015];
priority_queue<PI, vector<PI>, greater<PI>> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k; fill(dst, dst + 200015, 2e9);
    dst[n] = 0; q.push({0, n});
    while (q.size()) {
        w = q.top().first, u = q.top().second; q.pop();
        if (u == k) {
            cout << w; break;
        }
        for (int i = 0; i < 3; ++i) {
            v = (i == 1? u + 1 : i? u * 2 : u - 1);
            if (0 <= v && v < 200010) {
                if (i == 2 && dst[v] > w) dst[v] = w, q.push({w, v});
                else if (i != 2 && dst[v] > w + 1) dst[v] = w + 1, q.push({w + 1, v});
            }
        }
    }
}