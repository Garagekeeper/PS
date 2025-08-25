#include <string>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

bool PrimeCheck(long long num)
{
    if (num == 1) return false;
    for (int i=2; i<=sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    
    return true;
}

vector<int> DeciToK(int n, int k)
{
    vector<int> remain;
    while (n)
    {
        remain.push_back(n % k);
        n /= k;
    }
    
    return vector<int>(remain.rbegin(), remain.rend());
}

int solution(int n, int k) 
{
    int answer = 0;
    
    // k진수 변환
    vector<int> afterTrans = DeciToK(n,k);
    //afterTrans.push_back(0);

    long long num = 0;
    for (int i=0; i<afterTrans.size(); i++)
    {
        //0. i번째 숫자가 0이면 
        //0-1 현재 num이 0인 경우는 넘어감
        //0-1 num이 0이 아니면 num 소수 판별
        //1. i벉째 숫자가 0이 아니면 num update
        
        if (afterTrans[i] == 0)
        {
            if (num  == 0) continue;
            if (PrimeCheck(num)) answer++;
            //cout << num << endl;
            num = 0;
        }
        else
        {
            num = num * 10 + afterTrans[i];
        }
    }
    if (num != 0 && PrimeCheck(num)) answer++;
    //cout << num << endl;
    
    return answer;
}