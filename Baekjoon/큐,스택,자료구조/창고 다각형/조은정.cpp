#include <iostream>
#include <stack>
#include <algorithm>
#include <cmath>
using namespace std;

// n: 기둥의 개수, w: x축 포지션을 저장할 변수, h: 높이를 저장할 변수, an: 정답, mx: 가장 큰 높이
int n, w, h, chk, an, mx;
// m: x축 위치와 높이를 저장하는 페어 배열
pair<int, int> m[1002];
// st: 페어 스택, {{x축 위치, 높이}, 이전에 비교하여 증가하는지 감소(0: 증가, 1: 감소)}
stack<pair<pair<int, int>, int>> st;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    // 기둥의 개수 및 기둥 정보 저장, 가장 높은 높이 갱신
    cin >> n; for(int i = 0; i < n; ++i) cin >> m[i].first >> m[i].second, mx = max(mx, m[i].second);
    // x축 좌표 기준 오름차순 정렬
    sort(m, m + n);
    // 스택에 첫번째 기둥을 push
    st.push({{m[0]}, 0});

    // 두번째 기둥부터 마지막 기둥까지 순회
    for(int i = 1; i < n; ++i) {
        // w: 현재 x축 위치, h: 높이, chk: 증가하고 있는지 감소하고 있는지 (0: 증가, 1: 감소)}
        w = st.top().first.first; h = st.top().first.second; chk = st.top().second;
        // 감소했던 경우
        // - 감소했던 원소에 대해서 현재 높이보다 작았던 경우, 스택에서 pop
        if(chk) while(st.top().second && st.top().first.second < m[i].second) st.pop();
        // 스택에 현재 원소 저장
        st.push({{m[i]}, (st.top().first.second < m[i].second ? 0 : 1)});
    }

    // 스택에서 원소를 제거하면서 면적 구하기
    while(st.size()) {
        // w: 현재 x축 위치, h: 높이, chk: 증가하고 있는지 감소하고 있는지 (0: 증가, 1: 감소)}
        w = st.top().first.first; h = st.top().first.second; chk = st.top().second; st.pop();
        if(st.empty()) break;  // 스택이 비어질 경우 break
        // 정답에 너비 저장
        // - 현재 너비 = (현재 x축 위치와 스택 top의 x축 위치의 차이) x (현재 높이와 스택 top의 높이 중 작은 값)
        an += abs(w - st.top().first.first) * min(h, st.top().first.second);
    }

    // (총 너비) = (구한 너비의 합) + (가장 높은 기둥의 너비)
    cout << an + mx;
}