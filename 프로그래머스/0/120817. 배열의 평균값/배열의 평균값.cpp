#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    int sum = 0;
    for (auto e : numbers) sum += e;
    
    answer = static_cast<double>(sum) / numbers.size();
    
    return answer;
}