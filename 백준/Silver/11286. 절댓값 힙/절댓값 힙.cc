#include <bits/stdc++.h>
using namespace std;

int n;
int x;

struct cmp {
  bool operator()(int a, int b) {
    if (abs(a) > abs(b))
      return true;
    else if (abs(a) == abs(b)) {
      if (a > b)
        return true;
      else
        return false;
    }
    return false;
  }
};

priority_queue<int, vector<int>, cmp> pq;

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
        res = (pq.top());
        pq.pop();
      }
      cout << res << "\n";
    } else {
      pq.push(x);
    }
  }
}