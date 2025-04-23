#include <iostream>
using namespace std;

long long t, n, d[102] = {0, 1, 1, 1, 2};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for(int i = 5; i <= 100; ++i) d[i] = d[i - 1] + d[i - 5];
    cin >> t; while(t--) cin >> n, cout << d[n] << '\n';
}