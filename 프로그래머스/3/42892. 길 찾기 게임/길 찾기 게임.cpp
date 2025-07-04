#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    Node(int x, int num) : _x(x), _num(num) , _left(nullptr), _right(nullptr){}
    int _x;
    int _num;
    
    Node* _left;
    Node* _right;
};

class BST
{
    public:
    BST() : _root(nullptr) {};
    void insert(int x, int num);
    void PreOrder(vector<int>& vec);
    void PostOrder(vector<int>& vec);
    
    private:
    Node* insertPrivate(Node* node, int x,  int num);
    void PreOrder(Node* node, vector<int>& vec);
    void PostOrder(Node* node, vector<int>& vec);
    Node* _root;
};

void BST::insert(int x, int num)
{
    if (_root == nullptr) 
        _root = new Node(x,num);
    else 
    {
        _root = insertPrivate(_root, x, num);
    }
    
}

Node* BST::insertPrivate(Node* node, int x, int num)
{
    if (node == nullptr)
    {
        Node* newNode = new Node(x,num);   
        return newNode;
    }
    
    if (node->_x < x)
    {
        node->_right = insertPrivate(node->_right, x, num);
    }
    else if (node->_x > x)
    {
        node->_left = insertPrivate(node->_left, x, num);
    }
    
    return node;
}

void BST::PreOrder(vector<int>& vec)
{
    PreOrder(_root, vec);
}

void BST::PostOrder(vector<int>& vec)
{
    PostOrder(_root, vec);
}

void BST::PreOrder(Node* node, vector<int>& vec)
{
    if (node == nullptr) return;

    vec.push_back(node->_num);
    PreOrder(node->_left, vec);
    PreOrder(node->_right, vec);
}

void BST::PostOrder(Node* node, vector<int>& vec)
{
    if (node == nullptr) return;
    PostOrder(node->_left, vec);
    PostOrder(node->_right, vec);
    vec.push_back(node->_num);
}

bool cmp (vector<int> vec1, vector<int> vec2)
{
    return vec1[1] > vec2[1];
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer(2,vector<int>());
    unordered_map<int, int> xtonum;
    
    for (int i=0; i<nodeinfo.size(); i++)
    {
        xtonum[nodeinfo[i][0]] = i+1;
    }
    // y가 큰 장소가 먼저 삽입되어야
    // x만 가지고 BST만들 수 있음.
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    BST bst;
    
    for (int i=0; i<nodeinfo.size(); i++)
    {
        bst.insert(nodeinfo[i][0], xtonum[nodeinfo[i][0]]);
    }
    
    bst.PreOrder(answer[0]);
    bst.PostOrder(answer[1]);
    
    return answer;
}