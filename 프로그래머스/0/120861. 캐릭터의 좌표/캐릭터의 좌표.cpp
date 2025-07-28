#include <string>
#include <vector>
#include <iostream>
using namespace std;

int x_range;
int y_range;

int xpos;
int ypos;


bool CanGo(int x, int y)
{
    if (abs(x) > abs(x_range)) return false;
    if (abs(y) > abs(y_range)) return false;
    return true;
}

void MoveCharacter(string input)
{
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    int dir = 0;
    if (input[0] == 'u') dir = 0;
    if (input[0] == 'd') dir = 1;
    if (input[0] == 'l') dir = 2;
    if (input[0] == 'r') dir = 3;
    
    int nx = xpos + dx[dir];
    int ny = ypos + dy[dir];
    
    if (CanGo(nx, ny))
    {
        xpos = nx;
        ypos = ny;
    }
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    x_range = board[0]/2;
    y_range = board[1]/2;
    
    xpos = 0;
    ypos = 0;
    
    for (auto& input : keyinput)
    {
        MoveCharacter(input);
    }
    
    return {xpos, ypos};
}