#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m[100002], u, an = 2e9, a, b;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 용액을 입력 받고 정렬
    cin >> n; for(int i = 0; i < n; ++i) cin >> m[i]; sort(m, m + n);

    // u가 n보다 작을 때까지 반복
    --n; while(u < n) {
        if(an >= abs(m[n] + m[u])) an = abs(m[n] + m[u]), a = m[u], b = m[n];
        if(!an) break;

        // 양수일 경우 n 1만큼 감소, 음수일 경우 u 1만큼 증가
        m[n] + m[u] > 0 ? --n : ++u;
    }

    // 용액 출력
    cout << a << ' ' << b;
}