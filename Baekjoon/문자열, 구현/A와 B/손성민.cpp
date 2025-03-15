#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// A와 B(12904)
// https://www.acmicpc.net/problem/12904
// 문자열 - Greedy Alg.

// 문자열 S를 T로 바꾸는 문제
// 접근방식1. S에 A를 추가하거나, 뒤집고 B를 추가해 T를 만든다
// 접근방식2. T를 S로 바꾸는 방법을 생각해보자
// 추가해서 만드는 방식은 너무 경우의 수가 많으니, T를 S로 바꿔 비교해보기.
string str1, str2;
int str1Size, str2Size;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> str1 >> str2;
    str1Size = str1.size();
    str2Size = str2.size();
    return;
}
int main()
{
    fastIO();
    input();
    while(str1Size != str2Size)
    {
        if(str2[str2Size-1] == 'A') str2.pop_back();
        else
        {
            str2.pop_back();
            reverse(str2.begin(), str2.end());
        }
        str2Size = str2.size();
    }
    cout << (str1 == str2 ? 1 : 0) << "\n";
    return 0;
}