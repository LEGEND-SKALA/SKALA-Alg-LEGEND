#include <iostream>
#include <queue>
using namespace std;

// 숨바꼭질 (1697)
// https://www.acmicpc.net/problem/1697
/*
- BFS Alg.
- 시간복잡도: O(n)
- 공간복잡도: O(1)
*/
int n, k, visited[100001];
queue<pair<int,int>> q;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// pos-1, pos+1, pos*2 위치를 bfs로 탐색
void bfs(int start, int end)
{
    q.push({0, start});
    while(!q.empty())
    {
        int t = q.front().first;
        int pos = q.front().second;
        q.pop();
        visited[pos] = 1;
        if(pos == end)
        {
            cout << t << "\n";
            return;
        }
        for(int num : {pos-1, pos+1, pos*2})
        {
            if(num < 0 || num >100000 || visited[num]) continue;
            q.push({t+1, num});
        }
    }
    return;
}
int main()
{
    fastIO();
    cin >> n >> k;
    bfs(n, k);
    return 0;
}