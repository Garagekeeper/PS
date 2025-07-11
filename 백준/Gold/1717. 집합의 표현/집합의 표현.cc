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

    if (A != B)
    {
        if (rankVec[A] <= rankVec[B])
        {
            parents[A] = B;
            rankVec[B] += rankVec[A];
        }
        else
        {
            parents[B] = A;
            rankVec[A] += rankVec[B];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 초기상태
    
    rankVec.resize(n+1,1);
    // 자신의 부모는 자기 자신
    for (int i = 0; i <= n; ++i)
    {
        parents.push_back(i);
    }

    while (m--)
    {
        int cmd,a,b;
        cin >> cmd >> a >> b;
        if (cmd == 0)
        {
            if (a==b)
                continue;
            Union(a,b);
        }
        else
        {
            if (a==b)
            {
                 cout << "yes" << "\n";
                 continue;
            }
            cout << (DetermineSameSet(a,b) ? "yes" : "no") << "\n";
        }
    }

}