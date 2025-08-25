#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

// key가 size
unordered_set<int> routeSet;
int n;
int answer = 0;
vector<bool> idVisited;

int CalMatchCnt(string a, string b)
{
    int res = 0;
    for (int i=0; i<a.size(); i++)
    {
        if (a[i] == b[i]) res++;
    }
    
    return res;
}

void dfs(int index,vector<string>& user_id, vector<string>& banned_id)
{
    //cout <<"index: "<< index << endl;
    //cout << "test" << n << endl;
    if (index == n)
    {
        int mask = 0;
        for (int i=0; i<idVisited.size(); i++)
        {
            if(idVisited[i] == 1) mask |= 1 << i;
        }
        if (routeSet.insert(mask).second == false) return;
        
        answer++;
        return;
    }
    
   
    
    int asteriskCnt = 0;
    int len = banned_id[index].size();
    for (int i=0; i<len; i++)
    {
        if (banned_id[index][i] == '*') asteriskCnt++;
    }
    
    for (int i=0; i<user_id.size(); i++)
    {
        int match = 0;
        if (idVisited[i]) continue;
        if (user_id[i].size() !=  banned_id[index].size()) continue;
        match = CalMatchCnt(user_id[i], banned_id[index]);
        //cout << "ust: "<<user_id[i] << " ban: " << banned_id[index] << endl;
        //cout << "match: "<<match << " astCnt: " << asteriskCnt << endl;
        if (match + asteriskCnt != len) continue;
        idVisited[i] = true;
        dfs (index+1,user_id, banned_id);
        idVisited[i] = false;
    }
    
}

int solution(vector<string> user_id, vector<string> banned_id) 
{
    
    n = banned_id.size();
    idVisited = vector<bool>(user_id.size(),false);
    //idMap = vector<string>(user_id.size()+1);

    dfs(0,user_id, banned_id);
    
    return answer;
}