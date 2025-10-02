#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long A,B,C;

int main()
{
    long long ans = 1;
    cin >> A >> B >> C;
    ans = max(A*B/C, A*C/B);

    cout << ans << '\n';
}