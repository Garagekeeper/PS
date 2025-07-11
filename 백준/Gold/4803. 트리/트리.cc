#include <iterator>
#include <iostream>
#include <vector>

using namespace std;


int n, m;
vector<int> parents;
vector<int> rankVec;

int Find(int x)
{
    if (parents[x] == x) return x;
    return parents[x] = Find(parents[x]);
}

bool DetermineSameSet(int a, int b)
{
    int A = Find(a);
    int B = Find(b);

    return A == B;
}

void Union(int a, int b)
{
    int A = Find(a);
    int B = Find(b);

    if (A == 0 || B == 0)
    {
        parents[B] = 0;
        parents[A] = 0;
    }
    else if (A != B)
    {
        parents[B] = A;
    }
    else if (A == B)
    {
        parents[B] = 0;
        parents[A] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int caseNum = 1;
    while (true)
    {
        int n, m;
        cin >> n >> m;
        if ((n==0) && (m==0)) break;

        parents.clear();
        rankVec.clear();
        parents.resize(n+1);
        rankVec.resize(n+1, 1);
        for (int i = 0; i < n+1; i++)
        {
            parents[i] = i;
        }

        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            Union(a,b);
        }

        int treecnt = 0;
        for (int i = 1; i < n + 1; i++)
        {
            if (parents[i] == i)
                treecnt++;
        }

        cout << "Case " << caseNum <<": ";
        if (treecnt == 0)
        {
            cout << "No trees.\n";
        }
        else if (treecnt == 1)
        {
            cout << "There is one tree.\n";

        }
        else if (treecnt > 1)
        {
            cout << "A forest of " << treecnt << " trees.\n";
        }
        caseNum++;
    }

}