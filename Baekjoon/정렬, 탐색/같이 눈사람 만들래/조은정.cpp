#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, an = 2e9, sm1, sm2, st, en, h[602];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // N개의 눈덩이에 대해 지름을 입력 받고 오름차순 정렬
    cin >> n; for(int i = 0; i < n; ++i) cin >> h[i]; sort(h, h + n);

    for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) {
        // for문을 통해 엘사의 눈사람 정하기
        sm1 = h[i] + h[j]; 

        // 투포인터로 안나의 눈사람 정하기
        st = 0; en = n - 1;
        while(st < en) {
            // st와 en 각각에 대해 i 또는 j와 같다면 처리
            if(st == i || st == j) ++ st;
            else if(en == i || en == j) --en;
            else {
                sm2 = h[st] + h[en];
                an = min(an, abs(sm1 - sm2));

                // 엘사 눈사람이 안나 눈사람보다 크다면 st 1만큼 증가
                // 아니라면 en 1만큼 감소
                sm1 > sm2 ? ++st : --en;
            }
        }
    }

    // 두 눈사람의 키 차이 중 최솟값 출력
    cout << an;
}
