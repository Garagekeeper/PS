#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

map<pair<int,int>, vector<bool>> visited;
int dy[] = {-1,-1,0,1,1,1,0,-1};
int dx[] = {0,1,1,1,0,-1,-1,-1};

int solution(vector<int> arrows) {
    int answer = 0;
    
    int cx = 0;
    int cy = 0;
    int cdir = 0;
    visited[{cx, cy}].resize(8,false);
    for (auto& dir : arrows)
    {
        for (int i=0; i< 2; i++)
        {
            int nx = cx + dx[dir];
            int ny = cy + dy[dir];
            if (visited.find({nx, ny}) == visited.end())
            {
                visited[{nx, ny}].resize(8,false);
            }
            else
            {
                if (visited[{nx, ny}][dir] == false)
                    answer++;
            }
            visited[{nx, ny}][dir] = true;
            visited[{cx, cy}][(dir+4)%8] = true;
            cx = nx;
            cy = ny;
        }
       
    }
    
    return answer;
}