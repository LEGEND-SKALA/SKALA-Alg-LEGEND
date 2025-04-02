#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num,num_input;
int ans=0;
vector<int> arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>num_input;
        arr.push_back(num_input);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<num;i++)
    {
        int j=0;
        int k=num-1;
        while(j<k)
        {
            if(arr[i]==(arr[j]+arr[k]))
            {
                if(j!=i && k!=i)
                {
                    ans++;
                    break;
                }
                else if(j==i) j++;
                else if(k==i) k--;
            }
            else if((arr[j]+arr[k])<arr[i])
                j++;
            else
                k--;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
