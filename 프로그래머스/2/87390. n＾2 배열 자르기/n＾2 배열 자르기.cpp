#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;
    
    // i의 값을 2차원 배열의 인덱스들로 바꿔서 풀이
    for (auto i = left; i<=right; i++)
    {
        int row = i % n;
        int col = i / n;
        
        // Lower Triangle(x==y 포함)
        if (row >= col)
        {
            answer.push_back(row + 1);
        }
        // Upper Triangle
        else if (row < col)
        {
            answer.push_back(col + 1);
        }
    }
    return answer;
}