#include <iostream>
#include <string>
#include <algorithm>
int main() {
    std::string a, b;
    std::cin >> a >> b;

    int dp[1001][1001] = {0};  // dp 배열 초기화

    // dp 배열을 채우기 시작
    for (int i = 1; i <= a.length(); i++) {  // 1부터 a.length()까지
        for (int j = 1; j <= b.length(); j++) {  // 1부터 b.length()까지
            if (a[i - 1] == b[j - 1]) {  // 문자열 비교는 0-based index이므로 i-1, j-1을 사용
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::cout << dp[a.length()][b.length()] << std::endl;  // 최종 결과 출력
    return 0;
}
