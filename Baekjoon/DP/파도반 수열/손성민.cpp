#include <iostream>
using namespace std;

// 파도반 수열 (9461)
// https://www.acmicpc.net/problem/9461

typedef long long ll;
ll t, n, dp[101];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve() {
    cin >> t;
    
    dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2;
    // for(int i=4; i<=100; i++) dp[i] = dp[i-2] + dp[i-3];
    for(int i=5; i<=100; i++) dp[i] = dp[i-5] + dp[i-1];
    for(int i=0; i<t; i++) {
        cin >> n;
        cout << dp[n] << "\n";
    }

    return;
}
int main() {
    fastIO();
    solve();
    return 0;
}