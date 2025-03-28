#include <iostream>
#include <queue>
using namespace std;

// 카드 합체 놀이 (15903)
// 우선순위큐 - 자료구조 Alg.
// https://www.acmicpc.net/problem/15903
typedef long long ll;
ll n, m, num, ret;
priority_queue<ll, vector<ll>, greater<ll>> pq;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 우선순위큐 사용 -> 두 개씩 뽑아 더하고 다시 두 개씩 push
void solve()
{
    while(m--)
    {
        ll a = pq.top(); pq.pop();
        ll b = pq.top(); pq.pop();
        ll sum = a + b;
        pq.push(sum); pq.push(sum);
    }
    while(!pq.empty())
    {
        ret += pq.top(); pq.pop();
    }
    cout << ret << "\n";
}
int main()
{
    fastIO();
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        cin >> num;
        pq.push(num);
    }
    solve();
    return 0;
}