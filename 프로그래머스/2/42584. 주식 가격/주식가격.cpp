#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer(prices.size(), 0);
    stack<pair<int, int>> priceStack;
    int time = 0;
    // 각 원소는 한번씩 push 와 pop을 한다.
    // 즉 N개 원소는 각각 N번의 push N번의 pop을 한다.
    // 2N -> O(N)
    for (auto it = prices.begin(); it != prices.end(); ++it)
    {
        time++;
        
        // top이 현재 가격보다 작거나 같을때 까지 pop
        while (!priceStack.empty() && priceStack.top().first > *it)
        {
            int insertTime = priceStack.top().second;
            priceStack.pop();
                    
            //삽입된 시점에 가격을 유지한 시간 기록
            answer[insertTime - 1] = time - insertTime;
        }
        priceStack.push(make_pair(*it, time));
    }

    
    while(!priceStack.empty())
    {
        int insertTime = priceStack.top().second;
        priceStack.pop();
        answer[insertTime - 1] = time - insertTime;
    }
    
    return answer;
}
