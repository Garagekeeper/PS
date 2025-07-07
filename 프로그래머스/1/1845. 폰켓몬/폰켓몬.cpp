#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> poketmon;
    int targetNum = nums.size()/2;
    
    for (int i=0; i<nums.size(); i++)
    {
        poketmon.insert(nums[i]);
    }
    
    answer= min(targetNum, (int)poketmon.size());
    return answer;
}