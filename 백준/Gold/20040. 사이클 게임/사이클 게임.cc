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

bool Union(int a, int b)
{
    int A = Find(a);
    int B = Find(b);
    bool mergeSucess = false;

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
        mergeSucess = true;
    }

    return mergeSucess;
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

    int answer = 0;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (!Union(a,b))
        {
            answer = i;
            break;
        }
    }

    cout << answer << "\n";
}