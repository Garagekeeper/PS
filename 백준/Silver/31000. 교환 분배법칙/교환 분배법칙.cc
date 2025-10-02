#include <iostream>

using namespace std;

int N;

int main()
{
    cin >> N;
    int ans = (2*N+1) * (2*N+1);

    for (int i=1; i<=N; i++)
    {
        int left = max(1-i-N, -N);
        int right = min(1-i+N, N);
        
        if (left <= right)
            ans += right - left + 1;
    }
    
    for (int i=-N; i<=-1; i++)
    {
        int left = max(1-i-N, -N);
        int right = min(1-i+N, N);
        
        if (left <= right)
            ans += right - left + 1;
    }

    cout << ans;
    return 0;
}