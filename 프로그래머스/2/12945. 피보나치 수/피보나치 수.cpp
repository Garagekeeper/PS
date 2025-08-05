#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#define MOD 1234567;
vector<int> cache;

int Fibo(int n)
{
    if (n <= 2) return 1;
    if (cache[n] != 0) return cache[n];
    return cache[n] = (Fibo(n-1) + Fibo(n-2)) % MOD;
}

// 정확도 문제로 큰 n에서는 사용 불가
// 이 환경에서는 71부터 오차 발생
// 변형해서 써야함
int Fibo2(int n)
{
    if (n <= 70)
    {
        long double temp = pow((1 + sqrt(5))/2, n);
        temp -= pow((1 - sqrt(5))/2, n);
        temp /= sqrt(5);
        int result = static_cast<long long>(round(temp)) % MOD;
        return result;
    }
    else 
    {
        
    }

}

int solution(int n) 
{
    cache.resize(n+1);
    return Fibo(n);
}