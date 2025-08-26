#include <string>
#include <vector>

using namespace std;

vector<int> answer(2);

void QuadTreeCompression(int x, int y, int len, vector<vector<int>>& arr)
{
    int sum = 0;
    for (int i=x; i<x+len; i++)
    {
        for (int j=y; j<y+len; j++)
        {
            sum+=arr[i][j];
        }
    }
    
    if (sum == 0) 
    {
        answer[0]++;
        return;
    }
    
    if (sum == len * len) 
    {
        answer[1]++;
        return;
    }
    
    QuadTreeCompression(x,y,len/2, arr);
    QuadTreeCompression(x + len/2,y,len/2, arr);
    QuadTreeCompression(x,y+len/2,len/2, arr);
    QuadTreeCompression(x+len/2,y+len/2,len/2, arr);
    
}

vector<int> solution(vector<vector<int>> arr) 
{
    QuadTreeCompression(0,0,arr.size(), arr);
    return answer;
}