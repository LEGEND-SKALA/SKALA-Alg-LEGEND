#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 스도쿠 (2580)
// https://www.acmicpc.net/problem/2580
// 백 트래킹 Alg.
// 시간복잡도: O(9^k)
// 공간복잡도: O(1)
const int _size = 9;
int arr[_size][_size];
vector<pair<int,int>> zero;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 입력 (0인 위치 따로 보관)
void input()
{
    for(int i=0; i<_size; i++) 
    {
        for(int j=0; j<_size; j++) 
        {
            cin >> arr[i][j];
            if(arr[i][j] == 0) zero.push_back({i, j});
        }
    }
    return;
}
// 행, 열, 3x3 체크 하는 함수
bool check(int y, int x, int value)
{
    for(int i=0; i<_size; i++)
    {
        if(arr[i][x] == value && i != y) return false;
        if(arr[y][i] == value && i != x) return false;
    }
    int startY = (y / 3) * 3, startX = (x / 3) * 3;
    for(int i=startY; i<startY+3; i++)
    {
        for(int j=startX; j<startX+3; j++) if(arr[i][j] == value && i != y && j != x) return false;
    }
    return true;
}
void print()
{
    for(int i=0; i<_size; i++) 
    {
        for(int j=0; j<_size; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}
void solution(int idx)
{
    // 만약 zero인 위치를 모두 다 처리했으면 출력 후 종료
    if(idx == zero.size())
    {
        print();
        exit(0);
    }
    // 0인 위치를 확인하며, 1~9를 넣어보고 체크, 체크 성립하면 다음 0인 위치를 재귀로 확인
    for(int i=1; i<=9; i++)
    {
        arr[zero[idx].first][zero[idx].second] = i;
        if(check(zero[idx].first, zero[idx].second, i)) solution(idx+1);
    }
    // 체크되지 않으면 해당 위치 원위치
    arr[zero[idx].first][zero[idx].second] = 0;
    return;
}
int main()
{
    fastIO();
    input();
    solution(0);
    return 0;
}