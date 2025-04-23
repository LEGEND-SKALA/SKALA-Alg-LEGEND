#include <iostream>
#include <algorithm>
using namespace std;

int y, d[11];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> d[0] >> y;
    for(int i = 1; i <= y; ++i)
        d[i] = max({(int)(d[i - 1] * 1.05),
                    (i > 2 ? (int)(d[i - 3]* 1.2) : 0),
                    (i > 4 ? (int)(d[i - 5] * 1.35) : 0)});
    cout << d[y];
}
