#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) 
{
    int answer = 0;
    
    long long sum1 = 0;
    long long sum2 = 0;
    long long total = 0LL;
    int max1 = 0;
    int max2 = 0;
    
    queue<int> q1;
    queue<int> q2;
    
    for (auto& f1 : queue1)
    {
        q1.push(f1);
        max1 = max(max1, f1);
        sum1 += f1;
    }
    
    for (auto& f2 : queue2)
    {
        q2.push(f2);
        max2 = max(max2, f2);
        sum2 += f2;
    }
    
    total = sum1 + sum2;
    
    if (total % 2 != 0) return -1;
    if (total / 2 < max1) return -1;
    if (total / 2 < max2) return -1;
    
    while(true)
    {
        //cout << sum1 <<"," << sum2 << endl;
        if (answer > 600'001) return -1;
        if (sum1 == sum2) break;
        if (abs(total/2 - sum1) < (abs(total/2 - sum2)))
        {
            sum1 += q2.front();
            sum2 -= q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        else if (abs(total/2 - sum1) > (abs(total/2 - sum2)))
        {
            sum1 -= q1.front();
            sum2 += q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else 
        {
            if (sum1 > sum2)
            {
                sum1 -= q1.front();
                sum2 += q1.front();
                q2.push(q1.front());
                q1.pop();
            }
            else 
            {
                sum1 += q2.front();
                sum2 -= q2.front();
                q1.push(q2.front());
                q2.pop();
            }
        }
        answer++;
    }
    
    
    return answer;
}