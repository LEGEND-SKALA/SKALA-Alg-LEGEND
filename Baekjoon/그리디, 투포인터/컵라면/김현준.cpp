#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int n,ans,dm;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int r,d;
        cin>>d>>r;
        v.push_back({d,r});
    }
    sort(v.begin(),v.end(),[](pair<int, int>a, pair<int,int>b){return a.first<b.first;});
    for(int i=0;i<n;i++)
    {
        pq.push(v[i].second);
        if(pq.size()>v[i].first)
            pq.pop();
    }
    while(!pq.empty())
    {
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<"\n";
    return 0;
}
