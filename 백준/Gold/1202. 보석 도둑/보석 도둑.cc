#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

/*
    When true is returned 
    it means the order is NOT correct and swapping of elements takes place.

    if (a > b) return true or return a > b
    -> a > b 인 상태가 swap이 필요한 상태. (오름차순)
*/

struct Jewel
{
public:
    Jewel(){}
    Jewel(int m, int v) : mass(m), value(v) { }    

    int mass;
    int value;
};

struct Compare
{
    bool operator()(Jewel a, Jewel b) 
    {
        if (a.value < b.value)
            return true;
        else if (a.value == b.value)
        {
            if (a.mass > b.mass)
            return true;
        }

        return false;
    }
};


int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    priority_queue<Jewel , vector<Jewel>, Compare> pq;
    //priority_queue<Jewel , vector<Jewel>, greater<int>> pq;
    multiset<int> sackVec;
    
    int N,K;
    int M,V;
    int MAX;

    cin >> N >> K;

    while (N--)
    {
        cin >> M >> V;
        pq.push(Jewel(M,V));
    }

    while (K--)
    {
        int C;
        cin >> C;
        MAX = max(C,MAX);
        sackVec.insert(C);
    }

    long long maxValue = 0;
    //sort(sackVec.begin(), sackVec.end());

    while (!pq.empty())
    {
        Jewel top = pq.top();
        pq.pop();
        if (top.mass > MAX) continue;
        if (sackVec.empty()) break;
        for (int i = 0; i < sackVec.size(); i++)
        {
            auto it = sackVec.lower_bound(top.mass);
            if (it != sackVec.end())
            {
                maxValue += top.value;
                sackVec.erase(it);
                break;
            }
        }
    }

    cout << maxValue;
    return 0;
}