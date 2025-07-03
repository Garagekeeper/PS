#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

vector<int> solution(int n, vector<string> words) 
{
    unordered_set<string> pastWords;
    
    string before = words[0];
    pastWords.insert(words[0]);
    
    int turn = 2;
    for (int i = 1; i  < words.size(); i++)
    {
        int who = (turn % n) == 0 ? (turn % n) + n : (turn % n); 
        int turnCount = ceil(turn / static_cast<double> (n));    
        
        if (before[before.size()-1] != words[i][0])
        {
            return {who, turnCount};    
        }
        else if (pastWords.find(words[i]) != pastWords.end())
        {
            return {who, turnCount};
        }
        else
        {
            pastWords.insert(words[i]);
        }
        turn++;
        before = words[i];
    }
    
    return {0,0};
}