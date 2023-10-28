#include <bits/stdc++.h>
#define MAX 1001

int arr[50];
using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
      return a.first > b.first;
    }
    return a.second > b.second;
  }
};

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
  int index = 0;
  for (int i = 0; i < s.size(); i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      s2 += s[i];
    } else {
      if (s[i] == '-') {
        st2.push(0);
      } else if (s[i] == '+') {
        st2.push(1);
      }
      int temp = stoi(s2);
      st.push(temp);
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
        vec.push_back(-1 * res);
        res = st.top();
      } else {
        vec.push_back(-1 * res);
        res = st.top();
      }

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
// 55 -50 40 -30 20
// 1 -2 -3 4 -5