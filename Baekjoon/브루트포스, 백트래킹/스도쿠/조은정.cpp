#include <iostream>
using namespace std;

// a[0] : 3x3 정사각형 배열, a[1] : 가로선 배열, a[2]: 세로선 배열
int sz, a[3][9][10], b[9][9];
pair<int, int> p[82];

// u : 0이 저장된 배열 p에 대한 인덱스
void sol(int u) {
    // 0을 다 채운 경우
    if(u == sz) {
        // 채워진 스도쿠판 출력
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) cout << b[i][j] << ' ';
            cout << '\n';
        }
        exit(0);    // 프로그램 종료
    }
    // 인덱스 u에 대한 좌표 저장
    int y = p[u].first, x = p[u].second;
    for(int i = 1; i <= 9; ++i) {   // 1부터 9까지 직접 넣어가며 판단
        if(!a[0][y / 3 * 3 + x / 3][i] && !a[1][y][i] && !a[2][x][i]) {
            // i가 가능한 경우 b[y][x]에 i를 작성
            a[0][y / 3 * 3 + x / 3][i] = a[1][y][i] = a[2][x][i] = 1;
            b[y][x] = i; sol(u + 1);
            // 다시 0으로 되돌리기
            a[0][y / 3 * 3 + x / 3][i] = a[1][y][i] = a[2][x][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 스도쿠판 입력
    for(int i = 0; i < 9; ++i) for(int j = 0; j < 9; ++j) {
        cin >> b[i][j]; a[0][i / 3 * 3 + j / 3][b[i][j]] = a[1][i][b[i][j]] = a[2][j][b[i][j]] = 1;
        // 0일 경우, p 배열에 좌표 저장
        if(!b[i][j]) p[sz++] = {i, j};
    }
    sol(0);  // sol 함수 실행
}