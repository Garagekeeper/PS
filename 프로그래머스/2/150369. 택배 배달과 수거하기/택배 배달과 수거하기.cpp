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
        if (deliveries[i] != 0) dvec.push_back(i);
        if (pickups[i] != 0) pvec.push_back(i);
    }
    
    int ddidx = dvec.size() - 1;
    int ppidx = pvec.size() - 1;
    
    while (true)
    {
        if (ddidx<0 && ppidx<0) break;

        //int dist = 0;
        //if (ddidx>=0) dist = max(dist, dvec[ddidx]+1);
        //if (ppidx>=0) dist = max(dist, pvec[ppidx]+1);
        answer += max(dvec[ddidx]+1, pvec[ppidx]+1) * 2;
        //answer += dist * 2;
        load = cap;
       
        // 배달 처리
        while (load > 0 && ddidx >=0)
        {
            if (deliveries[dvec[ddidx]] > load) 
            {
                deliveries[dvec[ddidx]] -= load;
                load = 0;
            }
            else 
            {
                load -= deliveries[dvec[ddidx]];
                deliveries[dvec[ddidx]] = 0;
                ddidx--;
            }
            
        }
        
        load = 0;
        
        // 수거 처리
        
        while (load < cap && ppidx >= 0)
        {
            if (cap - load < pickups[pvec[ppidx]])
            {
                pickups[pvec[ppidx]] -= cap - load;
                load = cap;
            }
            else
            {
                load += pickups[pvec[ppidx]];
                pickups[pvec[ppidx]] = 0;
                ppidx--;
            }
        }
    }
    
    return answer;
}
