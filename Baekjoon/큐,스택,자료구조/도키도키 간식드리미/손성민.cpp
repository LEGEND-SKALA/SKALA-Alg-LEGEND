#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 도키도키 간식드리기미 (12789)
// https://www.acmicpc.net/problem/12789
/* 
접근방식1
- 탐색하며 해당 순서가 아니면, Stack에 push
- 탐색 완료 시 Stack에서 하나씩 꺼내서 순서가 맞는지 확인
=> 탐색 도중에도 Stack에서 pop해서 확인할 수 있다는 사실 간과
*/
int n, num;
vector<int> v;
// 입출력 동기화 해제
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 입력 (메모리 효율 차원 벡터 사용)
void input()
{
    cin >> n;
    if(n<1 || n>1000) exit(0);

    for(int i=0; i<n; i++)
    {
        cin >> num;
        v.push_back(num);
    }
}
void solve()
{
    stack<int> stk;
    int pos = 1;
    // 벡터 순회하며 해당 순서일 때 스택에서도 맞는 순서가 있는지 확인
    for(int i=0; i<v.size(); i++)
    {
        if(pos == v[i])
        {
            pos++;
            while(!stk.empty())
            {
                if(stk.top() > pos) break;
                else if(stk.top() == pos)
                {
                    pos++;
                    stk.pop();
                }
            }
        } else {
            stk.push(v[i]);
        }
    }
    if(stk.size()) cout << "Sad" << "\n";
    else cout << "Nice" << "\n";
    return;
}
int main()
{
    fastIO();
    input();
    solve();
}
// 4
// 4 2 1 3
// Nice