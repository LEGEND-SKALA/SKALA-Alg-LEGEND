#include <iostream>
#include <queue>
using namespace std;

// 숨바꼭질3 (13549)
// https://www.acmicpc.net/problem/13549
/*
- BFS Alg.
- 시간복잡도: O(nlogn)
- 공간복잡도: O(1)
*/
int n, k, visited[100001];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// pos-1, pos+1, pos*2 위치를 bfs로 탐색
// 우선순위큐 사용 -> 최단 시간 처리하기 위함
void bfs(int start, int end)
{
    pq.push({0, start});
    while(!pq.empty())
    {
        int t = pq.top().first;
        int pos = pq.top().second;
        pq.pop();
        visited[pos] = 1;
        if(pos == end)
        {
            cout << t << "\n";
            return;
        }
        for(int num : {pos-1, pos+1, pos*2})
        {
            if(num < 0 || num >100000 || visited[num]) continue;
            if(num == pos * 2) pq.push({t, num});
            else pq.push({t+1, num});
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