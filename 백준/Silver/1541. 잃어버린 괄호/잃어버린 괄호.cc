#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;
stack<int> st;
stack<int> st2;
vector<int> vec;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  string s2;
  cin >> s;
  s += 'e';
  int res;
  
  for (int i = 0; i < s.size(); i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      s2 += s[i];
    } else {
      if (s[i] == '-') {
        st2.push(0);
      } else if (s[i] == '+') {
        st2.push(1);
      }
      st.push(stoi(s2));
      s2 = "";
    }
  }

  bool flag = true;
  res       = st.top();
  st.pop();
  while (!st.empty()) {
    if (st2.top() == 0) {
      if (flag) {
        flag = false;
      }
      vec.push_back(-1 * res);
      res = st.top();
    } else {
      flag = true;
      res += st.top();
    }
    st.pop();
    st2.pop();
  }
  for (auto a : vec) {
    res += a;
  }
  cout << res;
}