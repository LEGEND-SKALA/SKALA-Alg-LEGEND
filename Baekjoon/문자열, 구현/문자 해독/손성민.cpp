#include <iostream>
#include <string>
#include <map>
using namespace std;

// 문자 해독 (1593)
// https://www.acmicpc.net/problem/1593
// 문자열 - 슬라이딩 윈도우? Alg.
map<char, int> wMap, sMap;
int wLen, sLen, ret;
string w, s;
// 입출력 동기화 해제
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 입력
void input()
{
    cin >> wLen >> sLen;
    cin >> w >> s;
    if(wLen < 1 || wLen > 3000 || sLen < wLen || sLen > 3000000) exit(0);
    for(int i=0; i<wLen; i++) wMap[w[i]]++;
    return;
}
// Map을 이용
// 각 문자열에 대한 Map을 만들어서, 슬라이딩 하면서 비교
// ex) w = "ABC", s = "ABCBA"
// wMap = {A: 1, B: 1, C: 1}
// sMap = ABC{A: 1, B: 1, C: 1} -> BCB{B: 2, C: 1} -> CBA{A: 1, B: 1, C: 1}
void solution()
{
    for(int i=0; i<wLen; i++) sMap[s[i]]++;
    if(sMap == wMap) ret++;
    for(int i=wLen; i<sLen; i++)
    {
        sMap[s[i-wLen]]--;
        if(sMap[s[i-wLen]] == 0) sMap.erase(s[i-wLen]);
        sMap[s[i]]++;
        if(sMap == wMap) ret++; 
    }
    return;
}
int main()
{
    fastIO();
    input();
    solution();
    cout << ret << "\n";
    return 0;
}