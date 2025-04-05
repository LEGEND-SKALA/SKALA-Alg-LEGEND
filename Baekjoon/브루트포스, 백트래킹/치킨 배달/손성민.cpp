#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 치킨 배달 (15686)
// Brute Force Alg.
// https://www.acmicpc.net/problem/15686
// 공간복잡도: O(n)
// 시간복잡도: O(nCm x hm)
const int INF = 987654321;
int n, m, ret = INF, num;
vector<pair<int,int>> chicken;
vector<pair<int,int>> house;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
// 입력, 1이면 house, 2이면 chicken
void input()
{
    cin >> n >> m;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++) 
        {
            cin >> num;
            if(num == 2) chicken.push_back({i, j});
            if(num == 1) house.push_back({i, j});
        }
    }
    return;
}
// 집들과 치킨집의 최단거리 합 구하기
void findMinDist(vector<pair<int,int>> &selectedChicken)
{
    int sum = 0;
    // 모든 집들을 순회하며
    for(pair<int,int> home : house)
    {
        int _min = INF;
        // 조합으로 선택한 m개의 치킨집들을 순회
        for(pair<int,int> chickens : selectedChicken)
        {
            // 하나의 집과 모든 치킨집과의 거리를 구해 최단거리를 구함
            _min = min(_min, abs(home.first - chickens.first) + abs(home.second - chickens.second));
        }
        sum += _min;
    }
    ret = min(ret, sum);
    return;
}
// 조합 코드 (nCm)
// vector를 사용
// for문을 통해 모든 인덱스를 순회하며, ('push' - '재귀' - 'pop') 과정을 반복
void combi(int start, vector<pair<int,int>> &selectedChicken)
{
    if(selectedChicken.size() == m)
    {
        findMinDist(selectedChicken);
        return;
    }
    for(int i=start+1; i<chicken.size(); i++)
    {
        selectedChicken.push_back({chicken[i].first, chicken[i].second});
        combi(i, selectedChicken);
        selectedChicken.pop_back();
    }
    return;
}
void solve()
{
    vector<pair<int,int>> selectedChicken;
    combi(-1, selectedChicken);
    return;
}
int main()
{
    fastIO();
    input();
    solve();
    cout << ret << "\n";
}