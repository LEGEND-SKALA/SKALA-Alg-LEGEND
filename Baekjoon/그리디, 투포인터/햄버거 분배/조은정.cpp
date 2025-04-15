#include <iostream>
#include <algorithm>
using namespace std;

// n: 식탁 길이, k: 햄버거 선택할 수 있는 거리, an: 정답, s: 식탁에 있는 사람과 햄버거 정보
int n, k, an;
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> k >> s; for(int i = 0; i < n; ++i) {
        if(s[i] != 'P') continue;   // 사람이 아닌 경우 패스

        // 사람이 위치한 곳에서 k 만큼의 거리 내에 가장 왼쪽에서 오른쪽으로 확인
        // - 햄버거가 있는 경우 해당 사람이 E를 저장함으로써 먹음을 표시 및 an을 1만큼 증가
        for(int j = max(0, i - k); j <= min(n - 1, i + k); ++j) {
            if(s[j] == 'H') {
                ++an, s[j] = 'E'; break;
            }
        }
    }

    // 정답 출력
    cout << an;
}