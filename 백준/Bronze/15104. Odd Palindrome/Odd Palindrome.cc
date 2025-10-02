#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
    cin >> s;
    for (int i=1; i<s.size(); i++)
    {
        if (s[i-1] == s[i])
        {
            cout << "Or not.\n";
            return 0; 
        }
    }

    cout << "Odd.";
}