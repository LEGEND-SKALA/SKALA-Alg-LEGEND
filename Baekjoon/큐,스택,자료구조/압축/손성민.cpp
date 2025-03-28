#include <iostream>
#include <stack>
using namespace std;

// 압축 (1662)
// https://www.acmicpc.net/problem/1662
string str;
int ret;
stack<int> stk;
// 입출력 동기화 해제
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solve()
{
    for(int i=0; i<str.length(); i++)
    {
        // '('이면 스택에 -1 추가 
        if(str[i] == '(') stk.push(-1);
        else if(str[i] >= '0' && str[i] <= '9')
        {
            // 숫자고, 인덱스가 범위 내이며, 다음 문자 값이 (일 때, 해당 값 push
            if((i < str.length() - 1) && str[i+1] == '(')
            {
                stk.push(str[i] - '0');
            }
            // 그렇지 않으면 1 push -> 단순히 문자열 길이만 확인하면 되므로, 해당 값이 아닌 해당 문자의 길이를 나타내는 값인 1 추가
            else stk.push(1);
        } else {
            // stack 형태 예시
            // 3454(2315(...))
            // 1114-11115-1 ...
            // -1기준으로 -1: 여는 괄호, -1이전값: 반복되는 횟수
            int len = 0;
            while(stk.top() != -1)
            {
                len += stk.top(); stk.pop();
            }
            stk.pop();
            len *= stk.top(); stk.pop();
            stk.push(len);
        }
    }
    while(!stk.empty())
    {
        ret += stk.top(); stk.pop();
    }
    cout << ret << "\n";
    return;
}
int main()
{
    fastIO();
    cin >> str;
    solve();
    return 0;
}
// 입출력 예제
// 33(562(71(9)))
// 33(562(79))
// 33(567979)
// 3567979567979567979