#include <bits/stdc++.h>
using namespace std;

int n;
int x;
priority_queue<int> pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int res;

  cin >> n;
  while (n--) {
    cin >> x;
    res = 0;
    if (x == 0) {
      if (!pq.empty()) {
        res = (-pq.top());
        pq.pop();
      }
      cout << res << "\n";
    } else {
      pq.push(-x);
    }
  }
}