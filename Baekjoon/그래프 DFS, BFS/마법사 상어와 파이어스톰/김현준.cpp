#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxpoint =100001;
int visited[maxpoint];
void bfs(int s, int m){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int c=q.front();
        if(c==m)
        {
            cout<<visited[c];
            return ;
        }
        q.pop();
        int next[3]={c+1,c-1,c*2};
        for(int i=0;i<3;i++)
        {
            if(next[i]>100001)
                continue;
            if(visited[next[i]]==0)
            {
                q.push(next[i]);
                visited[next[i]]=visited[c]+1;
            }
        }
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    bfs(n,m);
    return 0;
}