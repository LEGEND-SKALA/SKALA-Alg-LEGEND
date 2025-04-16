#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, idx, an;
pair<int, int> p[200002];   // {데드라인, 컵라면 수}
priority_queue<int> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // n개의 문제에 대한 정보({데드라인, 컵라면 수})를 배열 p에 저장 후 p 오름차순 정렬
    cin >> n; idx = n - 1; for(int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second; sort(p, p + n);

    // 시간 n부터 0으로 가며 확인
    for(int i = n; i > 0; --i) {
        // 현재 idx에 해당하는 문제의 데드라인이 시간 i인 경우 q에 컵라면 수 삽입 및 idx 1만큼 감소
        // - i인 경우 넣은 이유: 0 ~ i초 안에서 풀 수 있는 문제기 때문
        while(idx >= 0 && p[idx].first == i) q.push(p[idx--].second);

        // q에 원소가 존재하면 정답에 top에 해당하는 컵라면 수만큼 an 증가
        if(q.size()) an += q.top(), q.pop();
    }

    // 정답 출력
    cout << an;
}