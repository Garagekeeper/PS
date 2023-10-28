#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  string s;
  string s2;
  cin >> s;
  int res;

  bool flag = false;

  for (int i = 0; i <= s.size(); i++) {
    if (s[i] == '-' || s[i] == '+' || s[i] == '\0') {
      if (flag)
        res -= stoi(s2);
      else
        res += stoi(s2);

      s2 = "";

      if (s[i] == '-') {
        flag = true;
        continue;
      }
    }
    s2 += s[i];
  }
  cout << res;
}
