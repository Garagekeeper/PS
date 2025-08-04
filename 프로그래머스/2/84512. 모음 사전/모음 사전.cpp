#include <string>
#include <vector>
using namespace std;

int answer = 0;
int cnt = 0;
string charList = "AEIOU";

void dfs(string current, string target)
{
    if (answer != 0) return;
    if (current.size() > 5) return;

    if (current == target)
    {
        answer = cnt;
        return;
    }

    cnt++;
    for (int i=0; i<5; i++)
    {
        dfs(current + charList[i], target);
        if (answer != 0) return;
    }
}

int solution(string word)
{
    dfs("", word);
    return answer;
}