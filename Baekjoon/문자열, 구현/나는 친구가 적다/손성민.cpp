#include <iostream>
#include <string>
using namespace std;

// 나는 친구가 적다(16172)
// https://www.acmicpc.net/problem/16172
// 문자열 -  구현Alg.
string s, k;
int sLen, kLen;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> s >> k;
    sLen = s.size();
    kLen = k.size();
    if(sLen < 1 || sLen > 200000 || kLen < 1 || kLen > 200000 || sLen < kLen) exit(0);
    return;
}
int main()
{
    fastIO();
    input();
    string tmp = "";
    for(int i=0; i<sLen; i++)
    {
        if(s[i] >= '0' && s[i] <= '9') continue;
        tmp += s[i];
    }
    cout << (tmp.find(k) != string::npos ? 1 : 0) << "\n";
    return 0;
}