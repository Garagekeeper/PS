#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void Combination(string src, string current, int depth, unordered_map<string, int>& map)
{
    if (current.size() == depth)
        map[current]++;
    else
        for (int i = 0; i < src.size(); i++)
            //i번째 문자를 선택하고, i+1부터의 문자열로 재귀
            Combination(src.substr(i + 1), current + src[i], depth, map);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    unordered_map<string, int> orderLog;
    int maxOrder = 0;
    for (int i = 0 ; i < orders.size() ; i++)
    {
        sort(orders[i].begin(), orders[i].end());
    }
    
    for (int i = 0 ; i < course.size() ; i++)
    {
        for (int j = 0 ; j < orders.size() ; j++)
        {
             Combination(orders[j], "", course[i], orderLog);
        }
        
        maxOrder = 0;
            
        for (auto& e : orderLog)
        {
            maxOrder = max(maxOrder, e.second);
        }
        
        for (auto& [first, second] : orderLog)
        {
            if (second >= 2 && second == maxOrder) answer.push_back(first);
        }
        orderLog.clear();
    }
    sort(answer.begin(), answer.end());
    
    return answer;
}