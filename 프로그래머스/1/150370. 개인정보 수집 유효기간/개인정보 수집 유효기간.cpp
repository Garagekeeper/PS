#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

unordered_map<char, int> termMap;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    vector<int> answer;
    
    int currYear = stoi(today.substr(0,4));
    int currMonth = stoi(today.substr(5,7));
    int currDay = stoi(today.substr(8,10));
    
    for (auto& term : terms)
    {
        termMap[term[0]] = stoi(term.substr(2));
    }
    
    for (int i=1; i <= privacies.size(); i++)
    {
        string temp = privacies[i-1];
        int y = stoi(temp.substr(0,4));
        int m = stoi(temp.substr(5,7));
        int d = stoi(temp.substr(8,10));
        char t = temp.back();
        
        m += termMap[t];
        
        while ( m > 12)
        {
            m -= 12;
            y++;
        }
        
        
        d--;
        if (d==0)
        {
            m--;
            if (m == 0)
            {
                m = 12;
                y--;
            }
            d=28;
        }
        
       
        
        if (currYear > y)
        {
             answer.push_back(i);
        }
        else if (currYear == y)
        {
            if (currMonth > m)
            {
                answer.push_back(i);
            }
            else if (currMonth == m)
            {
                if (currDay > d)
                {
                    answer.push_back(i);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}