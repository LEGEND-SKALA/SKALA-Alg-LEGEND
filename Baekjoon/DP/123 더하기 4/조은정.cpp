#include <iostream>
using namespace std;

int T, n, an;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T; while (T--) {
        cin >> n; an = 0;
        while (n >= 0) an += n / 2 + 1, n -= 3;
        cout << an << '\n';
    }
}