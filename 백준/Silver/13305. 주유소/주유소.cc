#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

long long dist[MAX];
long long city[MAX];
long long city_minimun[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  long long res  = 0;
  cin >> n;

  for (int i = 1; i < n; i++) {
    cin >> dist[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> city[i];
  }

  city_minimun[1] = city[1];
  for (int i = 2; i <= n; i++) {
    city_minimun[i] = min(city[i], city_minimun[i - 1]);
  }

  for (int i = 1; i < n; i++) {
    res += city_minimun[i] * dist[i];
  }

  cout << res;
}
