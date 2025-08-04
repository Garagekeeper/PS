#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int row = 1;
    int col = yellow;
    
    while (row <= sqrt(yellow))
    {
        if (2 * (row + col + 2) == brown)
            break;
            
        while (yellow % ++row != 0){}
        
        col = yellow / row;
    }
    return {max (row + 2, col + 2) , min(row + 2, col + 2)};
}