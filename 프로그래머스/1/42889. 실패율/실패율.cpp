#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> visited(N+2,0);
    multimap<double, int, greater<double>> failpercentage;
    
    for (int i=0; i < stages.size(); i++)
    {
        visited[stages[i]]++;
    }
    
    int visitN = stages.size();
    
    for (int i=1; i <= N; i++)
    {
        double percent = 0;
        if (visitN != 0)
            percent = static_cast<double>(visited[i]) / visitN;
        
        failpercentage.insert({percent, i});
        visitN -= visited[i];
    }
    
    for (auto e : failpercentage)
    {
        answer.push_back(e.second);
    }
    return answer;
}