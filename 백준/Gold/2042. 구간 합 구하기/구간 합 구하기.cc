#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 수의 개수, 변경이 일어나는 횟수, 구간합을 구하는 횟수
int N,M,K;

vector<long long> seqs;
vector<long long> segTreeVec;

long long BuildTree(int node, int left, int right)
{
    if (left == right)
    {
        segTreeVec[node] = seqs[left];
        return seqs[left];
    }
    int mid = (left + right)/2;

    return segTreeVec[node] = BuildTree(node * 2, left, mid) + BuildTree(node * 2 + 1, mid + 1, right);
}

void UpdateTree(int node, int left, int right, int index, long long diff)
{
    if (left > index || index > right) return;
    if (left == right)
    {
        segTreeVec[node] += diff;
        return;   
    }

    segTreeVec[node] += diff;
    int mid = (left + right) / 2;
    UpdateTree(node * 2, left, mid, index, diff);
    UpdateTree(node * 2 + 1, mid + 1, right,  index, diff);
}

void UpdateTree(int index, long long num)
{
    long long diff = num - seqs[index];
    seqs[index] = num;
    UpdateTree(1, 0, N - 1, index, diff);
}

long long SumTree(int node, int left, int right, int tleft, int tright)
{
    if (tleft <= left && right <= tright) return segTreeVec[node];
    if (tleft > right || tright < left) return 0;

    int mid = (left + right) / 2;
    return SumTree(node*2, left, mid, tleft, tright) + SumTree(node*2+1, mid + 1, right, tleft, tright);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;
    for (int i=0; i<N; i++)
    {
        long long num;
        cin >> num;
        seqs.push_back(num);
    }

    segTreeVec.resize(4*N + 1);
    BuildTree(1, 0, N-1);

    for (int i=0; i<M+K; i++)
    {
        long long a,b,c;
        cin >> a >> b >> c;

        if (a == 1)
            UpdateTree(b-1, c);
        else if(a == 2)
            cout << SumTree(1, 0, N-1, b-1, c-1) << '\n';
    }

    return 0;
}