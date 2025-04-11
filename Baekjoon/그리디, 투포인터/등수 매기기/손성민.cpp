#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 등수 매기기 (2012)
// https://www.acmicpc.net/problem/2012
// Greedy, Sort Alg.
// 시간복잡도: O(nlogn)
// 공간복잡도: O(n)

/*
- N명의 학생들
- 모든 학생들은 자신이 N명 중에서 몇 등을 할 것인지 예상 등수를 적어서 제출
- 제출본 사라져서 임의로 등수를 매겨야 함
- 예상 A등, 실제 B등 => 불만도 abs(A - B)
- 불만도를 최소로 하는 등수를 매겨야 함
*/
int n, r, idx = 1;
long long ret;
vector<int> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void checkIO(int num)
{
    if(num < 1 || num > 500000) exit(1);
    return;
}
// 정렬 후, 처음부터 끝까지, 랭크와 예상 등수 비교
void input()
{
    cin >> n;
    checkIO(n);
    for(int i=0; i<n; i++)
    {
        cin >> r;
        checkIO(r);
        v.push_back(r);
    }
    return;
}
void solve()
{
    // 정렬 (오름차순)
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++)
    {
        ret += abs(v[i] - idx++);
    }
    cout << ret << "\n";
    return;
}
int main()
{
    fastIO();
    input();
    solve();
    return 0;
}