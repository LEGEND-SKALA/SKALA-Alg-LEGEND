#include <stdio.h>
#include<iostream>

int main(){
    int a,b,c=0;
    int arr[6];
    std::cin >>a>>b>>c>>arr[0]>>arr[1]>>arr[2]>>arr[3]>>arr[4]>>arr[5];
    int time_1[100]={0};   
    int time_2[100]={0};   
    int time_3[100]={0};
    int cost=0;
    for(int i=arr[0];i<arr[1];i++)
        time_1[i]=1;
    for(int i=arr[2];i<arr[3];i++)
        time_2[i]=1;
    for(int i=arr[4];i<arr[5];i++)
        time_3[i]=1;
    for(int i=0;i<100;i++)
    {
        int num = time_1[i]+time_2[i]+time_3[i];
        if(num==3)
            cost+=c*3;
        else if(num==2)
            cost+=b*2;
        else if(num==1)
            cost+=a;
    }
    std::cout<<cost;
}
