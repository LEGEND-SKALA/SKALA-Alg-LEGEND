#include <iostream>
#include <queue>
using namespace std;

int n, m, t1, t2, loc, cnt, mp[102], vis[102];
queue<pair<int, int>> q;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> t1 >> t2, mp[t1] = t2;
    for (int i = 0; i < m; ++i) cin >> t1 >> t2, mp[t1] = t2;
    q.push(make_pair(1, 0)); while(q.size()){
        loc = q.front().first; cnt = q.front().second; q.pop();
        for (int i = 1; i <= 6;i++){
            int nx = loc + i;
            if(nx == 100){
                cout << cnt + 1; return 0;
            }
            else if(nx < 100){
                while(mp[nx]) nx = mp[nx];
                if(!vis[nx]) q.push(make_pair(nx, cnt + 1)), vis[nx] = true;
            }
        }
    }
}