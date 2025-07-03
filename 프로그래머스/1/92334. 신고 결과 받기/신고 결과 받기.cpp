#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    // 받은 메일 개수 저장
    unordered_map<string, int> mailList;
    // 유저가 누구한테 신고 당했는지
    unordered_map<string, unordered_set<string>> reportLog;
    
    // 누가 누굴 신고했는지 기록
    for (auto& e : report)
    {
        stringstream ss(e);
        string from;
        string to;
        
        ss >> from >> to;
        
        reportLog[to].insert(from);
    }
    
    // K회 이상 신고 당하면 신고한 사람들에게 메일
    for (auto& [to, from] : reportLog)
    {
        if (from.size() >= k)
        {
            for (auto& id : from)
            {
                mailList[id]++;
            }
        }
    }
    
    // 신고를 하지 않은 유저는 안만들어짐.
    // mailList[id]를 통해서 없으면 만들어지는 과정이 들어감
    for (int i=0; i<id_list.size(); i++)
    {
        string id = id_list[i];
        answer.push_back(mailList[id]);
    }
    
    return answer;
}