#include <iostream>
#include <algorithm>
using namespace std;

int n, d[10002], a[10002];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n; for(int i = 0; i < n; ++i) {
        cin >> a[i]; d[i] = max({(i > 0 ? d[i - 1] : 0),
                                (i > 1 ? d[i - 2] : 0) + a[i] ,
                                (i > 2 ? d[i - 3] : 0) + (i > 0 ?  a[i - 1] : 0) + a[i]});
    }
    cout << d[n - 1];
}