#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 두 용액(2470)
// Sort, TwoPointer Alg.
// https://www.acmicpc.net/problem/2470
vector<int> v;
int sum, _min = 2000000001;
int n, retL, retR;
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
        int num;
        cin >> num;
        v.push_back(num);
    }
    return;
}
void solve()
{
    // 오름차순 정렬
    sort(v.begin(), v.end());
    int left = 0, right = v.size() - 1;
    // 투 포인터
    while(left != right)
    {
        sum = v[left] + v[right];
        // 최솟값 갱신
        if(abs(sum) < _min)
        {
            _min = abs(sum);
            retL = v[left];
            retR = v[right];
        }
        // 합이 0보다 작으면 left + 1
        if(sum < 0) left++;
        // 합이 0보다 같거나 크면 right - 1
        else right--;
    }
    cout << retL << " " << retR << "\n";
    return;
}
int main()
{
    fastIO();
    input();
    solve();  
    return 0;
}