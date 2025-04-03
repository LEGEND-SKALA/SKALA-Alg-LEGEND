#include <iostream>
#include <algorithm>
using namespace std;

int n, an, en;
pair<int, int> p[100010];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
    // pair에 {끝나는 시간, 시작 시간}으로 저장하여 오름차순 정렬
	cin >> n; for (int i = 0; i < n; ++i) cin >> p[i].second >> p[i].first; sort(p, p + n);

    // 회의실 사용 시간 순회
    // - 시작시간이 현재 끝나는 시간보다 크거나 같을 경우, en 갱신
	for (int i = 0; i < n; ++i) if (en <= p[i].second) en = p[i].first, ++an;

    // 사용할 수 있는 회의의 최대 개수를 출력
	cout << an;
}