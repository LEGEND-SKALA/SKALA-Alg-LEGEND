#include <iostream>
#include <algorithm>
using namespace std;

int n, k, w, v, d[100002];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k; while(n--) {
        cin >> w >> v;
        for(int i = k; i >= w; --i) d[i] = max(d[i], v + d[i - w]);
    }
    cout << *max_element(d, d + k + 1);
}
