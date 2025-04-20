#include <iostream>
#include <algorithm>
using namespace std;

// 투자의 귀재 배주형 (19947)
// https://www.acmicpc.net/problem/19947
// DP Alg.
// 시간복잡도: O(1)
// 공간복잡도: O(1)
int h, y, dp[11];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve() {
    cin >> h >> y;
    // 초기값 설정
    dp[0] = h;
    dp[1] = h + h * 5 / 100;
    dp[2] = dp[1] + dp[1] * 5 / 100;
    for(int i=3; i<=10; i++) {
        dp[i] = dp[i-1] + dp[i-1] * 5 / 100;    // A
        if((i >= 3)) dp[i] = max(dp[i], (dp[i-3] + dp[i-3] * 20 / 100));    // B
        if((i >= 5)) dp[i] = max(dp[i], (dp[i-5] + dp[i-5] * 35 / 100));    // C
    }
    cout << dp[y] << "\n";
    return;
}
int main() {
    fastIO();
    solve();
    return 0;
}