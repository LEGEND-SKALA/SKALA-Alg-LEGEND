#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
int num,num_input;
int ans=INT_MAX;
int num_min=INT_MAX;
int arr_ans[2];
int value=0;
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
    int i=0;
    int j=num-1;
    while(i<j)
    {
        value = arr[i]+arr[j];
        if(num_min>abs(value))
        {
            num_min = abs(value);
            if(num_min<ans)
            {
                ans=num_min;
                arr_ans[0]=arr[i];
                arr_ans[1]=arr[j];
                if(ans==0)
                    break;
            }
        }
        if(value<0)
            i++;
        else
            j--;   
    }
    
    
    cout<<arr_ans[0]<<" "<<arr_ans[1]<<"\n";

    return 0;
}
