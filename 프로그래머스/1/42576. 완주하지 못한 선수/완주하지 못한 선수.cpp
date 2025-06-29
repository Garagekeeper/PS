#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, int> pmap;
    
    for(int i=0; i < participant.size(); i++)
    {
        string pstring = participant[i];
        if (pmap.find(pstring) == pmap.end())
        {
            pmap[pstring] = 1;
        }
        else 
        {
            pmap[pstring]++;
        }
    }
    
    for(int i=0; i < completion.size(); i++)
    {
        string cstring = completion[i];
        if (pmap.find(cstring) != pmap.end())
        {
            pmap[cstring]--;;
        }
    }
    
    for(int i=0; i < participant.size(); i++)
    {
        string pstring = participant[i];
        if (pmap[pstring] > 0)
        {
            answer = pstring;
            break;
        }
    }
    
    
    return answer;
}