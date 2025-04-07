#include <iostream>
using namespace std;

int n, m, b, t = 1e9, h, sm, mp[502][502];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 집터의 크기과 인벤토리에 들어있는 블록 개수 저장
    cin >> n >> m >> b; 
    // 총 블록의 개수 더하기
    sm += b;
    // 땅의 높이 입력
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mp[i][j], sm += mp[i][j];
    // 0부터 (최대 땅의 높이)까지 순회
    sm /= n * m; for (int i = 0; i <= sm; ++i) {
        // b : 걸리는 시간 계산
        b = 0; for (int j = 0; j < n; ++j) for (int k = 0; k < m; ++k) {
            if (mp[j][k] > i) b += (mp[j][k] - i) * 2;  // i 높이보다 큰 경우
            else if (mp[j][k] < i) b += i - mp[j][k];   // i 높이보다 작을 경우
        }
        if (t > b) t = b, h = i;            // 걸리는 시간이 t보다 더 작을 경우, 시간과 높이 갱신
        else if (t == b && h < i) h = i;    // 걸리는 시간이 같고 높이가 클 경우, 높이 갱신
    }
    // 걸리는 시간과 땅의 높이를 출력
    cout << t << ' ' << h;
}