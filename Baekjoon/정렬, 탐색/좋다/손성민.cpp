#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 좋다 (1253)
// Sort, Two-pointer Alg.
// https://www.acmicpc.net/problem/1253
typedef long long ll;
vector<ll> v;
int n, ret;
// 입출력 동기화 해제
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 입력
void input()
{
    cin >> n;
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
    // 한 번 오름차순 정렬
    sort(v.begin(), v.end());
    
    // 뒤에서부터 탐색
    for(int i=n-1; i>=0; i--)
    {
        ll val = v[i];

        // 투포인터
        int left = 0, right = n - 1;
        while(left < right)
        {
            ll sum = v[left] + v[right];
            if(val == sum)
            {
                // 찾고자 하는 수는 연산에 포함하면 안됨
                if(left != i && right != i) 
                {
                    ret++;
                    break;
                }
                else if(left == i) left++;
                else if(right == i) right--;
            } else if(val < sum) right--;
            else left++;
        }
    }
}
int main()
{
    fastIO();
    input();
    solve();
    cout << ret << "\n";
    return 0;
}