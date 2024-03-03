#include <algorithm>
#include <iostream>
#include <stack>

#define MAX 100002
using namespace std;

int ans, N, h[MAX];
stack<int> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> N;

  for (int i = 1; i <= N; i++) cin >> h[i];

  s.push(0);
  for (int i = 1; i <= N + 1; i++) {
    while (!s.empty() && h[s.top()] > h[i]) {
      int check = s.top();
      s.pop();
      ans = max(ans, h[check] * (i - s.top() - 1));
    }
    s.push(i);
  }
  cout << ans;
}