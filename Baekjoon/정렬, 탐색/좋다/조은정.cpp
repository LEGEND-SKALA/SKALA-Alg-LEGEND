#include <iostream>
#include <algorithm>
using namespace std;

int n, an, st, en, a[2002];

int main() {
    // 수를 입력 받아서 정렬
    cin >> n; for(int i = 0; i < n; i++) cin >> a[i]; sort(a, a+ n);

    // 정렬된 수에 대해 순회
    for (int i = 0; i < n; i++) {
        // 투포인터 알고리즘 활용
        st = 0, en = n - 1;
        while (st < en) {
            // a[i] 수가 더 크거나 st와 i가 같을 경우, st 1 증가
            if(a[i] > a[st] + a[en] || st == i) ++st;
            // a[i] 수가 더 작거나 en와 i가 같을 경우, en 1 감소
            else if(a[i] < a[st] + a[en] || en == i) --en;
            // a[i]와 a[st] + a[en]가 같을 경우, an 1 증가 후 break
            else {
                ++an; break;
            }
        }
    }

    // 좋은 수의 개수 출력
    cout << an;
}
