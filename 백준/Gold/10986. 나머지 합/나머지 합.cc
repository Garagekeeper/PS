#include <bits/stdc++.h>
#define MAX 1000
using namespace std;
long long arr[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  long long cnt       = 0;
  long long sum = 0;

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;

    sum += temp;
    if (sum % m == 0) cnt++;
    arr[(sum) % m]++;
  }

  for (int i = 0; i < m; i++) {
    if (arr[i] >= 2) {
      cnt += (arr[i] * (arr[i] - 1)) / 2;
    }
  }
  cout << cnt;
}
