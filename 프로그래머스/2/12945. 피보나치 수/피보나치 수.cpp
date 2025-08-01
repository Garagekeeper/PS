#include <string>
#include <vector>

using namespace std;

int solution(int n) 
{
    const int MOD = 1234567;
    vector<long long> fib(n + 1);
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; ++i) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
    
    return fib[n];

}