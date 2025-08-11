#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const vector<int>& a, const vector<int>& b)
{
    if (a[1] == b[1])
    {
        return a[0] > b[0];
    }
    
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) 
{
    int answer = 0;
    
    sort(routes.begin(), routes.end(), cmp);
    
    int before = routes[0][1];
    
    for (int i=1; i<routes.size(); i++)
    {
        //cout << routes[i][0] << before << routes[i][1] << endl;
        if (routes[i][0] <= before && before <= routes[i][1])
        {
            continue;
        }
        else
        {
            answer++;
            before = routes[i][1];
        }
    }
    
    answer++;
    
    return answer;
}