#include <bits/stdc++.h>
using namespace std;

string s;
string explosive_string;
string temp;

stack<char> st;

int s_length;
int es_length;

bool CheckExplosive() {
  if (st.size() < es_length) return false;
  temp = "";

  for (int i = 0; i < es_length; i++) {
    temp += st.top();
    st.pop();
  }

  reverse(temp.begin(), temp.end());
  return temp != explosive_string;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  cin >> explosive_string;

  s_length  = s.length();
  es_length = explosive_string.length();

  for (int i = 0; i < s_length; i++) {
    st.push(s[i]);

    if (s[i] == explosive_string.back()) {
      if (CheckExplosive()) {
        int index = 0;

        while (index < es_length) st.push(temp[index++]);
      }
    }
    temp = "";
  }

  if (st.size() == 0)
    cout << "FRULA";
  else {
    temp = "";
    while (!st.empty()) {
      temp += st.top();
      st.pop();
    }

    reverse(temp.begin(), temp.end());
    cout << temp;
  }

  return 0;
}
