#include <string>
#include <vector>

using namespace std;

// 개수를 기반으로 dfs
vector<int> Ainfo;
vector<int> Rinfo;
int N;
int maxScore=-987654321;
vector<int> answer;
vector<int> visited;
int CalcScore()
{
    int Ascore = 0;
    int Rscore = 0;
    for (int i=10; i>=1; i--)
    {
        if (Ainfo[i]==Rinfo[i] && Ainfo[i] == 0) continue;
        if (Ainfo[i]>=Rinfo[i])
        {
            Ascore += i;
        }
        else 
        {
            Rscore += i;
        }
    }
    
    return Rscore - Ascore;
}

bool dfs(int cnt)
{
    // cnt가 n보다 크거나 같으면 종료
    // 총 점수를 계산해서 같거나 더 높으면 갱신
    if (cnt > N) return false;
    if (cnt == N)
    {
        int res = CalcScore();
        if (res <= 0 ) return false;
        if (res >= maxScore) 
        {
            maxScore = res;
            answer = Rinfo;
        }
        return false;
    }
    
    // 10부터 선택하도록
    for (int i=10; i>=0; i--)
    {
        // 이미 라이언이 점수를 가져온 경우
        // 더 맞혀봐야 점수는 i점
        //if (visited[i] = true)
        if (Ainfo[i] < Rinfo[i]) continue;
        if (N - cnt < Ainfo[i] && i != 0) continue;
        
        if (i == 0)
        {
            Rinfo[i]+=N - cnt;
            bool flag = dfs(cnt+N - cnt);
            Rinfo[i]-=N - cnt;
        }
        else 
        {
            Rinfo[i]+=Ainfo[i] + 1;
            bool flag = dfs(cnt+Ainfo[i] + 1);
            Rinfo[i]-=Ainfo[i] + 1;
        }
        
        
        //if (!flag) visited[i] = true;
        
    }
    return true;
}

vector<int> solution(int n, vector<int> info) {
    Ainfo = vector<int>(info.rbegin(), info.rend());
    N = n;
    answer.resize(11, 0);
    Rinfo.resize(11, 0);
    visited.resize(11,0);
    dfs(0);
    vector<int> ansvec;
    bool flag = false;
    for (auto& e : answer)
    {
        if (e != 0) flag = true;
    }
    
    if (flag)
    {
        return ansvec = vector<int> (answer.rbegin(), answer.rend());
    }
    
    return {-1};
}
