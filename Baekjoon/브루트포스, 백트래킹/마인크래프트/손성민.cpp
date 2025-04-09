#include <iostream>
using namespace std;

// 마인크래프트 (18111)
// https://www.acmicpc.net/problem/18111
// Brute-Force Alg.
// 시간복잡도: O(n^3) -> n*m*(높이차)
// 공간복잡도: O(1)
const int _max = 501;
int n, m, ground[_max][_max];
int minHeight = 256, maxHeight, minTime = 1e18, ret, b;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 최적화 위해 주어진 땅에서의 최대/최소 높이를 구함
void input()
{
    cin >> n >> m >> b;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> ground[i][j];
            if(ground[i][j] > maxHeight) maxHeight = ground[i][j];
            if(ground[i][j] < minHeight) minHeight = ground[i][j];
        }
    }
    return;
}
// 완전탐색
void solve()
{
    int height, sum;
    // 최소높이에서 최대높이 범위 내에서 땅의 모든 경우의 수를 확인
    for(int k=minHeight; k<=maxHeight; k++)
    {
        // 땅에서 제거해야 할지, 추가해야 할지
        int pop = 0, push = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                // 땅의 높이에서 인덱스 높이를 빼서
                // 0보다 크면 큰 만큼 땅을 파야 함
                // 0보다 작으면 작은 만큼 땅을 채워야 함
                height = ground[i][j] - k;
                if(height > 0) pop += height;
                else if(height < 0) push -= height;
            }
        }
        // 인벤토리에 존재하는 블록 수 + 제거해서 인벤토리에 넣을 블록 수 >= 인벤토리에서 가져와서 쌓아야 할 블록 수
        if(pop + b >= push)
        {
            sum = pop * 2 + push;
            if(sum <= minTime) 
            {
                minTime = sum;
                ret = k;
            }
        }
    }
    return;
}
int main()
{
    fastIO();
    input();
    solve();
    cout << minTime << " " << ret << "\n";
    return 0;
}