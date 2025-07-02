#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string , string> userInfo;
    for (auto it = record.begin(); it != record.end(); ++it)
    {
        if ((*it)[0] == 'E' || (*it)[0] == 'C')
        {
            auto startPos = (*it).find(" ") + 1;
            auto endPos = (*it).find(" ", startPos);
            
            string uid = (*it).substr(startPos, endPos - startPos);
            string nickName = (*it).substr(endPos + 1);
            userInfo[uid] = nickName;
        }
    }
    
    for (auto it = record.begin(); it != record.end(); ++it)
    {
        string res = "";
        if ((*it)[0] == 'E')
        {
            auto startPos = (*it).find(" ") + 1;
            auto endPos = (*it).find(" ", startPos);
            string uid = (*it).substr(startPos, endPos - startPos);
            res += (userInfo[uid] + "님이 들어왔습니다.");

        }
        else if ((*it)[0] == 'L')
        {
            auto startPos = (*it).find(" ") + 1;
            string uid = (*it).substr(startPos);
            res += (userInfo[uid] + "님이 나갔습니다.");
        }
        else
            continue;
        answer.push_back(res);
    }
    
    return answer;
}
