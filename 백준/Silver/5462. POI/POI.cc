#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, T, P;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> T >> P;
    
    vector<int> problem(T,0);
    vector<vector<int>> students(N, vector<int>(T,0));
    vector<vector<int>> res(N, vector<int>(3,0));
    vector<int> tem;

    // 입력
    for (int i=0; i<N; i++)
    {
        for (int k=0; k<T; k++)
        {
            int pass;
            
            // 참가자의 정답 여부
            cin >> pass;
            students[i][k] = pass;

            // 해당 문제의 정답자 수 증가
            if (pass == 1)
                problem[k]++;
        }
    }

    // 점수 계산
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

    // 문제의 조건으로 정렬
    // 점수 내림차순
    // 동일시 문제수 내림 차순
    // 동일시 번호 오름차순
    sort(res.begin(), res.end(), [&](vector<int> a, vector<int> b){
        if (a[0] == b[0])
        {
            if (a[1] == b[1])
                return a[2] < b[2];
            return a[1] > b[1];
        }
        return a[0] > b[0];
    });

    // P를 찾아서 점수와 등수 출력
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
