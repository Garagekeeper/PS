#include <string>
#include <vector>

using namespace std;
#define MOD 1234567;
//const int MOD = 1234567
vector<int> cache;

int Fibo(int n)
{
    if (n <= 2) return 1;
    if (cache[n] != 0) return cache[n];
    return cache[n] = (Fibo(n-1) + Fibo(n-2)) % MOD;
}

int solution(int n) 
{
    int answer = 0;
    cache.resize(n+1);
    answer = Fibo(n);
    return answer;
}