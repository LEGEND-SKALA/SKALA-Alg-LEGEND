#include <iostream>
#include <algorithm>
using namespace std;

int n, m[1000003];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // N개의 수 입력 받아서 오름차순 정렬 후 출력
    cin >> n; for(int i = 0; i < n; ++i) cin >> m[i];
    sort(m, m + n); for(int i = 0; i < n; ++i) cout << m[i] << '\n';
}