#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

struct CCTV
{
    int _x;
    int _y;
    int _type;
    vector<pair<int,int>> rotVec;
};

int N,M;
int cnt = 0;
int answer = INT_MAX;

vector<CCTV> cctvVec;
vector<vector<int>> board;
vector<int> rotCntVec = {0,4,2,4,4,1};
vector<vector<pair<int,int>>> rotVecs = {
    {},
    {{0, 1}}, 
    {{0, 1}, {0, -1}}, 
    {{0, 1}, {-1, 0}},
    {{0, 1}, {0, -1}, {-1, 0}},
    {{0, 1}, {0, -1}, {-1, 0}, {1, 0}},
};

int CalcBlindSpot(int index, vector<vector<int>> inboard)
{
    int res = cnt;

    for (int i =0; i < cctvVec.size(); i++)
    {
        auto current_cctv = cctvVec[i];
        for (int j=0; j<current_cctv.rotVec.size(); j++)
        {
            int x = current_cctv._x;
            int y = current_cctv._y;
            while (true)
            {
                int nx = x + current_cctv.rotVec[j].first;
                int ny = y + current_cctv.rotVec[j].second;

                if (nx < 0 || nx >= N) break;
                if (ny < 0 || ny >= M) break;
                if (inboard[nx][ny] == 6)break;
                if (inboard[nx][ny] == 0)
                {
                    inboard[nx][ny] = -1;
                    res--;
                }
                
                x = nx;
                y = ny;
            }
        }
    }

    return res;
}

void RotateVec(CCTV& ctv, int cnt)
{
    if (cnt == 0) return;

    int clockwise = cnt > 0 ? 0 : 1;
    

    for (int i=0; i<abs(cnt); i++)
    {
        for (int j = 0; j < ctv.rotVec.size(); j++)
        {
            int x = ctv.rotVec[j].first;
            int y = ctv.rotVec[j].second;
            if (cnt > 0) 
            {
                // 시계 방향 90도
                ctv.rotVec[j].first = y;
                ctv.rotVec[j].second = -x;
            } 
            else 
            {
                // 반시계 방향 90도
                ctv.rotVec[j].first = -y;
                ctv.rotVec[j].second = x;
            }

        }
    }
}

void dfs(int index)
{
    if (index == cctvVec.size())
    {
        int res = CalcBlindSpot(index, board);
        answer = min(res, answer);
        return;
    }

    CCTV& ctv = cctvVec[index];

    for (int i = 0; i < rotCntVec[ctv._type]; i++)
    {
        RotateVec(ctv, i);
        dfs(index + 1);
        RotateVec(ctv, i * -1);
    }


}

int main()
{
    cin >> N >> M;
    board.resize(N, vector<int>(M));

    for (int i=0; i<N; i++)
    {
        for (int j=0; j<M; j++)
        {
            int val;
            cin >> val;
            board[i][j] = val;
            if (val == 0) cnt++;
            if (1 <= val && val <= 5) cctvVec.push_back({i,j,val,rotVecs[val]});
        }
    }

    dfs(0);

    cout << answer << '\n';
    return 0;
}