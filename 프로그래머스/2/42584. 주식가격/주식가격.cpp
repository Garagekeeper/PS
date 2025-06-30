#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) 
{
    vector<int> answer(prices.size(), 0);
    stack<int> priceStack;
    // 각 원소는 한번씩 push 와 pop을 한다.
    // 즉 N개 원소는 각각 N번의 push N번의 pop을 한다.
    // 2N -> O(N)
    for (int i=0; i<prices.size(); i++)
    {
        while(!priceStack.empty() && prices[priceStack.top()] > prices[i])
        {
            answer[priceStack.top()] = i - priceStack.top();
            priceStack.pop();
        }
        
        priceStack.push(i);
    }
    
    while(!priceStack.empty())
    {
        answer[priceStack.top()] = prices.size() - 1 - priceStack.top();
        priceStack.pop();
    }
    
    return answer;
}