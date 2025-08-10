#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) 
{
    unordered_map<int, int> typeCnt;
    int answer = 0;
    
    for (int i=0; i<tangerine.size(); i++)
    {
        typeCnt[tangerine[i]]++;
    }
    
    vector<int> typeVec;
    for (auto& cnt : typeCnt)
    {
        typeVec.push_back(cnt.second);
    }
    
    sort(typeVec.begin(), typeVec.end(), greater<>());
    
    for (auto& cnt : typeVec)
    {
        if (k == 0) break;
        if (cnt > k)
        {
            answer++;
            break;
        }
        k -= cnt;
        answer++;
    }
    
    
    return answer;
}