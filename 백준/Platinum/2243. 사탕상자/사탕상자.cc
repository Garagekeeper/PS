#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1000001;
int n;
long long A,B,C;
long long segTree[4*MAX];

void UpdateTree(int node, int left, int right, int idx, int diff)
{
    // idx --left --- right -- idx 인 경우 처리
    if (left > idx || idx > right) return;
    segTree[node] += diff;
    if (left == right) return;
    
    int mid = (left + right)/2;
    //왼쪽 자식 노드
    UpdateTree(node * 2, left, mid, idx, diff);
    //오른쪽 자식 노드
    UpdateTree(node * 2 + 1, mid + 1, right, idx, diff);
}

int query(int node, int left, int right, long long rank)
{
    if (left == right)  return left;
    int mid = (left + right) / 2;
    // 왼쪽 자식의 범위 [left , mid] 까지의 개수가 rank보다 많으면 
    // 즉 왼쪽범위의 사탕개수가 순위보다 같거나 많아지면 왼쪽 자식으로 감.
    // 사탕의 개수보다 rank가 크면
    // 오른쪽 범위에 답이 있으니까 왼쪽만큼의 개수를 빼고 탐색
    if (segTree[node * 2] >= rank)
        return query(node * 2, left, mid, rank);
    else
        return query(node * 2 + 1, mid + 1, right, rank - segTree[node * 2]);


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> A;
        if (A == 1)
        {
            cin >> B;
            int res = query(1, 1, MAX, B);
            cout << res << "\n";
            UpdateTree(1, 1, MAX, res, -1);
        }
        else
        {
            cin >> B >> C;
            UpdateTree(1, 1, MAX, B, C);
        }
    }

    return 0;
}