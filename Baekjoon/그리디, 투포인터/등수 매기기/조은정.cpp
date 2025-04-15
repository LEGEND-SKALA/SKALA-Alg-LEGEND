#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long n, m[500003], an;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // n개의 등수를 m에 저장하여 오름차순 정렬
    cin >> n; for(int i = 1; i <= n; ++i) cin >> m[i]; sort(m + 1, m + n + 1);

    // |배열 m과 인덱스의 차이|의 합을 정답에 저장
    for(int i = 1; i <= n; ++i) an += abs(i - m[i]); cout << an;
}