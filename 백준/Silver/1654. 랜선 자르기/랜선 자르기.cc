#include <bits/stdc++.h>
#define MAX 10000
using namespace std;

int number[MAX];
int n, k;
long long max_len = 0;

long long bi_search(long long left, long long right) {
  int cnt = 0;
  long long mid;
  long long res = 0;

  while (left <= right) {
    mid = (left + right) / 2;
    cnt = 0;
    for (int i = 0; i < k; i++) {
      if (number[i] == mid)
        cnt++;
      else
        cnt += number[i] / mid;
    }

    if (cnt >= n) {
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

  cin >> k >> n;
  for (int i = 0; i < k; i++) {
    cin >> number[i];
    max_len = max_len > number[i] ? max_len : number[i];
  }

  cout << bi_search(1, max_len);
}
// 1 2 3 4 5 6
// 1 2