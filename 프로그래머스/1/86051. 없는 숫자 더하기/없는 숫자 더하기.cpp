#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> numbers) 
{
    int answer = 45;
    answer -= accumulate(numbers.begin(), numbers.end(), 0);
    return answer;
}