#include <iterator>
#include <iostream>
#include <vector>

using namespace std;


int n, m;
vector<int> parents;

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
    if (!DetermineSameSet(a,b))
    {
        parents[Find(b)] = Find(a);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 초기상태
    // 자신의 부모는 자기 자신
    parents.resize(n+1);
    for (int i = 0; i < parents.size(); ++i)
    {
        parents[i] = i;
    }

    while (m--)
    {
        int cmd,a,b;
        cin >> cmd >> a >> b;
        if (cmd == 0)
        {
            Union(a,b);
        }
        else
        {
            cout << (DetermineSameSet(a,b) ? "yes" : "no") << "\n";
        }
    }
}