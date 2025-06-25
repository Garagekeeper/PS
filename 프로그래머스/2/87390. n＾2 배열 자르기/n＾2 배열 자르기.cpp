#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    for (auto i = left; i<=right; i++)
    {
        int row = i % n;
        int col = i / n;
        
        if (row >= col)
        {
            answer.push_back(row + 1);
        }
        else if (row < col)
        {
            answer.push_back(col + 1);
        }
    }
    return answer;
}