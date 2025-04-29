#include <iostream>
#include <algorithm>
using namespace std;

// 내려가기 (2096)
// https://www.acmicpc.net/problem/2096
// 시간복잡도: O(n)
// 공간복잡도: O(1)
int n, arr[3];
int maxDP[3], minDP[3];
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve() {
    cin >> n;
    // 한 줄씩 입력받으며 진행
    for(int i=0; i<3; i++) cin >> arr[i];
    maxDP[0] = minDP[0] = arr[0];
    maxDP[1] = minDP[1] = arr[1];
    maxDP[2] = minDP[2] = arr[2];

    // 최댓값을 저장할 DP와 최솟값 저장할 DP 사용
    for(int i=1; i<n; i++) {
        for(int i=0; i<3; i++) cin >> arr[i];
        int tmp = maxDP[1];
        // 가운데는 왼쪽, 가운데, 오른쪽 중 비교
        maxDP[1] = max({maxDP[0], maxDP[1], maxDP[2]}) + arr[1];
        // 왼쪽은 왼쪽과 가운데 비교
        maxDP[0] = max(maxDP[0], tmp) + arr[0];
        // 오른쪽은 오른쪽과 가운데 비교
        maxDP[2] = max(maxDP[2], tmp) + arr[2];

        tmp = minDP[1];
        minDP[1] = min({minDP[0], minDP[1], minDP[2]}) + arr[1];
        minDP[0] = min(minDP[0], tmp) + arr[0];
        minDP[2] = min(minDP[2], tmp) + arr[2];
    }
    
    cout << max({maxDP[0], maxDP[1], maxDP[2]}) << " " << min({minDP[0], minDP[1], minDP[2]}) << "\n";
    return;
}
int main() {
    fastIO();
    solve();
    return 0;
}