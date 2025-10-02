#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M,T,U,F,D;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> T >> U >> F >> D;

    int fDis = 2*F;
    int udDis = U + D;
    int ans = 0;
    int prifix=0;

    for (int i=0; i<T; i++)
    {
        char temp;
        cin >> temp;
        if (temp == 'f')
        {
            prifix+=fDis;
            if (M < prifix) break;
            ans++;
        }
        else if (temp == 'u' || temp == 'd')
        {
            prifix+=udDis;
            if (M < prifix) break;
            ans++;
        }
    }

    cout << ans;

    
}
