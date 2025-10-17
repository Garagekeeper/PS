#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

const int INF = 987654321;
int N, P;

int graph[16][16];
int minimum = INF;
int cost[1 << 16];

int dfs(int mask)
{
    if (cost[mask] != -1)
    {
        return cost[mask];
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) 
    {
        if ((mask >> i) & 1) 
            cnt++;
    }

    if (cnt >= P)
    {
        return 0;
    }

    cost[mask] = INF;
    for (int i=0; i<N; i++)
    {
        if (!(mask & (1 << i))) continue;
        for (int j=0; j<N; j++)
        {
            if (mask & (1 << j)) continue;
            cost[mask] = min(cost[mask], dfs(mask | ( 1 << j )) + graph[i][j]);
        }
    }

    return cost[mask];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
    memset(cost, -1, sizeof(cost));
    cin >> N;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++)
        {
            int weight;
            cin >> weight;
            graph[i][j] = weight;
        }
    }

    string onOffstat;
    cin >> onOffstat;
    int mask = 0;
    for (int i=0; i<onOffstat.size(); i++)
    {
        if (onOffstat[i] == 'Y')
        {
            mask |= 1 << i;
        }
    }

    cin >> P;

    minimum = dfs(mask);

    if (minimum == INF)
    {
        minimum = -1;
    }

    cout << minimum;

    return 0;
}
