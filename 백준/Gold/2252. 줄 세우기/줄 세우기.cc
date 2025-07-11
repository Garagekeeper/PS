#include <iterator>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> enterCount;
vector<vector<int>> adjMatrix;
vector<int> appear;
vector<bool> visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    enterCount.resize(n+1, 0);
    adjMatrix.resize(n+1);
    for (int i=0; i < m ; i++)
    {
        int from, to;
        cin >> from >> to;
        adjMatrix[from].push_back(to);
        enterCount[to]++;
    }

    queue<int> q;
    for (int i = 1; i < n+1; i++)
    {
        if (enterCount[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cout << front << ' ';
        for (auto& to : adjMatrix[front])
        {
            enterCount[to]--;

            if (enterCount[to] == 0)
            {
                q.push(to);
            }
        }
    }

    
}