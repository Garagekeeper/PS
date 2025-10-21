#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <queue>
using namespace std;

int N,K;
const int MAX = 100001;
int ans;
vector<int> visited(MAX, MAX);

bool CanGo(int x, int cnt)
{
    if (x < 0 || x >= MAX) return false;
    if (visited[x] < cnt) return false;

    return true;
}

void BFS(int x)
{
    int dx[3] = {-1, 1, 2};
    queue<pair<int,int>> q;
    q.push({x,0});
    visited[x] = 0;

    while(!q.empty())
    {
        int pos = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cnt == visited[K] && pos == K) ans++; 
        int nx = 0;
        for (int i=0; i<3; i++)
        {
            if (i == 2)
            {
                nx = pos * 2;
            }
            else
            {
                nx = pos + dx[i];
            }
            
            if (CanGo(nx, cnt+1))
            {
                visited[nx] = cnt+1;
                q.push({nx, cnt+1});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    
    BFS(N);

    cout << visited[K] << "\n";
    cout << ans << "\n";

    return 0;
}