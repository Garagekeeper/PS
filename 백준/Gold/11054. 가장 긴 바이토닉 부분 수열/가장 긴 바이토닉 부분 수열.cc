#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;

int main()
{
    cin >> N;

    vector<int> seq;
    vector<int> dp1(N,1);
    vector<int> dp2(N,1);

    for (int i=0; i<N; i++)
    {
        int temp;
        cin >> temp;
        seq.push_back(temp);
    }


    dp1[0] = 1;
    dp2[0] = 1;
    for (int i = 1; i<N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (seq[j] >= seq[i]) continue;
            dp1[i] = max(dp1[j] + 1, dp1[i]);
        }
    }

    seq = vector<int>(seq.rbegin(), seq.rend());

    for (int i = 1; i<N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (seq[j] >= seq[i]) continue;
            dp2[i] = max(dp2[j] + 1, dp2[i]);
        }
    }

    dp2 = vector<int>(dp2.rbegin(), dp2.rend());
    int answer = 0;
    for (int i=0; i<N; i++)
    {
        answer = max({dp1[i] + dp2[i], answer});
    }

    cout << answer-1;
}