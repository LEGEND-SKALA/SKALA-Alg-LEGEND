#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int num;
long long ans=0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num;
    vector<int> arr;
    for(int i=0;i<num;i++)
    {
        int n=0;
        cin>>n;
        arr.push_back(n);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<num;i++)
    {
        ans+=abs((i+1)-arr[i]);
    }
        cout<<ans<<"\n";
    return 0;
}
