#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) 
{
    int answer = 0;
    int n = people.size();
    int left=0, right=n-1;
    
    vector<bool> visited(n,false);
    
    sort(people.begin(), people.end());
    
    int remain = limit;
    while(left <= right)
    {
        int val = people[right];
        
        if (val + people[left] <= limit)
        {
            val += people[left];
            left++;
        }
        
        answer++;
        right--;
    }
    
    return answer;
}