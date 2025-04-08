#include <iostream>
using namespace std;

// a[0] : 오른쪽 위 대각선, a[1] : 왼쪽 위 대각선, a[2] : 세로선
int n, an, a[3][30];

// u: 몇 번째 행인지 (행마다 하나의 퀸만 놓을 수 있으므로)
void sol(int u) {
    // 퀸을 다 놓은 경우, an을 1 만큼 증가
    if(u == n) {
        ++an; return;
    }
    // 몇 번째 열에 놓을지 0부터 n까지 순회하면서 판단
    for(int i = 0; i < n; ++i) {
        if(!a[0][u + i] && !a[1][u - i + n] && !a[2][i]) {
            // i 열에 놓을 수 있는 경우, i 열에 놓음을 저장
            a[0][u + i] = a[1][u - i + n] = a[2][i] = 1;
            sol(u + 1);
            // i 열에서 놓았던 걸 다시 빼기
            a[0][u + i] = a[1][u - i + n] = a[2][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 퀸의 개수 입력 받고, sol 함수 실행 후 경우의 수 출력
    cin >> n; sol(0); cout << an;
}