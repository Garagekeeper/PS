#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> m;
    vector<pair<int, int>> frqv;
    
    string temp="";
    int maxNum = 0;
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        if ( '0' <= *it && *it <= '9')
            temp += *it;
        else
        {
            if (temp == "") continue;
            maxNum = max(maxNum, stoi(temp));
            m[stoi(temp)]++;
            temp="";
        }
        
    }
    
    frqv = vector<pair<int,int>> (m.begin(), m.end());
    
    sort(frqv.begin(), frqv.end(), [](auto& a, auto& b){
        return a.second > b.second;
    });
    
     for (auto& [val, cnt] : frqv)
        answer.push_back(val);
    
    return answer;
}

/*
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> setVec;
    unordered_set<int> answerSet;
    
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
*/