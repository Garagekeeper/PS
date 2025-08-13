#include <string>
#include <vector>
#include <queue>

using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) 
{
    int answer = 0;
    queue<pair<int,int>> q;
    int cnt = 0;
    int wsum = 0;
    int time = 0;
    int index = 0;
   while(true)
    {
        time++;
        if (q.empty())
        {   
            if (index >= truck_weights.size()) break;
            q.push(make_pair(truck_weights[index], time));
            wsum += truck_weights[index++];
        }
            
        else
        {

            if (time - q.front().second == bridge_length)
            {
                wsum -= q.front().first;
                q.pop();
            }
            if (index >= truck_weights.size()) continue;
            int truck = truck_weights[index];
            if (wsum + truck <= weight)
            {
                q.push(make_pair(truck, time));
                wsum += truck_weights[index++];
            }
        }
    }
    return time - 1;
}