#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

#define MOD 1234567
vector<int> cache;

vector<vector<long long>> MatrixTime(vector<vector<long long>> A, vector<vector<long long>> B)
{
    vector<vector<long long>> res (A.size(), vector<long long>(B[0].size()));
    
    for (int i=0; i<A.size(); i++)
    {
        for (int j=0; j<B[0].size(); j++)
        {
            long long sum = 0;
            for (int k=0; k<A[0].size(); k++)
            {
                sum += (A[i][k] * B[k][j]) % MOD;
            }
            res[i][j] += sum;
        }
    }
    
    return res;
}

vector<vector<long long>> MatrixPow(vector<vector<long long>> target, int n)
{
    vector<vector<long long>> res(target.size(), vector<long long>(target.size()));
    
    for (int i=0; i<target.size(); i++)
        res[i][i] =1;
    
    while(n != 0)
    {
        if (n%2==1) res = MatrixTime(res, target);
        target = MatrixTime(target, target);
        n/=2;
    }
    
    return res;
}

int Fibo(int n)
{
    if (n <= 2) return 1;
    if (cache[n] != 0) return cache[n];
    return cache[n] = (Fibo(n-1) + Fibo(n-2)) % MOD;
}

// 피보나치 수의 규칙을 행렬을 통해서 표현.
// uk+1 = A * uk;
// uk = A^k * u0;
int Fibo2(int n)
{
    vector<vector<long long>> A = {{1,1}, {1,0}};
    vector<int> U0 = {1,0};
    
    A = MatrixPow(A,n);
    
    return A[1][0] % MOD;
}


// Eigenvalue를 통한 방법
// uk+1 = A^k * u0 에서 
// Eigenvector를 찾기 (lambda1,1) , (lambda2, 1);
// Eigenvector의 선형 결합으로 표현.
// 위의 값에 A^k를 곱해서 값을 구함. (각 고유벡터에 A를 곱한 것은 고유벡터에 해당하는 고윳값을 곱한것과 같음)
// 식을 정리하면 아래의 형태로 나옴

// 간단한 코드
// 정확도 문제로 큰 n에서는 사용 불가
// 이 환경에서는 71부터 오차 발생
// 변형해서 써야함
int Fibo3(int n)
{
    long double a = (1 + sqrt(5))/2;
    long double b = (1 - sqrt(5))/2;
    long long res = round((pow(a, n) - pow(b, n)) / sqrt(5));
    int result = static_cast<int>(res % MOD);
    return result;
}

// 3의 변형
// 행렬이 필요하지 않음.
// n이 커지면 커질수록 선형.
int Fibo4(int n)
{
    if (n<= 70) return Fibo3(n);
    int num = 0;
    int nm2 = Fibo3(69);
    int nm1 = Fibo3(70);
    for (int i=71; i<=n; i++)
    {
        num = (nm2 + nm1) % MOD;
        nm2 = nm1;
        nm1 = num;
    }
    
    return num;
}


int solution(int n) 
{
    cache.resize(n+1);
    return Fibo(n);
}