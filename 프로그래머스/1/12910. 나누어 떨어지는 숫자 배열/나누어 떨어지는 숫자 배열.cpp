#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    if (divisor == 1)
    {
        sort(arr.begin(), arr.end());   
        return arr;
    }
    
    for (int i =0; i <= arr.size(); i++)
    {
        if (i == arr.size())
        {
            if ( answer.size() == 0 )
                answer.push_back(-1);
        }
        else
        {
            if ((arr[i] % divisor) == 0) answer.push_back(arr[i]);
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}