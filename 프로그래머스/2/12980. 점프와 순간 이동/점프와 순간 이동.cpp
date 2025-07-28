#include <iostream>
#include <climits>
using namespace std;

int N;
int ans = 0;
void dfs(int dist, int cnt)
{
    if (dist > N) return;
    if (dist == N)
    {
        ans = min (ans, cnt);
        return;
    }
    
    dfs (dist + 1, cnt + 1);
    if (dist * 2  <= N && dist != 0 )
        dfs(dist * 2, cnt);
    
}

int solution(int n)
{
    N=n;
    //dfs(0,0);

    int current = n;
    while (current != 0)
    {
        if (current % 2 == 0)
            current /= 2;
        else 
        {
            current--;
            ans++;
        }
            
    }
    return ans;
}