#include <iostream>
#include <vector>
using namespace std;

// 햄버거 분배 (19941)
// https://www.acmicpc.net/problem/19941
// Greedy Alg.
// 시간복잡도: O(nk)
// 공간복잡도: O(1)

/*
- 벤치 모양의 식탁에 사람 - 햄버거가 단위 간격으로 놓여 있음
- 사람들은 자신의 위치에서 거리가 K이하인 햄버거만 먹을 수 있음
- 식탁의 길이 N, 햄버거를 선택할 수 있는 거리 K, 사람과 햄버거의 위치가 주어졌을 때 햄버거를 먹을 수 있는 사람의 최대 수 구하기
- 문자열로 사람(P)과 햄버거(H)의 위치가 주어짐
*/
int n, k, ret;
string str;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> n >> k;
    cin >> str;
    return;
}
// 좀 더럽게 풀었습니다.
void solve()
{
    // 문자열 순회
    for(int i=0; i<str.size(); i++)
    {
        if(str[i] == 'H') continue;
        // 사람일 때
        else if(str[i] == 'P')
        {
            // [i-k, i+k] 범위를 확인
            for(int j=i-k; j<=i+k; j++)
            {
                // 인덱스가 0보다 작거나 i와 같지 않을 때
                if(j < 0 || j == i) continue;
                // 햄버거를 먹을 수 있다면
                if(str[j] == 'H')
                {
                    // 결과값에 더해주고 그 위치를 이상한 값으로 대체
                    ret++;
                    str[j] = 'Q';
                    break;
                }
            }
        }
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