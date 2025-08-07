#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;

int solution(int N, int number) 
{
    int answer = 0;
    
    if (number == N) return 1;
    int temp = N;
    vector<unordered_set<int>> vecofset(9);
    vecofset[1].insert(N);
    
    for (int i=2; i<9; i++)
    {
        int seqN=0;
        for (int j=0; j<i; j++)
        {
            seqN = seqN*10 + N; 
        }
        
        vecofset[i].insert(seqN);
        for (int j=1; j<i; j++)
        {
            for(auto e1 : vecofset[j])
            {
                for (auto e2 : vecofset[i-j])
                {
                    vecofset[i].insert(e1 + e2);
                    vecofset[i].insert(e1 - e2);
                    vecofset[i].insert(e1 * e2);
                    if (e2 != 0)
                        vecofset[i].insert(e1 / e2);
                }
            }
        }
        
        if (vecofset[i].count(number)) return i;
    }

    return -1 ;
}

