#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll T, n, an, d[101], mxV = 1e18;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    for (int i = 1; i <= 100; i++)
        d[i] = min({d[i - 1] + 1, (i > 9 ? d[i - 10] + 1 : mxV), (i > 24 ? d[i - 25] + 1 : mxV)});
    cin >> T; while(T--) {
        cin >> n; an = 0;
        while(n) an += d[n % 100], n /= 100;
        cout << an << '\n';
    }
}