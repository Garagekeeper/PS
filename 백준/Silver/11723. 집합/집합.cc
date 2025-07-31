#include <string>
#include <vector>
#include <iostream>
using namespace std;

int M;
int mask = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M;

    for (int i=0; i<M; i++)
    {
        string cmd;
        cin >> cmd;
        int num;
        if (cmd == "add")
        {
            cin >> num;
            mask |= (1 << num); 
        }
        else if (cmd == "remove")
        {
            cin >> num;
            mask &= ~(1 << num);
        }
        else if (cmd == "check")
        {
            cin >> num;
            if ((mask & (1<<num)) == (1<<num)) cout << 1;
            else cout << 0;
            cout << '\n';
        }
        else if (cmd == "toggle")
        {
            cin >> num;
            mask ^= (1 << num);
        }
        else if (cmd == "all")
        {
            mask = (1<<21)-1;
        }
        else if (cmd == "empty")
        {
            mask = 0;
        }
    }

    return 0;
}