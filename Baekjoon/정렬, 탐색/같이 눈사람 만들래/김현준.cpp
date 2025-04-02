#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int num,num_2,sumA,sumB,num_left,num_right,ans = INT_MAX;
vector<int> arr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>num;
    for(int i=0;i<num;i++)
    {
        cin>>num_2;
        arr.push_back(num_2);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<num-3;i++)
        for(int j=i+3;j<num;j++)
        {
            sumA=arr[i]+arr[j];
            num_left=i+1;
            num_right=j-1;
            while(num_left<num_right){
                sumB =arr[num_left]+arr[num_right];
                ans = min(abs(sumA-sumB),ans);
                if(ans==0)
                {
                    cout<<ans<<"\n";
                    exit(0);
                }
                if(sumA>sumB)
                    num_left++;
                else
                    num_right--;
            }
        }
    cout<<ans<<"\n";
    return 0;
}
