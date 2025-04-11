#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// 컵라면 (1781)
// https://www.acmicpc.net/problem/1781
// Greedy, 자료구조 Alg.
// 시간복잡도: O(nlogn)
// 공간복잡도: O(n)

/*
- N개의 문제
- 각 문제를 풀었을 때 컵라면을 받음
- 각 문제에 대한 데드라인도 존재
- 동호가 받을 수 있는 최대 컵라면 수 구하기
*/
int n, ret;
vector<pair<int,int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
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
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    return;
}
void solve()
{
    // 정렬 - 오름차순
    sort(v.begin(), v.end());

    // 받을 수 있는 컵라면 갯수를 우선순위큐에 삽입
    // 삽입 후, 만약 우선순위큐의 갯수가 데드라인보다 크면 우선순위큐에서 한 개 삭제
    // 즉, 우선순위큐에 들어있는 요소의 갯수가 데드라인이 되는 것
    // 우선순위큐에서 삭제하는 건, 값이 젤 작은 걸 먼저 삭제하므로 남는 값들은 최대 값들만 남게 됨
    for(int i=0; i<n; i++)
    {
        pq.push(v[i].second);
        if(pq.size() > v[i].first) pq.pop();
    }
    while(!pq.empty())
    {
        ret += pq.top();
        pq.pop();
    }
    cout << ret << "\n";
    return;
}
int main()
{
    fastIO();
    input();
    solve();
}