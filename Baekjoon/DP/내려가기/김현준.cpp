#include <iostream>
#include <vector>
using namespace std;
int arr[100001][3];
int minans[3];
int maxans[3];
int main() {
    int N;
    cin >> N;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<3;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<3;i++)
    {
        minans[i]=maxans[i]=arr[0][i];
    }
    for(int i=1;i<N;i++)
    {
        int temp_min[3], temp_max[3];
        temp_min[0]=min(minans[0],minans[1])+arr[i][0];
        temp_min[1]=min(minans[0],min(minans[1],minans[2]))+arr[i][1];
        temp_min[2]=min(minans[1],minans[2])+arr[i][2];

        temp_max[0]=max(maxans[0],maxans[1])+arr[i][0];
        temp_max[1]=max(maxans[0],max(maxans[1],maxans[2]))+arr[i][1];
        temp_max[2]=max(maxans[1],maxans[2])+arr[i][2];
        for (int j=0;j<3;j++) {
            minans[j] = temp_min[j];
            maxans[j] = temp_max[j];
        }
    }
    cout<<max(maxans[0],max(maxans[1],maxans[2]))<<" "<<min(minans[0],min(minans[1],minans[2]));
    return 0;
}
