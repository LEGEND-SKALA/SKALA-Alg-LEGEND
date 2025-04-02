#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 숫자 카드(10815)
// https://www.acmicpc.net/problem/10815
int n, m;
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    // n개 입력받고
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    // 오름차순 정렬
    sort(v.begin(), v.end());
    cin >> m;
    // 입력받으면서 이진탐색
    for(int i=0; i<m; i++)
    {
        int num;
        cin >> num;
        cout << binary_search(v.begin(), v.end(), num) << " ";
    }
    cout << "\n";
    return;
}
int main()
{
    fastIO();
    input();
    return 0;
}