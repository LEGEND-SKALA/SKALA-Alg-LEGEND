#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, chkSz, homeSz, sm, an = 1e9, mp[51][51], dst[15][101], curDst[101], tmp[15][101];
pair<int, int> chk[15];

void sol(int chkIdx, int cnt) {
    // M개의 치킨집을 고른 경우
    if (cnt == m) {
        // 도시의 치킨 거리 구하기
        sm = 0; for (int i = 0; i < homeSz; ++i) sm += curDst[i];
        an = min(an, sm); return;
    }
    if (chkIdx == chkSz) return;

    // chkIdx에 해당되는 치킨집을 고르지 않은 경우
    sol(chkIdx + 1, cnt);

    // chkIdx에 해당되는 치킨집을 고르지 않은 경우
    for (int i = 0; i < homeSz; ++i) tmp[chkIdx][i] = curDst[i], curDst[i] = min(curDst[i], dst[chkIdx][i]);
    sol(chkIdx + 1, cnt + 1);
    for (int i = 0; i < homeSz; ++i) curDst[i] = tmp[chkIdx][i];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 크기와 치킨집 개수 입력
    cin >> n >> m;
    // 치킨 거리를 1e9로 초기화
    fill(curDst, curDst + 2 * n, 1e9); 

    // 도시의 정보 입력
    // - 치킨집일 경우, chk 배열에 저장
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cin >> mp[i][j]; if (mp[i][j] == 2) chk[chkSz++] = { i,j };
    }

    // 치킨집과 집과의 모든 거리 dst에 저장
    for (int k = 0; k < chkSz; ++k) {
        homeSz = 0; for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
            if (mp[i][j] == 1) dst[k][homeSz++] = abs(i - chk[k].first) + abs(j - chk[k].second);
        }
    }

    // sol 함수 돌린 후, 도시의 치킨 거리의 최솟값 출력
    sol(0, 0); cout << an;
}