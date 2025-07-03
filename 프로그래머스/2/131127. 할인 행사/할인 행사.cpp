#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool matchCheck(vector<string>& want, vector<int>& number, vector<string>& discount,  unordered_map<string, int>& disMap)
{
            
    for (int j=0; j < want.size(); j++)
    {
        if (number[j] != disMap[want[j]])
        {
            return false;
        }
    }
    
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> disMap;
    
    for (int i = 0; i < discount.size(); i++)
    {
 
        if (i > 9)
            disMap[discount[i-10]]--;
        disMap[discount[i]]++;

        if (matchCheck(want, number, discount, disMap)) answer++;
        
    }
  
    return answer;
}