#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

vector<vector<int>> cost;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    cost.resize(n+1, vector<int>(n+1, INT_MAX));
    
    for(auto& fare : fares)
    {
        int from = fare[0];
        int to = fare[1];
        int weight = fare[2];
        cost[from][to] = weight;
        cost[to][from] = weight;
    }
    
    for (int k=1; k<n+1; k++)
    {
        for (int i=0; i<n+1; i++)
        {
            for (int j=0; j<n+1; j++)
            {
                if (i==j)
                {
                    cost[i][j] = 0;
                    continue;
                }
                int i2j = cost[i][j];
                int i2k = cost[i][k];
                int k2j = cost[k][j];
                
                if (i2k == INT_MAX) continue;
                if (k2j == INT_MAX) continue;
                
                if (i2j > i2k + k2j)
                {
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
    
    int withoutA = cost[s][a];
    int withoutB = cost[s][b];
    int withoutTotal = withoutA + withoutB;
    answer = withoutTotal;
    
    for (int i=1 ; i<n+1; i++)
    {
        if (i == s) continue;
        int stoi = cost[s][i];
        int itoa = cost[i][a];
        int itob = cost[i][b];
        answer = min (answer, stoi + itoa + itob);
    }
    
    return answer;
}