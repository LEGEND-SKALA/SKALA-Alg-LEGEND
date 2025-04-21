#include<iostream>
#include<vector>
using namespace std;
int n,t,t2,m;
vector<int> nv;
vector<pair<int,int>> vp;
bool ans[2001][2001];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        nv.push_back(t);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>t>>t2;
        vp.push_back(make_pair(t,t2));
    }
    for(int i=0;i<n;i++) ans[i][i]=1;
    for(int i=0;i<n-1;i++)if(nv[i]==nv[i+1])ans[i][i+1]=1;
    for (int len = 3; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            if (nv[i] == nv[j] && ans[i + 1][j - 1])
                ans[i][j] = true;
        }
    }
    for(int i=0;i<vp.size();i++)cout<<ans[vp[i].first-1][vp[i].second-1]<<"\n";
    return 0;
}
