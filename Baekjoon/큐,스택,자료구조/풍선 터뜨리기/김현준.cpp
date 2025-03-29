#include<iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int length=0;
    int arr[1000];
    int ans[1000];
    bool broken[1000] ={0};
    int pos=0;
    std::cin >>length;
    for(int i=0;i<length;i++)
    {
        std::cin>>arr[i];
        if(arr[i]==0)
            exit(1);
    }
    ans[0]=pos+1;
    broken[pos]=1;
    for(int i=1;i<length;i++)
    {
        int dir=arr[pos];
        if(dir>0)
        {
            while(dir!=0)
            {
                if(++pos>length-1)
                    pos-=length;
                if(broken[pos]==0)
                    dir--;
            }
        }
        else
        {
            while(dir!=0)
            {
                if(--pos<0)
                    pos+=length;
                if(broken[pos]==0)
                    dir++;
            }

        }
        ans[i]=pos+1;
        broken[pos]=1;

    }
    for(int i=0;i<length;i++)
    {
        std::cout<<ans[i];
        if(i<length-1)
            std::cout<<" ";
    }
    std::cout << std::endl;

    return 0;
}
