#include <bits/stdc++.h>
#define MAX 100002
using namespace std;

int h[MAX];
stack<int> s;
int ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  
  int size;
  cin >> size;

  for (int i = 1; i <= size; i++) cin >> h[i];

  s.push(0);
  for (int i = 1; i <= size + 1; i++) {
    while ((!s.empty() && h[s.top()] > h[i])) {
      int check = s.top();
      s.pop();
      ans = max(ans, h[check] * (i - s.top() - 1));
    }
    s.push(i);
  }

  cout << ans;
}
