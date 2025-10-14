using System;

public class Solution {

    private bool[,,] visited;
    
    public int solution(string dirs) {
        int answer = 0;
        int cx = 0;
        int cy = 0;
        // x y 방문한 방향
        visited = new bool[12,12,4];
        
        foreach (var dir in dirs){
            int dx = 0;
            int dy = 0;
            int dirVec = 0;
            
            if (dir == 'R') { dx = 1; dy = 0; dirVec = 0;}
            else if (dir == 'D') { dx = 0; dy = -1; dirVec = 1;}
            else if (dir == 'L') { dx = -1; dy = 0; dirVec = 2;}
            else if (dir == 'U') { dx = 0; dy = 1; dirVec = 3;}
            
            int nx = cx + dx;
            int ny = cy + dy;

            // condition check
            if (-5 > nx || nx > 5) continue;
            if (-5 > ny || ny > 5) continue;
            if (visited[nx+5,ny+5,(dirVec + 2) % 4] != true && visited[cx+5,cy+5,(dirVec) % 4] != true)
            {
                visited[nx+5,ny+5,(dirVec + 2) % 4] = true;
                answer++;
            }

            cx = nx;
            cy = ny;
        }
        
        return answer;
    }
}