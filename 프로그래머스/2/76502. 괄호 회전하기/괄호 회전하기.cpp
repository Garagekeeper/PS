#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = -1;
    stack<char> leftOpen;
    
    for (int i = 0; i < s.size(); i++)
    {
        int pushcnt = 0;
        for (int j=0; j < s.size(); j++)
        {
            int index = (i + j) % s.size();
            if (s[index] == '(' || s[index] == '{' || s[index] == '[')
            {
                leftOpen.push(s[index]);   
                pushcnt++;
            }
            else 
            {
                if (leftOpen.empty())  continue;
                
                if (s[index] == ')')
                {
                    if (leftOpen.top() == '(') leftOpen.pop();
                }
                else if (s[index] == '}')
                {
                if (leftOpen.top() == '{') leftOpen.pop();
                }
                else if (s[index] == ']')
                {
                if (leftOpen.top() == '[') leftOpen.pop();
                }

            }
        }
        if (leftOpen.empty() && pushcnt!=0) answer++;
        while (!leftOpen.empty()) leftOpen.pop();
    }
    answer++;
    return answer;
}
