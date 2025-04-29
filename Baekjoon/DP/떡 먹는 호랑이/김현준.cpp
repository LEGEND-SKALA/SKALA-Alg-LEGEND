#include <iostream>
#include <vector>
using namespace std;
int arr[100000];
int main() {
    int N, K;
    cin >> N >> K;
    arr[0]=K;
    for(int i=K-1;i>0;i--)
    {
        arr[1]=i;
        for(int j=2;j<N;j++)
        {
            arr[j]=arr[j-2]-arr[j-1];
            if(arr[j]>arr[j-1])
                break;
            if(j==(N-1))
            {
                cout<<arr[j]<<"\n"<<arr[j-1];            
                return 0;
            }
        }
    }
    return 0;
}
