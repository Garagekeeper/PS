#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    unordered_map<string, string> userMap;
    vector<pair<string, string>> actions;
    
    for (const string& line : record) {
        size_t space1 = line.find(' ');
        size_t space2 = line.find(' ', space1 + 1);
        string cmd = line.substr(0, space1);
        string uid = line.substr(space1 + 1, space2 - space1 - 1);

        if (cmd == "Enter") {
            string name = line.substr(space2 + 1);
            userMap[uid] = name;
            actions.push_back({uid, "님이 들어왔습니다."});
        }
        else if (cmd == "Leave") {
            actions.push_back({uid, "님이 나갔습니다."});
        }
        else if (cmd == "Change") {
            string name = line.substr(space2 + 1);
            userMap[uid] = name;
        }
    }

    vector<string> answer;
    for (auto& [uid, action] : actions) {
        answer.push_back(userMap[uid] + action);
    }

    return answer;
}
