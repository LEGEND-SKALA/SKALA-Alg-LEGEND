#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 수 정렬하기 2
// Sort Alg.
// https://www.acmicpc.net/problem/2751
vector<int> v;
int n, num;
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
        v.push_back(num);
    }
    return;
}
int main()
{
    fastIO();
    input();
    sort(v.begin(), v.end());
    for(int num : v) cout << num << "\n";
    return 0;
}