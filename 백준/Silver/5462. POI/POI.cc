#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T, P;

int main()
{
    cin >> N >> T >> P;
    
    vector<int> problem(T,0);
    vector<vector<int>> students(N, vector<int>(T,0));
    vector<vector<int>> res(N, vector<int>(3,0));
    vector<int> tem;

    for (int i=0; i<N; i++)
    {
        for (int k=0; k<T; k++)
        {
            int pass;
            
            cin >> pass;
            students[i][k] = pass;

            if (pass == 1)
                problem[k]++;
        }
    }

    for (int i=0; i<N; i++)
    {
        for (int k=0; k<T; k++)
        {
            //점수
            res[i][0] += students[i][k] * (N-problem[k]);
            //푼 문제수
            res[i][1] += students[i][k];
            //id
            res[i][2] = i;
        }
    }

    sort(res.begin(), res.end(), [&](vector<int> a, vector<int> b){
        if (a[0] == b[0])
        {
            if (a[1] == b[1])
                return a[2] < b[2];
            return a[1] > b[1];
        }
        return a[0] > b[0];
    });

    for (int i=0; i<N; i++)
    {
        if (res[i][2] + 1 == P)
        {
            cout << res[i][0] << " " << i+1;
            break;
        }
    }

    return 0;
}
