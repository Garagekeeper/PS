#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int row = 1;
    int col = yellow;
    
    while (true)
    {
        if (2 * (row + col + 2) == brown)
            return {max (row + 2, col + 2) , min(row + 2, col + 2)};
            
        int temp = row + 1;
        while (yellow % temp != 0)
        {
            temp++;
        }
        col = yellow / temp;
        row = temp;
    }
    return {max (row + 2, col + 2) , min(row + 2, col + 2)};
}
/*
11111111
1      1
1      1
1      1
1      1
11111111
2(ax + bx) = 24
2(ax-2 * bx) = 24
*/