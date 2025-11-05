#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
const int MAX = 10001;
int T,N;
int parent[MAX];

int Solution(int a, int b)
{
    int currA = a;
    int currB = b;

    vector<int> parA;
    unordered_set<int> parB;

    parA.push_back(a);
    parB.insert(b);
    while (true)
    {
        if (parent[currA] == currA) break;
        parA.push_back(parent[currA]);
        currA = parent[currA];
    }

    while (true)
    {
        if (parent[currB] == currB) break;
        parB.insert(parent[currB]);
        currB = parent[currB];
    }

    for (auto e : parA)
    {
        if (parB.find(e) != parB.end())
            return e;
    }

    int res = 0;

    return -1;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> T;
    while(T--)
    {
        cin >> N;
        for (int i=1; i<=N; i++)
        {
            parent[i] = i;
        }

        for (int i=0; i<N-1; i++)
        {
            int p, c;
            cin >> p >> c;

            parent[c] = p;
        }

        int targetA, targetB;
        cin >> targetA >> targetB;

        int ans = Solution(targetA, targetB);
        cout << ans << "\n";
    }

    return 0;
}