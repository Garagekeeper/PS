#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    /*
    NAn+1 = A1 + A2 + ... + AN을 만족하는 수열을 찾는 문제
    후보군이 충분히 넓으니 An+1 = 0 을 만족하는 조건을 찾자
    즉 A1 + A2 + ... + AN = 0이 되도록 설정하자
    그렇다면 
    i -i j -j k -k ... 0 형태의 수열을 찾아낼 수 있다.
    여기서 홀수인 경우 -1 0 1 을 미리 넣어서 남은 개수를 짝수개로 만들어서
    i-i같이 짝을 맞춰 수열을 구성한다.
    */

    cin >> N;
    if (N & 1)
    {
        cout << -100 << ' ' << 1 << ' ' << 99 << ' ';
        N-=3;
    }

    for (int i = 1; i <= N / 2; i++)
    {
        int pairAi = i + 100;
        cout << pairAi << ' ' << -1 * pairAi << ' ';
    }
    
    cout << 0 ;
    
    return 0;
}

