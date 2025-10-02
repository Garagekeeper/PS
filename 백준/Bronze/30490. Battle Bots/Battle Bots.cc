#include <iostream>
using namespace std;

long long N;

int main()
{
    cin >> N;
    long ans=0;
    while(N > 1)
    {
        N++;
        N/=2;
        ans++;
    }
    
    ans++;

    cout << ans;
}