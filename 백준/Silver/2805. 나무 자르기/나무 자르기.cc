#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int number[MAX];
int n, m;
long long max_len = 0;

long long bi_search(long long left, long long right) {
  long long len = 0;
  long long mid;
  long long res = 0;

  while (left <= right) {
    mid = (left + right) / 2;
    len = 0;
    for (int i = 0; i < n; i++) {
      len += number[i] - mid >= 0 ? number[i] - mid : 0;
      // printf("%d\n", len);
    }

    if (len >= m) {
      res  = max(res, mid);
      left = mid + 1;

    } else {
      right = mid - 1;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> number[i];
    max_len = max_len > number[i] ? max_len : number[i];
  }

  cout << bi_search(0, max_len);
}
// 1 2 3 4 5 6
// 1 2