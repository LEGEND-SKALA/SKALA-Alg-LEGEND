#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 통학버스 (2513)
// https://www.acmicpc.net/problem/2513
// Greedy Alg.
// 시간복잡도: O()

/*
- 직선 도로에 여러 아파트 단지
- 어느 한 지점에 학교 신설
- 통학버스를 이용해서만 학교를 다닐 수 있고, 버스는 한 대, 정원이 존재
- 모든 학생을 등교시키는데 필요한 통학버스의 총 이동 거리의 최솟값 구하기
*/
int n, k, s, loc, st, ret;
vector<pair<int,int>> vLeft, vRight;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input() {
    cin >> n >> k >> s;
    for(int i=0; i<n; i++) {
        cin >> loc >> st;
        if(loc < s) vLeft.push_back({loc, st});
        else vRight.push_back({loc, st});
    }
    // 멀리서부터 확인할거기 때문에 왼쪽은 오름차순, 오른쪽은 내림차순 정렬
    sort(vLeft.begin(), vLeft.end());
    sort(vRight.begin(), vRight.end(), greater<pair<int,int>>());
    return;
}
void solve(vector<pair<int,int>> &v) {
    int i = 0;
    int n = v.size();
    while(i < n) {
        int curLoc = v[i].first;
        int sum = 0;
        int j = i;
        // i부터 시작해서 버스 정원만큼 태움
        while(j < n && sum + v[j].second <= k) {
            sum += v[j].second;
            j++;
        }
        // 태울만큼 태우고, 정원을 더 채움
        if(j < n && sum < k) {
            int diff = k - sum;
            sum += diff;
            v[j].second -= diff;
        }
        // 거리 계산
        ret += 2 * abs(curLoc - s);
        i = j;
    }
}
int main() {
    fastIO();
    input();
    solve(vLeft);
    solve(vRight);
    cout << ret << "\n";
    return 0;
}