#include <iostream>
using namespace std;

// 셀프 넘버(4673)
// https://www.acmicpc.net/problem/4673
// 구현 - Brute Force Alg.
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
int selfNum(int num)
{
    for(int i=1; i<num; i++)
    {
        int sum = 0, tmp = i;
        while(tmp)
        {
            sum += tmp%10;
            tmp /= 10;
        }
        if(i+sum == num) return 0;
    }
    return 1;
}
int main()
{
    fastIO();
    for(int i=1; i<=10000; i++) if(selfNum(i)) cout << i << "\n";
    return 0;
}