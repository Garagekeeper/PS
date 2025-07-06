#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;
    for (int i=0; i<commands.size(); i++)
    {
        int left = commands[i][0]-1;
        int right = commands[i][1]-1;
        int target = commands[i][2]-1;
        temp = vector<int>(array.begin() + left, array.begin() + right + 1);
        sort(temp.begin(), temp.end());;
        answer.push_back(temp[target]);
    }
    return answer;
}