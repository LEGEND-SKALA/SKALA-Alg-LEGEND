#include <iostream>
using namespace std;

// 1, 2, 3 더하기 4 (15989)
// https://www.acmicpc.net/problem/15989
// DP Alg.
// 시간 복잡도: O(t)
// 공간 복잡도: O(1)
int dp[10001][4];
int t, n, num;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve() {
    // dp[a][b] = a를 만들 때 마지막 수가 b인 경우
    dp[1][1] = 1;   // 1을 만들 때 마지막 수가 1인 경우: (1+1) 
    dp[2][1] = 1; dp[2][2] = 1; // 2를 만들 때 마지막 수가 1인 경우: (1+1), 마지막 수가 2인 경우: (2)
    dp[3][1] = 1; dp[3][2] = 1; dp[3][3] = 1; // 3을 만들 때 마지막 수가 1인 경우: (1+1+1), 2인 경우: (1+2), 3인 경우: (3)

    for(int i=4; i<=10000; i++) {
        dp[i][1] = dp[i-1][1];
        dp[i][2] = dp[i-2][1] + dp[i-2][2];
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3];
    }
    
    for(int i=0; i<t; i++) {
        cin >> n;
        cout << dp[n][1] + dp[n][2] + dp[n][3] << "\n";
    }
    return;
}
int main() {
    fastIO();
    cin >> t;
    solve();
    return 0;
}