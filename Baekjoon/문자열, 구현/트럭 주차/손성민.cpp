#include <iostream>
using namespace std;

// 트럭 주차 (2979)
// https://www.acmicpc.net/problem/2979
// 구현 Alg - 구간 파악하기 (마킹)
int A, B, C, ret;
int park[101];
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void solution()
{
    cin >> A >> B >> C;
    if(A<1 || A>100 || B<1 || B>100 || C<1 || C>100) exit(1);
    for(int i=0; i<3; i++)
    {
        int in, out;
        cin >> in >> out;
        if(in<1 || in>100 || out<1 || out>100 || in > out) exit(1); 
        for(int j=in; j<out; j++) park[j]++;
    }
    for(int i=1; i<=100; i++)
    {
        if(park[i] == 1) ret += A;
        else if(park[i] == 2) ret += B*2;
        else if(park[i] == 3) ret += C*3;
    }
    cout << ret << "\n";
    return;
}
int main()
{
    fastIO();
    solution();
    return 0;
}