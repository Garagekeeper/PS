#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

int L,C;
string cList = "";
string vowels ="aeiou";
vector<int> cListVisited;
int vowelCnt = 0;

bool isVowel(char c)
{
    if (find(vowels.begin(), vowels.end(), c) != vowels.end()) return true;
    return false;
}

void dfs(int index, string password, int ccnt, int vcnt)
{
    if (password.size() == L)
    {
        if (ccnt < 2) return;
        if (vcnt < 1) return;
            
        cout << password << '\n';
        return;
    }

    for (int i = index; i<cList.size(); i++)
    {
        if (cListVisited[i]) continue;
        if (*(password.end()-1) > cList[i]) continue;
        cListVisited[i] = true;
        if (isVowel(cList[i])) 
            dfs(index + 1, password + cList[i], ccnt, vcnt+1);
        else
            dfs(index + 1, password + cList[i], ccnt+1, vcnt);
        cListVisited[i] = false;
    }
}

int main()
{
    cin >> L >> C;

    while(C--)
    {
        char temp;
        cin>>temp;
        cList += temp;
    }

    sort(cList.begin(), cList.end());
    cListVisited.resize(cList.size(),false);
    dfs(0, "", 0, 0);
    return 0;
}