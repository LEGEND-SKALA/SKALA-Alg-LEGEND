#include <iostream>
#include <deque>
using namespace std;

// 풍선 터뜨리기 (2346)
// deque 자료구조 사용
// https://www.acmicpc.net/problem/2346
int n, num;
deque<pair<int,int>> deq;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        deq.push_back({i+1, num});
    }
    return;
}
// 양수 일때는 오른쪽 -> push_back(deque.front), pop_front();
// 음수 일때는 왼쪽 -> push_front(deque.back), pop_back();
void solve()
{
    while(!deq.empty())
    {
        cout << deq.front().first << " ";
        int moves = deq.front().second;
        deq.pop_front();

        if(deq.empty()) break;
        if(moves > 0)
        {
            // 양수일 때는, moves만큼 앞에서부터 삭제해줘야 하지만, 위에서 pop_front를 한 번 해주었기 때문에 moves-1만큼 
            for(int i=0; i<moves-1; i++)
            {
                deq.push_back(deq.front());
                deq.pop_front();
            }
        } else {
            // 음수일 때는, moves만큼 뒤에서부터 삭제해줘야 하므로, moves만큼
            for(int i=0; i< -1*moves; i++)
            {
                deq.push_front(deq.back());
                deq.pop_back();
            }
        }
    }
    cout << "\n";
    return;
}
int main()
{
    fastIO();
    input();
    solve();
    return 0;
}