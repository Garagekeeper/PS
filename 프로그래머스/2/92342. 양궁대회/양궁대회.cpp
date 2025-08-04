#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 개수를 기반으로 dfs
vector<int> Ainfo;
vector<int> Rinfo;
int N;
int maxScore=-1;
vector<int> answer;
int CalcScore()
{
    int Ascore = 0;
    int Rscore = 0;
    for (int i=10; i>=1; i--)
    {
        if (Ainfo[i]>=Rinfo[i])
        {
            if (Ainfo[i] == 0) continue;
            Ascore += i;
        }
        else 
        {
            Rscore += i;
        }
    }
    
    return Rscore - Ascore;
}

void dfs(int cnt)
{
    // cnt가 n보다 크거나 같으면 종료
    // 총 점수를 계산해서 같거나 더 높으면 갱신
    if (cnt > N) return;
    if (cnt == N)
    {
        int res = CalcScore();
        // 동점이거나 진 경우
        if (res <= 0 ) return;
        // 이겼는데 최고점수보다 같거나 큰 경우
        // 큰 숫자부터 선택하기 때문에 같은 점수의 
        // 더 낮은 조합을 따지기 위해서 등호가 포함되어야
        if (res >= maxScore) 
        {
            maxScore = res;
            answer = Rinfo;
        }
        return;
    }
    
    // 10부터 선택하도록
    for (int i=10; i>=0; i--)
    {
        // 이미 라이언이 점수를 가져온 경우
        // 더 맞혀봐야 점수는 i점
        if (Ainfo[i] < Rinfo[i]) continue;
        
        if (i == 0)
        {
            // 0점인 경우 남은거 다 박기
            Rinfo[i]+=N - cnt;
            dfs(cnt+N - cnt);
            Rinfo[i]-=N - cnt;
        }
        else 
        {
            // i점을 얻기위한 최소한의 화살 개수를 더해서 dfs진행
            Rinfo[i]+=Ainfo[i] + 1;
            dfs(cnt+Ainfo[i] + 1);
            Rinfo[i]-=Ainfo[i] + 1;
        }
    }
}

vector<int> solution(int n, vector<int> info) {
    Ainfo = vector<int>(info.rbegin(), info.rend());
    N = n;
    answer.resize(11, 0);
    Rinfo.resize(11, 0);
    dfs(0);
    bool flag = false;
    
    if (any_of(answer.begin(), answer.end(), [](int x){ return x != 0; }))
    {
        return vector<int>(answer.rbegin(), answer.rend());
    }
    
    return {-1};
}
