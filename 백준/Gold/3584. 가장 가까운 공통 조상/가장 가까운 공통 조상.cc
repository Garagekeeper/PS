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

    vector<int> parentAvec;
    unordered_set<int> parBuset;

    parentAvec.push_back(a);
    parBuset.insert(b);
    
    // A부터 root까지의 노드를 담는다.
    while (true)
    {
        if (parent[currA] == currA) break;
        parentAvec.push_back(parent[currA]);
        currA = parent[currA];
    }

    // B부터 root까지의 노드를 해시셋에 담는다.
    while (true)
    {
        if (parent[currB] == currB) break;
        parBuset.insert(parent[currB]);
        currB = parent[currB];
    }

    // A부터 위로 올라가면서 B의 부모 목록에 있는지 확인하고
    // 있으면 반환.
    for (auto e : parentAvec)
    {
        if (parBuset.find(e) != parBuset.end())
            return e;
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

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