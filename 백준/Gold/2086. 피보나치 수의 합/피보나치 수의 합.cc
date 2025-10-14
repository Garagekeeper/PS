#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000000;

vector<vector<long long>> base =
{
    {1,1},
    {1,0}
};

vector<vector<long long>> current;

vector<vector<long long>> matrix_time(vector<vector<long long>> A, vector<vector<long long>> B)
{
    vector<vector<long long>> res = vector<vector<long long>>(A.size(), vector<long long>(B[0].size()));
    for (int i=0; i<2; i++)
    {
        for (int j=0; j<2; j++)
        {
            long long sum = 0;
            for (int k=0; k<2; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            res[i][j] = sum % MOD;
        }
    }

    return res;
}

vector<vector<long long>> matrix_power(vector<vector<long long>> arr, long long i)
{
    vector<vector<long long>> res = {{1,0},{0,1}};
    while (i > 0)
    {
        if (i % 2 == 1)
        {
            res = matrix_time(res, arr);
        }
            arr = matrix_time(arr, arr);
        i /= 2;
    }

    return res;
}

long long fibo(long long i)
{
    vector<vector<long long>> A =
    {
        {1,1},
        {1,0}
    };

    A = matrix_power(A, i);

    current = A;

    return A[1][0];
}


long long Sol(long long left, long long right)
{
    long long l_1 = fibo(left+1) % MOD;
    long long r_2 = fibo(right+2) % MOD;

    long long sum = ((r_2 - l_1) + MOD) % MOD;

    return sum;
}

int main()
{
    
    long long l, r;

    cin >> l >> r;

    long long res = Sol(l, r);

    cout << res << "\n";

    return 0;
}
