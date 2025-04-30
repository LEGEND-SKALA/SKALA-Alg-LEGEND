#include <iostream>
using namespace std;

int d, k, a = 1, b, c;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> d >> k; while(d-- > 2) c = b, b = a, a = c + b;
    c = 1; while((k - c * b) % a) ++c;
    cout << c << '\n' << (k - c * b) / a;
}