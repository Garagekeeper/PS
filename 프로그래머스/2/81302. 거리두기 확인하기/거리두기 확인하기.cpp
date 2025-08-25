#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> answer;

// r, rr, d, dd, dr, ru
int dx[6] = {0,0,1,2,1,-1};
int dy[6] = {1,2,0,0,1,1};

bool PosCheck(int nx, int ny)
{
    if (0 > nx || nx >= 5) return false;
    if (0 > ny || ny >= 5) return false;
    return true;
}

void simulate(vector<string> place)
{
    for (int i=0; i<5; i++)
    {
        for (int j=0; j<5; j++)
        {
            if (place[i][j] == 'P')
            {
                bool flag = true;
                int nx;
                int ny;
                // 오른쪽
                for (int k=0; k<2; k++)
                {
                    nx = i+dx[k];
                    ny = j+dy[k];
                    if(!PosCheck(nx, ny)) continue;
                    if (place[nx][ny] == 'X') break;
                    if (place[nx][ny] == 'P') flag = false;
                }

                if (flag == false) { answer.push_back(0); return;}
                // 아래쪽
                for (int k=2; k<4; k++)
                {
                    nx = i+dx[k];
                    ny = j+dy[k];
                    if(!PosCheck(nx, ny)) continue;
                    if (place[nx][ny] == 'X') break;
                    if (place[nx][ny] == 'P') flag = false;
                }
                if (flag == false) { answer.push_back(0); return;}
                

                // 우하단
                nx = i+dx[4];
                ny = j+dy[4];
                if(!PosCheck(nx, ny)) continue;
                if (place[nx-1][ny] == 'X' && place[nx][ny-1] == 'X') continue;
                if (place[nx][ny] == 'P') flag = false;
                if (flag == false) { answer.push_back(0); return;}
                
                // 우상단
                nx = i+dx[5];
                ny = j+dy[5];
                if(!PosCheck(nx, ny)) continue;
                if (place[nx+1][ny] == 'X' && place[nx][ny-1] == 'X') continue;
                if (place[nx][ny] == 'P') flag = false;
                if (flag == false) { answer.push_back(0); return;}
            }
        }
    }
    answer.push_back(1);
}


vector<int> solution(vector<vector<string>> places) 
{
    for (auto& place : places)
        simulate(place);
    return answer;
}