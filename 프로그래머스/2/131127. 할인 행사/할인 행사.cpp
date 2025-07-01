#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> disMap;
    for (int i = 0; i < 10; i++)
    {
        disMap[discount[i]]++;
    }
    
    bool match = true;
    for (int i=0; i<want.size(); i++)
    {
        if (number[i] != disMap[want[i]])
            {
                match = false;
                break;
            }
    }
    
    if (match) answer++;
    
    for (int i = 10; i<discount.size(); i++)
    {
        disMap[discount[i-10]]--;
        disMap[discount[i]]++;
        
        bool match = true;
        for (int j=0; j < want.size(); j++)
        {
            if (number[j] != disMap[want[j]])
            {
                match = false;
                break;
            }
        }
        if (match) answer++;

    }
    return answer;
}