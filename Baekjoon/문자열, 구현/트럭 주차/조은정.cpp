#include <iostream>
using namespace std;

// sm[101]: 시간별로 주차된 자동차 수 저장
int st, en, an, c[4], sm[101];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // c[4]: 자동차 개수에 따른 주차 요금 저장
    for(int i = 1; i < 4; ++i) cin >> c[i];

    for(int i = 0; i < 3; ++i) {
        cin >> st >> en; 
        // 시간별로 주차된 자동차 수 저장
        // - 각 자동차의 도착 시간부터 떠난 시간까지 sm 배열을 1씩 증가
        while(st < en) ++sm[st++];
    }

    // 주차 요금 구하기: (시간 별로 자동차 수) * (자동차 수에 따른 주차 요금)의 총합
    for(int i = 1; i < 101; ++i) an += sm[i] * c[sm[i]];

    // 정답 출력
    cout << an;
}