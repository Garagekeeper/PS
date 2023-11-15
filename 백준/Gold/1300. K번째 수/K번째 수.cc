#include <bits/stdc++.h>
using namespace std;

long long n;
long long k;

long long bi_search(long long left, long long right) {
  long long mid;
  long long res  = 0;

  while (left <= right) {
    long long cnt = 0;
    mid           = (left + right) / 2;
    for (int i = 1; i <= n; i++) {
      // i 행에서 열의 크기 n과, mid이하인 i의 배수
      cnt += min(n, mid / i);
    }

    if (cnt >= k) {
      res   = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin >> k;

  cout << bi_search(1, k);
}
