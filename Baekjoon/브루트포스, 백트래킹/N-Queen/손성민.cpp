#include <iostream>
#include <vector>
using namespace std;

// N-Queen(9663)
// https://www.acmicpc.net/problem/9663
// Brute Force - Back Tracking -Alg.
// 시간복잡도: O(n!)
// 공간복잡도: O(1)

/*
- 접근 방식
-> 퀸은 체스 판 위에 + or x 방향으로 공격 가능함 [같은 행/열에 위치하거나 대각선에 위치하면 안되겠다!]
-> 그러면 하나의 행에는 하나의 퀸만 존재 가능하겠네?
-> 조합으로 풀어볼까?
-> 다만 조합은 하나의 행에도 여러 개를 선택하는 방식도 포함하니 조합보다 완전탐색(백트래킹)으로 풀어보자
-> 배열을 선언, 배열의 각 인덱스는 체스판의 각 행을 나타내고, 배열의 각 값은 각 행에서의 열 위치를 나타냄
*/
const int _max = 15;
int n, ret, arr[_max + 1];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
bool check(int idx)
{
    for(int i=0; i<idx; i++)
    {
        // 같은 행에 있는지 확인
        if(arr[i] == arr[idx]) return false;

        // 대각선에 있는지 확인
        if(abs(arr[idx] - arr[i]) == idx - i) return false;
    }
    return true;
}
void solve(int idx)
{
    if(idx == n)
    {
        ret++;
        return;
    }
    // 모든 경우를 확인
    for(int i=0; i<n; i++)
    {
        arr[idx] = i;
        if(check(idx)) solve(idx + 1);
    }
    return;
}
int main()
{
    fastIO();
    cin >> n;
    solve(0);
    cout << ret << "\n";
    return 0;
}
