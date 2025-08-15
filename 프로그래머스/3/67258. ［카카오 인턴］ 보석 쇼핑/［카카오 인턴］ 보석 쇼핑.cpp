#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <climits>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> gems) 
{
    vector<int> answer;
    // 전체 종류를 답는 집합
    unordered_set<string> gemTypeSet;

    unordered_map<string, int> ansMap;
    // 보석 종류를 집합으로 만든다.
    for (auto& gem : gems)
    {
        gemTypeSet.insert(gem);
    }
    
    //cout << gemTypeSet.size() ;
    
    int left = 0;
    int right = 0;
    int from = 0;
    int len = gems.size();
    int minimum = len + 1;
    int start =0;
    int end=0;
    ansMap[gems[0]]++;
    while(right < len)
    {
        // 전체 종류와 개수가 같을 때
        if (ansMap.size() == gemTypeSet.size())
        {
            if (right - left + 1 < minimum)
            {
                minimum = right - left + 1;
                start = left;
                end = right;
            }
            ansMap[gems[left]]--;
            if (ansMap[gems[left]] == 0)
            {
                ansMap.erase(gems[left]);
            }
                
            left++;
            //cout << ansMap[gems[i]];
        }
        
        // 전체 종류보다 개수가 적으면 넣기
        else 
        {
            right++;
            if (right < len)
                ansMap[gems[right]]++;
        }
    }
    
    return {start+1, end+1};
}