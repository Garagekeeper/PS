#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

// 수의 개수, 변경이 일어나는 횟수, 구간합을 구하는 횟수
int N,M,K;

struct Node
{
    Node();
    Node(int num) : _num(num),  _data(0){}
    int _num;
    long long _data;
    Node* _left = nullptr;
    Node* _right = nullptr;
};

class SegTree
{
    public:
    SegTree();
    SegTree(vector<long long> seqVec) : _seqVec(seqVec) {}

    void Init();
    long long MakeTree(Node* node, int left, int right);
    void Update(int idx, long long num);
    long long Sum(int leftIndex, int rightIndex);

    private:
    long long Sum(Node* node, int leftIndex, int rightIndex, int targetLindex, int targetRIndex);
    void Update(Node* node, int leftIndex, int rightIndex, int targetIndex, long long diff);
    Node* _root = nullptr;
    vector<long long> _seqVec;
};

long long SegTree::Sum(int targetLindex, int targetRIndex)
{
    return Sum(_root, 0, _seqVec.size()-1, targetLindex, targetRIndex);
}

long long SegTree::Sum(Node* node, int leftIndex, int rightIndex, int targetLindex, int targetRIndex)
{
    if (targetLindex <= leftIndex && rightIndex <= targetRIndex) return node->_data;
    if (targetLindex > rightIndex || targetRIndex < leftIndex) return 0;
    int mid = (leftIndex + rightIndex) / 2;

    return Sum(node->_left, leftIndex, mid, targetLindex, targetRIndex) + Sum(node->_right, mid + 1, rightIndex, targetLindex, targetRIndex);
}

void  SegTree::Update(int idx, long long num)
{
    long long diff = num - _seqVec[idx];
    _seqVec[idx] = num;
    Update(_root, 0, _seqVec.size()-1, idx, diff);
}

void  SegTree::Update(Node* node, int leftIndex, int rightIndex, int targetIndex, long long diff)
{
    if (leftIndex > targetIndex || targetIndex > rightIndex) return;
    if (leftIndex == rightIndex)
    {
        node->_data += diff;
        return;
    }
    node->_data += diff;
    int mid = (leftIndex + rightIndex) / 2;
    Update(node->_left, leftIndex, mid, targetIndex, diff);
    Update(node->_right, mid + 1, rightIndex,  targetIndex, diff);
}

long long SegTree::MakeTree(Node* node, int leftIndex, int rightIndex)
{
    if (leftIndex == rightIndex) 
    {
        node->_data = _seqVec[leftIndex];
        return _seqVec[leftIndex];
    }
    int mid = (leftIndex + rightIndex)/2;
    node->_left = new Node(node->_num * 2);
    node->_right = new Node(node->_num * 2 + 1);
    return node->_data = MakeTree(node->_left, leftIndex, mid) + MakeTree(node->_right, mid+1 ,rightIndex);
}

void SegTree::Init()
{
    _root = new Node(1);
    MakeTree(_root, 0, _seqVec.size()-1);

}

int main()
{
    vector<long long> seqs;
    cin >> N >> M >> K;
    while (N--)
    {
        long long num;
        cin >> num;
        seqs.push_back(num);
    }

    SegTree st(seqs);
    st.Init();

    for (int i=0; i<M+K; i++)
    {
        long long a,b,c;
        cin >> a >> b >> c;

        if (a == 1)
        {
            st.Update(b-1,c);
        }
        else if(a == 2)
        {
            cout << st.Sum(b-1,c-1) <<'\n';
        }
    }

    return 0;
}