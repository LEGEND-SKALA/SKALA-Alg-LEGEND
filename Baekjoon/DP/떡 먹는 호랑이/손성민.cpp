#include <iostream>
using namespace std;

// 떡 먹는 호랑이 (2502)
// https://www.acmicpc.net/problem/2502
int dp[33][2];
int d, k;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve() {
    cin >> d >> k;
    dp[1][0] = 1; dp[1][1] = 0;
    dp[2][0] = 0; dp[2][1] = 1;

    for (int i = 3; i <= d ;i++) {
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
    for (int i = 1; i <= k; i++) {
        int remainder = k - dp[d][0] * i;
        if (remainder < 0) break;
        if (remainder % dp[d][1] == 0) {
            cout << i << "\n" << remainder / dp[d][1] << "\n";
            break;
        }
    }
    return;
}
int main() {
    fastIO();
    solve();
    return 0;
}
