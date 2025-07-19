#include <string>
#include <vector>

using namespace std;
vector<int> gnumbers;
int gtarget;

int dfs(int value, int depth)
{
    int cnt = 0;
    if (depth == gnumbers.size())
    {
        if (value == gtarget) return 1;
        else return 0;
    }
    //-시작
    cnt += dfs(value - gnumbers[depth], depth+1);
    //+시작
    cnt += dfs(value + gnumbers[depth], depth+1);
    
    return cnt;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    gnumbers = numbers;
    gtarget = target;
    
    answer = dfs(0,0);
    
    return answer;
}