#include <iostream>
#include <algorithm>
using namespace std;

// 평범한 배낭 (12865)
// https://www.acmicpc.net/problem/12865
// DP Alg.
// 시간복잡도: O(n * k)
// 공간복잡도: O(1)
int n, k, w, v, dp[100001];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve() {
    cin >> n >> k;
    for(int i=0; i<n; i++) {    // n개의 물건
        cin >> w >> v;
        for(int j=k; j>=w; j--) {   // 최대 무게 k부터 현재 물건 무게 w까지 역순 탐색
            dp[j] = max(dp[j], dp[j-w] + v);
        }
    }
    cout << dp[k] << "\n";
    return;
}
int main() {
    fastIO();
    solve();
    return 0;
}