#include <iostream>
#include <stack>
#include <map>
#include <string>

#define NMAX 1000
#define MMAX 1000
using namespace std;

void solution(const string& s)
{
  // 연산자 우선순위
  map<char, int> operatorPrecedence = {
    {'(',0},
    {'+',1},
    {'-',1},
    {'*',2},
    {'/',2},
  };

  stack<char> st;
  auto it = s.begin();
  while (it != s.end())
  {
  
    //0. 연산자인 경우
    if (*it == '+' || *it == '-' || *it == '*' || *it == '/')
    {
      // 스택이 비어 있으면 넣음
      if (st.empty())
      {
        st.push(*it);
      }
      // 1. stack 맨위의 연산자가 우선 순위가 높은 경우
      else if (operatorPrecedence[st.top()] >= operatorPrecedence[*it])
      {
        // 맨위의 연산자보다 자기의 연산자가 커질때까지
        while( !st.empty() && operatorPrecedence[st.top()] >= operatorPrecedence[*it])
        {
          cout << st.top();
          st.pop();
        }
        st.push(*it);
      }
      else 
      {
        st.push(*it);
      }
     
    }
    //1. 괄호인 경우
    else if (*it == '(' || *it == ')')
    {
      if (*it == '(') st.push(*it);
      else if (*it == ')')
      {
        while (st.top() != '(')
        {
          cout << st.top();
          st.pop();
        }
        st.pop();
      }
      
    }
    //2. 일반 문자일 경우
    else 
    {
      // 바로 출력
      cout<<*it;
    }
    ++it;
  }

  while (!st.empty())
  {
    cout << st.top();
    st.pop();
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  string s;

  cin.tie(0);
  cin >> s;

  solution(s);
}