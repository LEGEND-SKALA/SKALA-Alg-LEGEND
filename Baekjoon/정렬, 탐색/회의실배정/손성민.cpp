#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 회의실 배정 (1931)
// 그리디, 정렬 Alg.
int N, from, to, ret=1;
vector<pair<int,int>> v;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> from >> to;
        v.push_back({to,from});
    }
}
// 정렬, 그리디
void solve()
{
    // 정렬 -> (끝나는 시간)의 오름차순으로 (끝나는 시간, 시작 시간) 정렬
    sort(v.begin(), v.end());
    from = v[0].second;
    to = v[0].first;
    // 앞에서부터 차례로 탐색
    for(int i=1; i<N; i++){
        // 현재 회의의 끝나는 시간이 다음 회의의 시작시간보다 느리면,
        if(v[i].second < to) continue;
        from = v[i].second; 
        to = v[i].first; 
        ret++;
    }
    cout << ret << "\n"; 

    for(pair<int,int> p : v) cout << p.first << " : " << p.second << "\n";
}
int main(){
    fastIO();
    input();
    solve();
    return 0;
}