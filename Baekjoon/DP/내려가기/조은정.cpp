#include <iostream>
#include <algorithm>
using namespace std;

int n, d[2][3][2], mxV = 1e9;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n; for(int i = 0; i < n; ++i) {
        for(int j = 0; j < 3; ++j) cin >> d[1][j][0], d[1][j][1] = d[1][j][0];
        for(int j = 0; j < 3; ++j)
            d[1][j][1] += min({(j == 2? mxV : d[0][0][1]), d[0][1][1], (j ? d[0][2][1] : mxV)}),
            d[1][j][0] += max({(j == 2? 0 : d[0][0][0]), d[0][1][0], (j ? d[0][2][0] : 0)});
        for(int j = 0; j < 3; ++j) d[0][j][0] = d[1][j][0], d[0][j][1] = d[1][j][1];
    }
    cout << max({d[0][0][0], d[0][1][0], d[0][2][0]}) << ' '
        << min({d[0][0][1], d[0][1][1], d[0][2][1]});
}