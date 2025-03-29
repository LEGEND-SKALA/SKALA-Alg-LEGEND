#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int card_count=0;
    int task_count=0;
    long long number=0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    cin>>card_count>>task_count;
    for(int i=0;i<card_count;i++)
    {
        cin>>number;
        pq.push(number);
    }
    for(int i=0;i<task_count;i++)
    {
        number=0;
        for(int j=0;j<2;j++)
        {
            number+=pq.top();
            pq.pop();
        }
        for(int j=0;j<2;j++)
        {
            pq.push(number);
        }
    }
    long long sum=0;
    while(!pq.empty())
    {
        sum+=pq.top();
        pq.pop();
    }
    cout <<sum<< endl;
    return 0;
}
