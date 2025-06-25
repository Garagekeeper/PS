#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

bool validation(const string& s , int startIndex)
{
    map <char, char> match_pair = {
        {')','('},
        {'}','{'},
        {']','['},
    };
    
    stack<char> leftOpen;
    for (int j=0; j < s.size(); j++)
    {
        // 왼쪽으로 j칸 회전
        int index = (startIndex + j) % s.size();
        char c = s[index];
        
        if (c == '(' || c == '[' || c == '{')
        {
            leftOpen.push(c);
        }
        else 
        {
            if (leftOpen.empty()) return false;
            if (leftOpen.top() != match_pair[c]) return false;
            
            leftOpen.pop();
        }
    }
    
    return leftOpen.empty();
}

int solution(string s) {
    int answer = 0;
    stack<char> leftOpen;
    
    for (int i = 0; i < s.size(); i++)
    {
       if (validation(s, i)) answer++;
    }
    
    return answer;
}
