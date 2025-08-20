#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int answer = 0;

int solution(vector<int> A, vector<int> B) 
{   
    map<int,int> BEcnt;
    sort(A.begin(), A.end());
    
    for (auto& b : B)
    {
        BEcnt[b]++;
    }
    
    sort(B.rbegin(), B.rend());
    
    int maxA = *max_element(A.begin(), A.end());
    int maxB = *max_element(B.begin(), B.end());
    int minA = *min_element(A.begin(), A.end());
    int minB = *min_element(B.begin(), B.end());
    
    if (maxA < minB) return A.size();
    if (minA >= maxB) return 0;
    
    for (int i=0; i<A.size(); i++)
    {
        if (BEcnt.size() == 0) break;
        auto it = BEcnt.upper_bound(A[i]);
        //if (it == BEcnt.end()) break;
        if (it != BEcnt.end())
        {
            answer++;
            int key = it->first;
            BEcnt[key]--;
            if (BEcnt[key] == 0)
                BEcnt.erase(key);
        }
        
    }
    
    return answer;
}

