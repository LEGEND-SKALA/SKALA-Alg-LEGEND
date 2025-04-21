#include<iostream>
#include<vector>
using namespace std;
int c,p;
vector<int> ans;
void sol(pair<int,int> pr){
    if(pr.first==0)
    {
        ans.push_back(pr.second);
        return;
    }
    if(pr.first>=1)
    {
        pair<int,int> pr2=pr;
        pr2.first-=1;
        pr2.second*=1.05;
        sol(pr2);
    }
    if(pr.first>=3)
    {
        pair<int,int> pr2=pr;
        pr2.first-=3;
        pr2.second*=1.2;
        sol(pr2);
    }
    if(pr.first>=5)
    {
        pair<int,int> pr2=pr;
        pr2.first-=5;
        pr2.second*=1.35;
        sol(pr2);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>p;
    sol(make_pair(p,c));
    int mx=0;
    for(int i=0;i<ans.size();i++)
        mx=max(ans[i],mx);
    cout<<mx;
    
    return 0;
}
