#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

bool cmp1(pair<string, int> a, pair<string, int> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> totalCount;
    vector<pair<string, int>> totalCountVec;
    unordered_map<string, vector<pair<int, int>>> songListInGenres;
    
    for (int i = 0 ; i < genres.size(); i++)
    {
        totalCount[genres[i]] += plays[i];
        songListInGenres[genres[i]].push_back(make_pair(i, plays[i]));
    }
    
    for (auto it = totalCount.begin(); it != totalCount.end(); ++it)
    {
        totalCountVec.push_back(make_pair(it->first, it->second));
    }
    
    sort(totalCountVec.begin(), totalCountVec.end(), cmp1);
    
    for (auto it = totalCountVec.begin(); it != totalCountVec.end() ; ++it)
    {
        string genres = it->first;
        sort(songListInGenres[genres].begin(), songListInGenres[genres].end() ,cmp2);
        for (int i=0; i<2; i++)
        {
            if (i == songListInGenres[genres].size()) break;
            answer.push_back(songListInGenres[genres][i].first);
        }
    }
    
    return answer;
}