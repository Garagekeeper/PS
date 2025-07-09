#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> digit;
    
    while (n != 0)
    {
        digit.push_back(n % 10);
        n /= 10;
    }
    
    sort(digit.begin(), digit.end(), [](const int& a, const int& b){
        return a > b;
    });
    
    long long times = 1;
    for (auto it = digit.rbegin(); it != digit.rend(); ++it)
    {
        answer += *it * times;
        times*=10;
    }
    return answer;
}