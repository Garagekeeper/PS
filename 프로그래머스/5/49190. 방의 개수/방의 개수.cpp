#include <iostream>
#include <vector>
#include <map>
#include <tuple>
 
using namespace std;
 
map<pair<int, int>, bool> chk;
map<tuple<int, int, int, int>, bool> dirchk;
 
int dy[] = {-1,-1,0,1,1,1,0,-1};
int dx[] = {0,1,1,1,0,-1,-1,-1};
 
int solution(vector<int> arrows) {
    int cnt=0;
    
    int y = 0;
    int x = 0;
    chk[make_pair(y,x)] = 1;
    
    
    for(int i=0; i<arrows.size(); i++) {
        int tmp = 2;
        while(tmp--) {
            int ed = arrows[i];
            
            int ny = y + dy[ed];
            int nx = x + dx[ed];
            
            // 도착점이 중복값이면서, 같은 방향이 아닐경우
            if(chk[make_pair(ny,nx)] && dirchk[{ny,nx,y,x}] ==false) {
                cnt++;
            }
            
            chk[{ny, nx}] = 1;
            dirchk[{ny,nx,y,x}] = 1;
            dirchk[{y,x,ny,nx}] = 1;
            
            y = ny;
            x = nx;
        }
        
    }
    return cnt;
}
 