#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, k;
long long DC_power(long long a, int b) {
  long long res = 1;
  if (b == 1) return a % MOD;
  res = DC_power(a, b / 2);
  if (b % 2 == 0) {
    res = res * res % MOD;
  } else {
    res = ((res * res) % MOD * a) % MOD;
  }

  return res;
}

long long factorial(int x) {
  long long res = 1;
  while (x > 1) {
    res = (res * x--) % MOD;
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;

  long long A = 1;
  long long B = factorial(k);
  for (int i = n - k + 1; i <= n; i++) {
    A = (A * i) % MOD;
  }
  long long res = A * (DC_power(B, MOD - 2)) % MOD;

  cout << res;
}
