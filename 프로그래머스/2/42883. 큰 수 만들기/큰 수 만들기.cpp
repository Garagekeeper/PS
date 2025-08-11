#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(string number, int k) 
{
    string answer = "";
    
    stack<char> st;
    for (int i = 0; i<number.size(); i++)
    {
        while (!st.empty())
        {
            if (st.top() >= number[i]) break;
            if (k==0) break;
            st.pop();
            k--;
        }
        st.push(number[i]);
    }
    
    while(k!=0)
    {
        st.pop();
        k--;
    }
    
    while(!st.empty())
    {
        answer += st.top();
        st.pop();
    }
    
    return string(answer.rbegin(), answer.rend());
}