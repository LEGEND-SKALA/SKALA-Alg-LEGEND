#include <iostream>
#include <stack>
using namespace std;

// 후위 표기식 (1918)
// https://www.acmicpc.net/problem/1918
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 연산자 우선순위 비교 함수
int oper(char ch)
{
    switch(ch)
    {
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        case '(': return 0;     // (는 우선순위가 높지만, 스택에서 처리하기 위해 우선순위 낮게 설정
        default: exit(0);
    }
}
void postFixNotation()
{
    stack<char> stk;
    string ret = "";
    for(int i=0; i<str.length(); i++)
    {
        // 문자면 그대로 추가
        if(str[i] >= 'A' && str[i] <= 'Z') ret += str[i];

        // 스택이 비어있거나, '('이면 추가
        else if(str[i] == '(' || stk.empty()) stk.push(str[i]);
        
        // 연산자가 ')'이면 '('을 만날 때까지 스택에서 pop
        else if(str[i] == ')')
        {
            while(stk.top() != '(')
            {
                char op = stk.top(); stk.pop();
                ret += op;
            }
            stk.pop();
        }
        
        else 
        {
            // 연산자 우선순위 비교1.  -> 스택의 top보다 우선순위가 크다면 push
            if(oper(stk.top()) < oper(str[i])) stk.push(str[i]);

            // 연산자 우선순위 비교2. -> 그렇지 않다면 
            else
            {
                while(!stk.empty() && oper(stk.top()) >= oper(str[i]))
                {
                    ret += stk.top(); stk.pop();
                }
                stk.push(str[i]);
            }
        }
    }

    // 남은 연산자 추가
    while(!stk.empty())
    {
        char op = stk.top(); stk.pop();
        ret += op;
    }
    cout << ret << "\n";
    return;
}
int main()
{
    fastIO();
    getline(cin, str);
    postFixNotation();
    return 0;
}
// A/B+C*D*E
// AB/CD*E*+

// A+(B*C+D)*E
// ABC*DE*+