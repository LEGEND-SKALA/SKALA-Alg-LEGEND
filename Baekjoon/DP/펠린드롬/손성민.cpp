#include <iostream>
using namespace std;

// 펠린드롬? (10942)
// https://www.acmicpc.net/problem/10942
// DP Alg.
// 시간복잡도: O(n)
// 공간복잡도: O(1)
int n, m, s, e;
int dp[2001][2001], arr[2001];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        dp[i][i] = 1;   // 회문 구간이 1이면 무조건 회문
        if(i != 1 && arr[i-1] == arr[i]) dp[i-1][i] = 1;    //회문 구간이 2인경우
    }
    // 회문 구간이 3이상인 경우
    for(int i=n-2; i>=1; i--) {
        for(int j=i+2; j<=n; j++) {
            dp[i][j] = (arr[i]==arr[j] && dp[i+1][j-1]);    //(i,j)이 회문이려면 (i+1, j-1)도 회문이여야 함
        }
    }
    cin >> m;
    for(int i=0; i<m; i++) {
        cin >> s >> e;
        cout << dp[s][e] << "\n";
    }
    return;
}
int main() {
    fastIO();
    solve();
    return 0;
}