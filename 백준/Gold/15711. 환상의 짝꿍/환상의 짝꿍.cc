#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T;
// 어떤 자연수 N이 p+q로 표현될 수 있는지
constexpr int MAX = 2000001;
bool prime[MAX];
vector<int> primevec;

void change_bool(int start, int acc, bool flag)
{
    for (int i = start; i < MAX; i+=acc)
    {
        prime[i] = flag;
    }
}

void eratosthenes()
{
    std::fill_n(prime, MAX, false);
    prime[2] = true;
    prime[3] = true;

    // 모든 소수 p = 6k +- 1 형태로 표현 가능
    // 6k +- 1 형태라고 반드시 소수는 아님

    // 6k - 1
    // 5 11 17 23 29 35...
    change_bool(5, 6, true);

    // 6k + 1
    // 1 7 13 19 25 31 37 43 49 55 61 67...
    change_bool(7, 6, true);

    for (int i=5, j = 25; j < MAX;)
    {
        // i = 5에서 시작
        // next가 2, 4 로 반복
        // i = 5 7 11 13 17 ...
        int next = (i-3) % 6;
        if (prime[i] == true)
        {
            // 25 이후 부터 5의 배수들을 지운다.
            // 5x5 5x11 5x17
            // 5x7 5x13 5x19
            // 이렇개 i와 6의 최소 공배수 만큼마다 반복.
            int addi = i * 6; // x mod 6 인 숫자만 검색
            change_bool(j, addi, false);

            // 위에서 6k+1 패턴 지우면
            // 여기서 6k-1 패턴 지움
            change_bool(next * i  + j, addi, false);
        }
        i += next;
        j = i * i;
    }


    for (int i=2; i<MAX; i++)
    {
        if (prime[i])
            primevec.push_back(i);
    }
}

bool isPrime(long long n)
{
    if (n < MAX)
    {
        return prime[n];
    }
    else
    {
        for (auto p : primevec)
        {
            if (1LL * p * p > n) break;
            if (n % p == 0) return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    eratosthenes();

    cin >> T;
    while(T--)
    {
        long long a,b;
        cin >> a >> b;
        if (a+b <=3)
            cout << "NO" << '\n';
        else if ((a+b) % 2 == 0)
            cout << "YES" << '\n';
        else 
        {
            if (isPrime((a+b-2)))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
   
    return 0;
}
