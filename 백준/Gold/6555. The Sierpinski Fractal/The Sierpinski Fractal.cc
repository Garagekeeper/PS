#include <iostream>
#include <vector>
using namespace std;

int N;

void DrawSierpinskiFractal(vector<string>& canvas, int height, int x, int y)
{
    if (height==2)
    {
        canvas[y][x-1] = '/';
        canvas[y][x] = '\\';
        canvas[y+1][x-2] = '/';
        canvas[y+1][x-1] = '_';
        canvas[y+1][x] = '_';
        canvas[y+1][x+1] = '\\';
        return;
    }

    int half = height / 2;
    DrawSierpinskiFractal(canvas, half, x , y);
    DrawSierpinskiFractal(canvas, half, x - half , y + half);
    DrawSierpinskiFractal(canvas, half, x + half , y + half);
}


int main()
{
    while(true)
    {
        cin >> N;

        if (N==0) break;
        
        int height = 1 << N;
        int width = 1 << (N+1);
        vector<string> canvas(height, string(width, ' '));

        DrawSierpinskiFractal(canvas, height, height, 0);
        for (int i=0; i<height; i++)
        {
            int end = width - 1;
            while(canvas[i][end] == ' ') end--;
            cout << canvas[i].substr(0, end+1) << "\n";
        }
        cout << "\n";
    }

    return 0;
}

