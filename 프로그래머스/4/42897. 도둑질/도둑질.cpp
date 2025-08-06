#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) 
{
    int answer = 0;

    int len = money.size();
    vector<int> dpNotVisited1(len);
    vector<int> dpVisited1(len);

    //처음 집을 방문한 경우
    //그 다음집은 방문 못하니 최댓값은 처음 집의 값.
    dpVisited1[0] = money[0];
    dpVisited1[1] = money[0];

    for (int i=2; i<len-1; i++)
    {
        dpVisited1[i] = max( dpVisited1[i-1], dpVisited1[i-2] + money[i]);
    }

    //처음 집을 방문하지 않은 경우
    dpNotVisited1[1] = money[1];
    for (int i=2; i<len; i++)
    {
        dpNotVisited1[i] = max( dpNotVisited1[i-1], dpNotVisited1[i-2] + money[i]);
    }

    answer = max(dpVisited1[len-2], dpNotVisited1[len-1]);

    return answer;
}