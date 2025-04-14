#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 공주님의 정원 (2457)
// https://www.acmicpc.net/problem/2457

/*
- N개의 꽃, 꽃은 모두 같은 해에 피고 같은 해에 짐
- 꽃은 피는 날과 지는 날이 정해져 있음
- 4,6,9,11 (30)
- 1,3,5,7,8,10,12 (31)
- 2 (28)
- 공주가 가장 좋아하는 계절인 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어 있도록 한다.
- 정원이 넓지 않으므로 정원에 심는 꽃들의 수를 가능한 적게 한다.
- N개의 꽃들 중에서 두 조건을 만족하는
- 3월1일부터 11월30일까지 매일 꽃이 한 가지 이상 피어 있도록 꽃들을 선택
- 선택한 꽃들의 최소 갯수를 출력하는 프로그램 작성
*/
int n, ret, minVal = 1e9, maxVal;
int fromMonth, fromDay, toMonth, toDay;
vector<pair<int, int>> v;
void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int returnDay(int month, int day) {
    int monthDays[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    return day + monthDays[month];
}
void input() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> fromMonth >> fromDay >> toMonth >> toDay;
        int from = returnDay(fromMonth, fromDay);
        int to = returnDay(toMonth, toDay);
        if(from < minVal) minVal = from;
        if(to > maxVal) maxVal = to;
        v.push_back({from, to});
    }
    return;
}
void solve() {
    int f, t;
    f = returnDay(3, 1); t = returnDay(11, 30);

    // 조건1을 만족하지 않으면
    if(minVal > f || maxVal <= t) {
        cout << 0 << "\n";
        return;
    }
    // 피는 날짜 기준으로 오름차순 정렬
    sort(v.begin(), v.end());

    // 조건에 주어진 날짜 기준으로 탐색
    int idx = 0;
    while(f <= t) {
        int nt = f;
        // 꽃이 피는 시간이 기준시간보다 작거나 같고, 지는 시간이 기준시간보다 클 때
        for(int i=idx; i<n; i++) {
            if(v[i].first <= f && v[i].second > nt) {
                nt = v[i].second;
                idx = i;
            }
        }
        // 갱신이 안되었으면
        if(nt == f) {
            cout << 0 << "\n";
            return;
        }
        f = nt;
        ret++;
    }
    cout << ret << "\n";
    return;
}
int main() {
    fastIO();
    input();
    solve();
    return 0;
}