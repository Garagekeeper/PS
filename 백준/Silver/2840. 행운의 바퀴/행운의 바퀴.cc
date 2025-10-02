#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int N,K;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    vector<char> wheel(N,'0');
    set<char> usedSet;
    int arrow = 0;
    for (int i=0; i<K; i++)
    {
        int cnt;
        char pointingChar;
        cin >> cnt >> pointingChar;
        arrow += cnt;
        arrow %= N;
        if (wheel[arrow] == '0')
        {
            if (usedSet.insert(pointingChar).second == true)  
                wheel[arrow] = pointingChar;
            else 
            {
                cout << '!';
                return 0;
            }

        }
        else 
        {
            if (wheel[arrow] != pointingChar)
            {
                cout << '!';
                return 0;
            }
        }
    }

    int cnt = 0;
    for (int i=arrow; cnt < N; cnt++, i = (i + N - 1) % N)
    {
        if (wheel[i] == '0')
            cout << '?';
        else
            cout << wheel[i];
    }

    return 0;
}

