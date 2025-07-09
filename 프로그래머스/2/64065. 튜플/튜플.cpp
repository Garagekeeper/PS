#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> setVec;
    set<int> answerSet;
    
    bool canInsert = false;
    int index = 0;
    string temp = "";
    for (auto it = s.begin() + 1; it != s.end() - 1; ++it)
    {
        if (canInsert && ( '0'<= *it && *it <= '9'))
        {
            temp += *it;
        }
        if (canInsert && *it == ',')
        {
            setVec[index].push_back(stoi(temp));
            temp = "";
        }
        
        if (*it == '{')
        {
            canInsert = true;
            setVec.push_back(vector<int>());
        }
            
        if (*it == '}')
        {
            canInsert = false;
            setVec[index].push_back(stoi(temp));
            temp = "";
            index++;
        }
    }
    
    sort(setVec.begin(), setVec.end(), [](const vector<int> a, const vector<int> b){
        return a.size() < b.size();
    });
    
    for (auto& vec : setVec)
    {
        for (auto& e : vec)
        {
            if (answerSet.find(e) == answerSet.end())
            {
                answerSet.insert(e);
                answer.push_back(e);
            }
        }
    }
    
    return answer;
}