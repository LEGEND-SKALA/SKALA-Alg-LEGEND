#include <iostream>
#include <algorithm>
using namespace std;

string a, b;
int dp[1003][1003];  // S와 T의 부분문자열에 대해 LCS의 길이 저장

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;

    // 문자열 S의 요소와 문자열 T의 요소에 대해 이중 포문
    // - 두 문자가 같을 경우: (현재 문자를 포함하지 않은 부분문자열끼리의 LCS의 길이) + 1
    // - 두 문자가 다를 경우
    //   - 두 값 중 큰 것을 채택
    //     - 현재 S의 부분문자열과 현재 문자를 포함하지 않은 T의 부분문자열의 LCS의 길이
    //     - 현재 문자를 포함하지 않은 S의 부분문자열과 현재 T의 부분문자열의 LCS의 길이
    for(int i = 0; i < a.size(); ++i) for(int j = 0; j < b.size(); ++j)
        dp[i + 1][j + 1] = (a[i] == b[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]));
        
    cout << dp[a.size()][b.size()];
}