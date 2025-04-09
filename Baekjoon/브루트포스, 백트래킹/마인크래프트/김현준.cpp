#include<iostream>
#include<cmath>
using namespace std;
int n,m,b,t,sb,ans=1e9,h;
int arr[501][501];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m>>b;
    sb+=b;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            sb+=arr[i][j];
        }
    sb/=(n*m);
    for(int i=0;i<=sb;i++)
    {
        t=0;
        for(int j=0;j<n;j++)
            for(int k=0;k<m;k++)
            {
                if(arr[j][k]==i)
                    continue;
                else if(arr[j][k]<i)
                    t+=(i-arr[j][k]);
                else
                    t+=(arr[j][k]-i)*2;
            }
            if(t<=ans)ans=min(t,ans),h=i;
    }
    cout<<ans<<" "<<h<<"\n";

    return 0;
}
