#include <iostream>
#include <algorithm>
using namespace std;

int n, k, s, cnt, an, i, j;
pair<int, int> m[30002];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // n: 아파트 단지 수, k: 통학버스 정원, s: 학교 위치
    // m에 {아파트 단지 위치, 학생 수} 저장 후 오름차순 정렬
    cin >> n >> k >> s; for(int i = 0; i < n; ++i) cin >> m[i].first >> m[i].second; sort(m, m + n);

    // 학교 왼쪽에 있는 아파트 단지 확인
    for(i = 0; i < n; ++i) {
        if(m[i].first > s) break;  // 학교 오른쪽에 있으면 중단
        if(!m[i].second) continue; // 학생이 없는 경우 contitnue
        cnt = 0; j = i;
        while(m[j].first <= s && j < n && cnt < k) {
            // 단지에 있는 모든 학생수를 더했을 때 k 이하인 경우
            if(cnt + m[j].second <= k) cnt += m[j].second, m[j].second = 0;
            // 단지에 있는 모든 학생수를 더했을 때 k 초과인 경우, 초과하지 않을 정도로 학생 태우기
            else m[j].second -= k - cnt, cnt = k;
            ++j;
        }
        an += (s - m[i].first) * 2; // 정답에 거리 추가
        if(m[i].second) --i;        // 학생이 있는 경우 i번째 아파트 단지 재확인
    }
    // 학교 오른쪽에 있는 아파트 단지 확인
    for(--n; n >= i; --n) {
        if(m[n].first <= s) break;  // 학교 왼쪽에 있으면 중단
        if(!m[n].second) continue;  // 학생이 없는 경우 contitnue
        cnt = 0; j = n;
        while(m[j].first > s && j >= 0 && cnt < k) {
            // 단지에 있는 모든 학생수를 더했을 때 k 이하인 경우
            if(cnt + m[j].second <= k) cnt += m[j].second, m[j].second = 0;
            // 단지에 있는 모든 학생수를 더했을 때 k 초과인 경우, 초과하지 않을 정도로 학생 태우기
            else m[j].second -= k - cnt, cnt = k;
            --j;
        }
        an += (m[n].first - s) * 2; // 정답에 거리 추가
        if(m[n].second) ++n;        // 학생이 있는 경우 n번째 아파트 단지 재확인
    }

    // 정답 출력
    cout << an;
}