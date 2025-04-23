#include <iostream>
#include <cstring>
using namespace std;

int N, M, S, E;
int num[2020];
int d[2020][2020];

bool solution(int S, int E) {
	if (S == E || S + 1 == E) return num[S] == num[E];
	if (d[S][E] != -1) return d[S][E];
	if (num[S] == num[E]) return d[S][E] = solution(S + 1, E - 1);
	return 0;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	memset(d, -1, sizeof d);
	cin >> N; for (int i = 1; i <= N; ++i) cin >> num[i];
	cin >> M; while (M--) cin >> S >> E, cout << solution(S, E) << '\n';
}
