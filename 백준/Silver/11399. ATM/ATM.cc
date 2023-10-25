#include <bits/stdc++.h>
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
vector<int> vec;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;
    
  vec.push_back(0);
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    vec.push_back(temp);
  }

  sort(vec.begin(), vec.end());

  for (int k = 0; k < 2; k++) {
    for (int i = 1; i <= n; i++) {
      vec.at(i) += vec.at(i - 1);
    }
  }
  cout << vec.at(n);
}