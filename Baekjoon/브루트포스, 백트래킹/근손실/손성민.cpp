#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 근손실 (18429)
// https://www.acmicpc.net/problem/18429
// Brute Force - 순열 Alg.
// 시간복잡도: O(n!): n<=8이기에 브루트포스 가능
// 공간복잡도: O(n)
int n, k, ret, weight;
vector<int> weights;
void fastIO()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    return;
}
void input()
{
    cin >> n >> k;
    for(int i=0; i<n; i++) 
    {
        cin >> weight;
        weights.push_back(weight);
    }
    return;
}
// 순서대로 운동을 할 때, 500보다 작아지는 지 확인하는 함수
bool check()
{
    int sum = 500;
    for(int i=0; i<n; i++)
    {
        sum -= k; sum += weights[i];
        if(sum < 500) return false;
    }
    return true;
}
// 순열 로직
void makePermutation(int depth)
{
    if(depth == n)
    {
        if(check()) ret++;
        return;
    }
    // 깊이 개념을 이용, swap - 재귀 - swap
    for(int i=depth; i<n; i++)
    {
        swap(weights[i], weights[depth]);
        makePermutation(depth + 1);
        swap(weights[i], weights[depth]);
    }
}
int main()
{
    fastIO();
    input();
    makePermutation(0);
    cout << ret << "\n";
}