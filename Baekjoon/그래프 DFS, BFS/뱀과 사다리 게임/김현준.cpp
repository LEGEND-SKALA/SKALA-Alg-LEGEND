#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int maxpoint =101;
int ls[maxpoint];
int visited[maxpoint];
void bfs(){
    fill(visited,visited+maxpoint,-1);
    visited[1]=0;
    queue<int> q;
    q.push(1); 
    while(!q.empty()){
        int c=q.front();
        q.pop();
        for(int i=1;i<7;i++)
            {
                int next = c+i;
                if(next==100)
                {
                    cout<<visited[c]+1;
                    return;
                }
                else if(next<100)
                {
                    while(ls[next]!=0)
                        next=ls[next];
                    if(visited[next]==-1)
                    {
                        q.push(next);
                        visited[next]=visited[c]+1;
                    }
                }
            }
}
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m,t,t2;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>t>>t2;
        ls[t]=(t2);        
    }
    for(int i=0;i<m;i++)
    {
        cin>>t>>t2;
        ls[t]=t2;
    }
    bfs();
    return 0;
}