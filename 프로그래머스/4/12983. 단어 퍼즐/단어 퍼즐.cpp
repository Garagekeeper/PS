#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
using namespace std;

int solution(vector<string> strs, string t)
{
    int answer = 0;
    unordered_set<string> piecesHahsSet;
    vector<int> dp(t.size());
    
    for (auto& str : strs)
    {
        piecesHahsSet.insert(str);
    }
    
    if (piecesHahsSet.find(t.substr(0,1)) != piecesHahsSet.end())
        dp[0] = 1;
    
    string currentStr = t.substr(0,1);
    for (int i=1; i<t.size(); i++)
    {
        currentStr += t[i];
        int cnt = 5;
        int minimum = INT_MAX;
        for (int j=i; cnt>=0 && j>=0; j--, cnt--)
        {
            string right = t.substr(j, i-j+1);
            if (piecesHahsSet.find(right) != piecesHahsSet.end())
            {
                if (currentStr == right && i <= 4) minimum = min(minimum, 1);
                else
                {
                    if (dp[j-1] != 0)
                        minimum = min(dp[j-1] + 1, minimum);
                }
            }
        }
        dp[i] = minimum == INT_MAX ? 0 : minimum;
    }
        
    for (int i=0; i<t.size(); i++)
    {
        cout << dp[i] <<" ";
    }

    return dp[t.size()-1] == 0 ? -1 : dp[t.size()-1];
}
