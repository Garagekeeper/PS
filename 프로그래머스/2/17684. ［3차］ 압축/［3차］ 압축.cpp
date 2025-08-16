#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string msg) 
{
    vector<int> answer;
    unordered_map<string, int> pressMap;
    int cnt=0;
    for (auto& c : msg)
    {
        string s(1,c);
        pressMap[s] = c- 'A' + 1;
    }
    
    string currStr="";
    for (int i=0; i<msg.size(); i++)
    {
        currStr += msg[i];
        // 못찾으면 추가  
        if (pressMap.find(currStr + msg[i+1]) == pressMap.end())
        {
            answer.push_back(pressMap[currStr]);
            pressMap[currStr + msg[i+1]] = 27 + (cnt++);
            currStr="";
        }

    }
    return answer;
}