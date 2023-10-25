#include <bits/stdc++.h>
#define MAX 2001
using namespace std;

struct cmp {
  bool operator()(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
      return a.first > b.first;
    }
    return a.second > b.second;
  }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  long long start, end;

  int n;
  cin >> n;
  while (n--) {
    cin >> start >> end;
    pq.push(make_pair(start, end));
  }

  int cnt  = 0;
  int temp = 0;

  while (!pq.empty()) {
    if (pq.top().first >= temp) {
      cnt++;
      temp = pq.top().second;
    }
    // printf("befor_second:%d current:%d\n", temp, pq.top().first);
    pq.pop();
  }

  cout << cnt;
}
/*
3 5
5 7
*/