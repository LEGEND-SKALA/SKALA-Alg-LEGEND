#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 창고 다각형 (2304)
// https://www.acmicpc.net/problem/2304
// 완전탐색 Alg.
int n, l, h, ret, maxH, maxIdx;
int arr[1004];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 입력 받으며 최댓값 + 해당하는 idx값 구하기
void input()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> l >> h;
        arr[l] = h;
        if(h > maxH)
        {
            maxH = h;
            maxIdx = l;
        }
    }
    return;
}
void solve()
{
    int maxL = 0, maxR = 0;
    // 최댓값 기준 좌측까지 비교 + 합 구하기
    for(int i=1; i<maxIdx; i++)
    {
        maxL = max(maxL, arr[i]);
        ret += maxL;
    }
    // 최댓값 기준 우측까지 비교 + 합 구하기
    for(int i=1000; i>maxIdx; i--)
    {
        maxR = max(maxR, arr[i]);
        ret += maxR;
    }
    cout << ret + maxH << "\n";
}
int main()
{
    fastIO();
    input();
    solve();
    return 0;
}