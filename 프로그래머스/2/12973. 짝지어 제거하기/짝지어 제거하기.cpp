#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;
    int answer = -1;
    
    st.push(s[0]);
    for (int i=1; i < s.size(); i++)
    {
        if (st.empty()) 
            st.push(s[i]);
        else if (st.top() == s[i])
        {
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
    }
    
    answer = st.empty() ? 1 : 0;

    return answer;
}

/*
bababaababab
bababa
bababaa
bababb
babaa
babb
baa
bb
*/