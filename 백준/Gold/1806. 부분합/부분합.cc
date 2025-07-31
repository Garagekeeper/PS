#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

int N,S;
vector<int> seq;

int solve()
{
    int left = 0, right = 0;
    int sum = seq[0];
    int length = INT_MAX;
    while (true)
    {
        if (right > N-1) break;
        if (left > right) break;
        if (sum >= S)
        {
            length = min(length, right - left + 1);
            sum -= seq[left];
            left++;
        }
        else
        {
            right++;
            sum += seq[right];
        }
    }

    return length == INT_MAX ? 0 : length;
}

int main()
{
   cin >> N >> S;

   for (int i=0; i<N; i++)
   {
    int val;
    cin >> val;
    seq.push_back(val);
   }

   int res = solve();
   cout << res << "\n";
   return 0;
}