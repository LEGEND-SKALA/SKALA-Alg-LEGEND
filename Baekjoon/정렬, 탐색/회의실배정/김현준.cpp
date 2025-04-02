#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int num,num_input, num_input_sec,ans=0,num_end;
vector<pair<int,int>> arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>num_input;
        cin>>num_input_sec;
        arr.push_back(make_pair(num_input_sec,num_input));
    }
    sort(arr.begin(),arr.end());
    num_end = arr[0].first;
    ans = 1;
    for (int i = 1; i <= num; i++)
    {
        if (arr[i].second >= num_end)
        {
            ans++;
            num_end = arr[i].first;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
