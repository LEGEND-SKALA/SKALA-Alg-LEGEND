#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxpoint =1001;
vector<int> pv[maxpoint];
bool visited[maxpoint];
void dfs(int s){
    if(visited[s])
        return;
    visited[s]=1;
    cout<<s<<' ';
    for(int i=0;i<pv[s].size();i++)
    {
        dfs(pv[s][i]);    
    }
}
void bfs(int s){
    fill(visited,visited+maxpoint,0);
    queue<int> q;
    q.push(s);
    visited[s]=1; 
    while(!q.empty()){
        int c=q.front();
        q.pop();
        cout<<c<<' ';
        for(int i=0;i<pv[c].size();i++)
        {
            int next =pv[c][i];
            if(!visited[next])
            {
                q.push(next);
                visited[next]=true;
                
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,v,t,t2;
    cin>>n>>m>>v;
    for(int i=0;i<m;i++)
    {
       cin>>t>>t2;
       pv[t].push_back(t2);
       pv[t2].push_back(t);
    }
    for (int i = 1; i <= n; i++) {
        sort(pv[i].begin(), pv[i].end());  // 번호 작은 순서로 정렬
    }
    dfs(v);
    cout<<"\n";
    bfs(v);
    return 0;
}