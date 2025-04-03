#include <iostream>
using namespace std;

int n, m[20000002], a, sm = 10000000;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    // 배열에 들어온 숫자에 대해 1을 저장
    cin >> n; while(n--) cin >> a, m[a + sm] = 1;
    // 들어온 숫자인지 배열을 통해 확인
    cin >> n; while(n--) cin >> a, cout << m[a + sm] << ' ';
}