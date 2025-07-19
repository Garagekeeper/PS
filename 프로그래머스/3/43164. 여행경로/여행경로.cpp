#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<string>> gtickets;
vector<bool> ticketVisited;
vector<string> answer;
int N;
bool dfs(string start, int depth)
{
    answer.push_back(start);
    if (depth > N) return true;
    for (int i=0; i<N; i++)
    {
        if (start != gtickets[i][0]) continue;
        if (ticketVisited[i]) continue;
        
        ticketVisited[i] = true;
        bool isdone = dfs(gtickets[i][1], depth+1);
        if (isdone) return true;
        ticketVisited[i] = false;
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    gtickets = tickets;
    N = tickets.size();
    ticketVisited.resize(N,false);
    dfs("ICN", 1);
    return answer;
}