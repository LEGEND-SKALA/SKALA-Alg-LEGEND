#include <iostream>
#include <algorithm>
using namespace std;

// 동전 문제 (1398)
// https://www.acmicpc.net/problem/1398

/*
- (1, 10, 25), (100, 1000, 2500), (10000, 100000, 250000) ...
- 100으로 나눴을 때의 나머지 값에 대한 갯수를 재귀적으로 구해준다면?
*/
// 시간복잡도: O(1)
// 공간복잡도: O(1)
typedef long long ll;
ll t, p, ret, dp[101];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 1~99 사이 값일 때 필요한 동전 갯수를 구하기
void init() {
    for(int i=1; i<100; i++) {
        if(i >= 25) {
            dp[i] = min(dp[i-25]+1, dp[i-10]+1);
            dp[i] = min(dp[i], dp[i-1] + 1);
        } else if(i >= 10) {
            dp[i] = min(dp[i-10]+1, dp[i-1] + 1);
        } else dp[i] = dp[i-1] + 1;
    }
    return;
}
// 값을 100으로 나눴을 때의 나머지 값을 이용해 갯수 더하기
void solve() {
    while(p > 0) {
        ll num = p % 100;
        ret += dp[num];
        p /= 100;
    }
    cout << ret << "\n";
    ret = 0;
}
int main() {
    fastIO();
    cin >> t;
    init();
    for(int i=0; i<t; i++) {
        cin >> p;
        solve();
    }
    return 0;
}