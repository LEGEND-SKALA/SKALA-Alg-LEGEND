#include <iostream>
#include <algorithm>
using namespace std;

// 포도주 시식 (2156)
// https://www.acmicpc.net/problem/2156
// 시간 복잡도: O(n)
// 공간 복잡도: O(1)
int n, arr[10001], dp[10001];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    // 경우의 수 (i=3부터)
    // 1. i-3까지의 최댓값 + i-1번 + i번
    // 2. i-2까지의 최댓값 + i번
    // 3. i-1까지의 최댓값 (왜 i번은 확인하지 않는가? => i번째를 포함하는게 꼭 최댓값이 아닐 수도 있음)
    for(int i=3; i<=n; i++) {
        dp[i] = max(max(dp[i-3] + arr[i-1] + arr[i], dp[i-2] + arr[i]), dp[i-1]);
    }
    cout << dp[n] << "\n";
    return;
}
int main() {
    fastIO();
    solve();
    return 0;
}