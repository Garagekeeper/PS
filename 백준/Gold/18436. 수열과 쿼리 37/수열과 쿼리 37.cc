#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
const int MAX = 100001;
int oddSegTree[4 * MAX];
int seqArr[MAX];
int N, M;

void UpdateTree(int node, int left, int right, int idx, int diff)
{
    if (left > idx || idx > right) return;
    oddSegTree[node] += diff;
    if (left == right) return;

    int mid = (left + right) / 2;
    UpdateTree(node * 2, left, mid, idx, diff);
    UpdateTree(node * 2 + 1, mid+1, right, idx, diff);
}

int query(int node, int left, int right, int targetLeft, int targetRight)
{
    if (targetLeft <= left && right <= targetRight) return oddSegTree[node];
    if (targetLeft > right || left > targetRight) return 0;

    int mid = (left + right) / 2;
    return query(node * 2, left, mid , targetLeft, targetRight)
    + query(node * 2 + 1, mid + 1, right, targetLeft, targetRight);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i=1; i<=N; i++)
    {
        int inval;
        cin >> inval;
        if (inval % 2 != 0)
        {
            seqArr[i] = 1;
            UpdateTree(1,1,N,i,1); 
        }
    }
    
    cin >> M;

    for (int i=0; i<M; i++)
    {
        int cmd, a, b;
        cin >> cmd;
        if (cmd == 1)
        {
            cin >> a >> b;
            if (seqArr[a] == 0 && b % 2 != 0)
            {
                seqArr[a] = 1;
                UpdateTree(1,1,N,a,1); 
            }

            else if (seqArr[a] == 1 && b % 2 == 0)
            {
                seqArr[a] = 0;
                UpdateTree(1,1,N,a,-1); 
            }
        }
        else if (cmd == 2)
        {
            cin >> a >> b;
            cout << (b-a + 1) - query(1,1,N,a,b) << "\n";
        }
        else if (cmd == 3)
        {
            cin >> a >> b;
            cout << query(1,1,N,a,b) << "\n";
        }
    }

    return 0;
}