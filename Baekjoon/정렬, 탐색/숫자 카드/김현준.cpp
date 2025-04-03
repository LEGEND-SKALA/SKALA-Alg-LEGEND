#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int num,num_input;
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
    cin>>num;
    while(num--)
    {
        cin>>num_input;
        cout<<binary_search(arr.begin(),arr.end(),num_input)<<' ';
    }

    return 0;
}
