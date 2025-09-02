#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) 
{
    long long answer = 0;
    int load = 0;
    
    vector<int> dvec;
    vector<int> pvec;
    
    for (int i=0; i < deliveries.size(); i++)
    {
        //if (deliveries[i] != 0) dvec.push_back(i);
        //if (pickups[i] != 0) pvec.push_back(i);
    }
    
    int didx = n-1;
    int pidx = n-1;
    while ( didx >= 0 || pidx >= 0)
    {
        //if (!(didx >= 0 && pidx >= 0)) break;
        
        //int didx = dvec.back();
        //int pidx = pvec.back();
        
        while (didx >= 0 && deliveries[didx] == 0) didx--;
        while (pidx >= 0 && pickups[pidx] == 0) pidx--;
        
        answer += max(didx+1, pidx+1) * 2;
        load = cap;
       
        // 배달 처리
        //if (dvec.empty()) continue;
        while ( didx >= 0 && load > 0)
        {
            if (deliveries[didx] > load) 
            {
                deliveries[didx] -= load;
                load = 0;
            }
            else 
            {
                load -= deliveries[didx];
                deliveries[didx] = 0;
                didx--;
                //dvec.pop_back();
            }
            
            //if (dvec.empty()) break;
            //didx = dvec.back();
        }
        
        load = 0;
        
        // 수거 처리
        //if (pvec.empty()) continue;
        while (load < cap && pidx >= 0)
        {
            if (cap - load < pickups[pidx])
            {
                pickups[pidx] -= cap - load;
                load = cap;
            }
            else
            {
                load += pickups[pidx];
                pickups[pidx] = 0;
                pidx--;
                //pvec.pop_back();
            }
            //if (pvec.empty()) break;
            //pidx = pvec.back();
        }
    }
    
    return answer;
}
