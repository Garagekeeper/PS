#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int M,N;

int main()
{
    
    cin >> N;
    cin >> M;

    vector<vector<int>> cost(N+1,vector<int>(N+1,INT_MAX));

    while (M--)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        cost[from][to] = min(weight, cost[from][to]);
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                // i -> k -> j
                if (i==j) continue;
                if (cost[k][j] == INT_MAX) continue;
                if (cost[i][k] == INT_MAX) continue;
                if (cost[i][j] > cost[i][k] + cost[k][j])
                    cost[i][j] = cost[i][k] + cost[k][j];
            }
        }
    }

    
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                int val = cost[i][j] == INT_MAX ? 0 : cost[i][j];
                cout << val << " ";
            }
            cout << '\n';
        }

    return 0;
}