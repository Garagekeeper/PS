#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) 
{
    vector<int> answer;
    unordered_set<int> lottoSet;
    
    int zero = 0;
    int match = 0;
    
    for (int i = 0; i<lottos.size(); i++)
    {
        if (lottos[i] == 0) zero++;
        else
            lottoSet.insert(lottos[i]);
    }
    
    for (int i=0; i<win_nums.size(); i++)
    {
        if (lottoSet.find(win_nums[i]) != lottoSet.end()) match++;
    }
    
    //cout << match<< ',' << zero << endl;
    //cout << 7 - match<< ',' << 7 - (match + zero);;
    int maximum = (7 - (match + zero)) == 7 ? 6:7 - (match + zero);
    int minimum = (7 - match) == 7 ? 6 : (7 - match); 
    return {maximum, minimum};
}