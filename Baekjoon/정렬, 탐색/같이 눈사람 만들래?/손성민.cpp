#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 같이 눈사람 만들래? (20366)
// https://www.acmicpc.net/problem/20366
// Sort, Two Pointer Alg.
typedef long long ll;
const int INF = 1e9;
ll n, ret = INF, sumA, sumB;
vector<ll> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> n;
    if(n < 4 || n > 600) exit(1);
    for(int i=0; i<n; i++)
    {
        ll num;
        cin >> num;
        v.push_back(num);
    }
    return;
}
void solve()
{
    // 정렬
    sort(v.begin(), v.end());
    // 음.. 이걸 어떻게 풀지.. 흠..
    // 범위가 작아서 그냥 구현해도 되지 않을까? (n <= 600)
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            sumA = v[i] + v[j]; // 2중 for문 돌면서 숫자 두 개 고르기.
            int l = i+1, r = n-1;
            while(l < r)
            {
                if(l == i || l == j) 
                {
                    l++;
                    continue;
                }
                if(r == i || r == j) 
                {
                    r--;
                    continue;
                }
                sumB = v[l] + v[r];
                ret = min(ret, abs(sumA-sumB));
                if(sumB < sumA) l++;
                else if(sumB > sumA) r--;
                else
                {
                    cout << 0 << "\n";
                    return;
                }
            }
        }
    }
    cout << ret << "\n";
}
int main()
{
    fastIO();
    input();
    solve();
    return 0;
}