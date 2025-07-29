#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> diff;

int solution(string name) {
    int answer = INT_MAX;
    
    for (auto& c : name)
    {
        diff.push_back(min(c - 'A', 'Z' + 1 - c));
    }
    
    int next = 0;
    for (int i = 0; i<diff.size(); i++)
    {
        next = i + 1;
        while(diff[next] == 0 && next < diff.size()) 
            next++;
        
        int dist = min( 2 * i + (diff.size() - next), 2 * (diff.size() - next) + i);
        answer = min (dist, answer);
    }
    
    for (auto& val : diff)
    {
        answer += val;
    }
    
    
    return answer;
}

/*
abcdefghijklm
nopqrstuvwsyz
*/