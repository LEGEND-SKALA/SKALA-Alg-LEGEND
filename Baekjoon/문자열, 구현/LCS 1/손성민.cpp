#include <iostream>
#include <string>
using namespace std;;

// LCS (9251)
// https://www.acmicpc.net/problem/9251
// DP Alg.

// 2차원 배열 -> 행과 열을 이용해 문자열 비교
// 1. 문자열 길이만큼 2차원 배열 생성
// 2. 문자열 비교 -> 같으면 대각선 위의 값 + 1, 다르면 max(왼쪽 값, 위쪽 값)
// 3. 마지막 값 출력
int lcs[1004][1004];
string str1, str2;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> str1;
    cin >> str2;
    return;
}
void solution()
{
    int str1_len = str1.size(), str2_len = str2.size();
    for(int i=1; i<=str1_len; i++)
    {
        for(int j=1; j<=str2_len; j++)
        {
            if(str1[i-1] == str2[j-1]) lcs[i][j] = lcs[i-1][j-1] + 1;
            else lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
        }
    }
    cout << lcs[str1_len][str2_len] << "\n";
    return;
}
int main()
{
    fastIO();
    input();
    solution();
    return 0;
}