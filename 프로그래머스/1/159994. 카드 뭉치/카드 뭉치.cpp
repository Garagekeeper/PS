#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    int index1 =0 , index2 = 0;
    bool found = true;
    for (int i = 0; i < goal.size(); i++)
    {
        auto target = goal[i];
        if (index1 <  cards1.size() && cards1[index1] == target)
        {
            index1++;
        }
        else if (index2 <  cards2.size() && cards2[index2] == target) 
        {
            index2++;
        }
        else 
        {
            found = false;
            break;
        }
    }
    
    answer = found ? "Yes" : "No";
    
    return answer;
}