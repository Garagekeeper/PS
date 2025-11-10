#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX = 987654321;

int N, M;
vector<int>v[100001];
int cost[100001];

void dfs(int cur)
{
    for(int i=0; i<v[cur].size(); i++)
    {
        int next = v[cur][i]; //cur에 대한 직원
        cost[next] += cost[cur]; //내리칭찬 저장
        dfs(next);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); 
	cin.tie(0);
    
    cin >> N >> M;
    for(int i=1; i<=N; i++)
    {
        int n;
        cin >> n;
        v[n].push_back(i); //해당 직속 상사에 대한 직원 저장
    }

    for(int i=1; i<=M; i++)
    {
        int a, b;
        cin >> a >> b;
        cost[a]+=b; //입력받은 칭찬 저장
    }
    dfs(1);
    
    for(int i=1; i<=N; i++) cout << cost[i] << " ";
    return 0;
}