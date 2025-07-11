#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) 
{
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for (int i=citations.size() - 1; i>=0; i--)
    {
        int h = citations.size() - i;
        if (h <= citations[i])
            answer = h;
    }
    return answer;
}