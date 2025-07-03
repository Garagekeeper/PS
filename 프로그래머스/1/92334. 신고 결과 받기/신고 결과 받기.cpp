#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    unordered_map<string, int> mailList;
    unordered_map<string, unordered_set<string>> reportLog;
    
    for (auto& e : report)
    {
        stringstream ss(e);
        string from;
        string to;
        
        ss >> from >> to;
        
        reportLog[to].insert(from);
    }
    
    for (auto& v : reportLog)
    {
        if (v.second.size() >= k)
        {
            for (auto& from : v.second)
            {
                mailList[from]++;
            }
        }
    }
    
    
    for (int i=0; i<id_list.size(); i++)
    {
        string id = id_list[i];
        answer.push_back(mailList[id]);
    }
    
    return answer;
}