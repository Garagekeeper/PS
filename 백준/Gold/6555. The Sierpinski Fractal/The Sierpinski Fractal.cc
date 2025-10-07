#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

int N;

void DrawSierpinskiFractal(vector<string>& canvas, int n, int x, int y)
{
    if (n == 2)
    {
        canvas[y][x] = '/';
        canvas[y][x+1] = '\\';
        canvas[y+1][x-1] = '/';
        canvas[y+1][x] = '_';
        canvas[y+1][x+1] = '_';
        canvas[y+1][x+2] = '\\';
        return;
    }
    int half = n / 2;
    DrawSierpinskiFractal(canvas, half, x, y);
    DrawSierpinskiFractal(canvas, half, x - half, y + half);
    DrawSierpinskiFractal(canvas, half, x + half, y + half);

}


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    while(true)
    {
        cin >> N;

        if (N==0) break;

        
        int height = 1 << N;
        int width = 1 << (N+1);
        vector<string> canvas(height, string(width, ' '));
        DrawSierpinskiFractal(canvas, height, height -1, 0);

       for (int i = 0; i < height; ++i)
       {
        int end = width - 1;
        while(end >= 0 && canvas[i][end] == ' ') end--;
        if (end >= 0)
            cout << canvas[i].substr(0,end+1);
        cout << "\n";
       }
       cout << "\n";
    }
   
    return 0;
}

