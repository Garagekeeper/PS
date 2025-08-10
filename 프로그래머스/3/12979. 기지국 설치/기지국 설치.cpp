#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    int before = 1;
    int diff;
    if (stations[0] - w >1)
    {
        diff = (stations[0] - w) - before;
        if (diff > 0)
        {
            answer += diff/(2*w + 1);
            if (diff % (2*w + 1) != 0)
                answer++;
        }
    }
    
    before = stations[0];
    
    for (int i=1; i<stations.size(); i++)
    {
        diff = (stations[i] - w) - (before+w) - 1;
        
        if (diff > 0)
        {
            answer += diff/(2*w + 1);
            if (diff % (2*w + 1) != 0)
                answer++;
        }
        before = stations[i];
       
    }
    
    if(n != stations.back())
    {
        diff = (n) - (stations.back()+w);
        if (diff > 0)
        {
            answer += diff/(2*w + 1);
            if (diff % (2*w + 1) != 0)
                answer++;
        }
    }

    return answer;
}