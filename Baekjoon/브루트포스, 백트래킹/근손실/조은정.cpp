#include <iostream>
using namespace std;

int n, k, sm, an, up[9], arr[9];

// cnt: 사용한 키드 개수 저장
// vis: 키드 사용 여부 저장
void sol(int cnt, int vis) {
    // 키트를 모두 사용한 경우
    if(cnt == n) {
        // 저장한 키트 순서대로 확인
        // - 음수일 경우, break
        sm = 0; for(int i = 0; i < n; ++i) {
            sm += up[arr[i]] - k; if(sm < 0) break;
        }
        // 0 이상인 경우는 항상 중량이 500 이상이 되는 경우기에 an 1 만큼 증가
        if(sm >= 0) ++an;
        return;
    }
    // 각각의 키트에 대해 순회
    for(int i = 0; i < n; ++i) {
        // 사용한 경우 continue
        if(vis & (1 << i)) continue;
        // cnt번째 사용한 키트가 i임을 저장
        arr[cnt] = i; sol(cnt + 1, vis | (1 << i));
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 기간과 감소하는 중량, 키드의 중량 증가량 입력
    cin >> n >> k; for(int i = 0; i < n; ++i) cin >> up[i];
    // sol 함수 실행 후, 경우의 수 출력
    sol(0, 0); cout << an;
}