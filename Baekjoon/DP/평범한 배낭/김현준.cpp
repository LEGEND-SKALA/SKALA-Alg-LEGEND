#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<pair<int, int>> items(N + 1);  // (무게, 가치)
    for (int i = 1; i <= N; i++) {
        cin >> items[i].first >> items[i].second;
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    for (int i = 1; i <= N; i++) {
        int w = items[i].first;
        int v = items[i].second;
        for (int j = 0; j <= K; j++) {
            if (j < w)
                dp[i][j] = dp[i - 1][j];  // 무게 초과 → 못 넣음
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
        }
    }

    cout << dp[N][K] << "\n";
    return 0;
}
