#include<iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int length=0;
    int height[1000]={0};
    std::cin>>length;
    for(int i=0;i<length;i++)
    {
        int pos=0;
        std::cin>>pos;
        std::cin>>height[pos-1];
    }
    int max_index=0;
    //Max Index Find
    for(int i=0;i<1000;i++)if(height[max_index]<height[i])max_index=i;
    //Left Area Define
    int left_max=0;
    int area=0;
    for(int i=0;i<max_index;i++)
    {
        if(left_max<height[i])left_max=height[i];
        area+=left_max;
    }
    //Max Value Add
    area+=height[max_index];
    //Right Area Define
    int right_max=0;
    for(int i=999;i>max_index;i--)
    {
        if(right_max<height[i])right_max=height[i];
        area+=right_max;
    }
    std::cout <<area<< std::endl;
    return 0;
}
