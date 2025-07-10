#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(), citations.end());
    
    for (int i=0; i<citations.size(); i++)
    {
        int h = citations.size() - i;
        if (h <= citations[i])
            answer = max(answer , h);
            
    }
    return answer;
}