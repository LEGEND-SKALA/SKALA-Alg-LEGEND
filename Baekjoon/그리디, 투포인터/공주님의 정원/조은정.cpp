#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> PI;

// a: 달, b: 일
int n, a = 3, b = 1, idx, cnt;
pair<PI, PI> p[100002];
priority_queue<PI> q;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;   // 꽃들의 개수
    for(int i = 0; i < n; ++i)  // 꽃 피는 날짜와 지는 날짜 입력
        cin >> p[i].first.first >> p[i].first.second >> p[i].second.first >> p[i].second.second;
    sort(p, p + n);     // 꽃 정보를 오름차순 정렬
    while(a != 12) {    // 12월이 아닐 때까지 반복
        // idx가 n 미만이고 현재 날짜보다 같거나 그 전일 경우 q에 지는 날 push
        while(idx < n && p[idx].first.first < a 
            || (p[idx].first.first == a && p[idx].first.second <= b)) q.push({p[idx++].second});

        // q에 꽃 정보가 존재할 경우, 지는 날짜가 가장 늦게 있는 정보에 대해 a, b 갱신 및 q pop, cnt 1 증가
        if(q.size()) a = q.top().first, b = q.top().second, q.pop(), ++cnt;
        // q에 꽃 정보 없다면 break
        else break;
    }

    // 최종 달이 12월인 경우 cnt 출력, 아닌 경우 0 출력
    cout << (a == 12 ? cnt : 0);
}