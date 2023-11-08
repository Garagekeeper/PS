#include <bits/stdc++.h>
#define MAX 100000
using namespace std;

int number[MAX];
int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> number[i];
  }

  sort(number, number + n);
  cin >> m;

  for (int i = 0; i < m; i++) {
    int temp;
    cin >> temp;
    cout << binary_search(number, number + n, temp) << "\n";
  }
}
