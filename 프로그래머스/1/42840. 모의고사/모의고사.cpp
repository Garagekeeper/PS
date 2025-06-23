#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> students = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    vector<int> Ocount(3);
    for (int i=0; i < answers.size(); i++)
    {
        for (int j=0 ; j < 3; j++)
            if (answers[i] == students[j][i % students[j].size()]) 
                Ocount[j] += 1;
    }
    
    int maxCount = *max_element(Ocount.begin(),Ocount.end());
    
    for (int i=0 ; i < 3; i++)
        if (Ocount[i] == maxCount) answer.push_back(i+1);    
    
    return answer;
}