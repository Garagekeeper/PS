#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int sequence[MAX];
int num_cnt[MAX];
int ans[MAX];
stack<int> f;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int size;
  cin >> size;
  for (int i = 0; i < size; i++) {
    cin >> sequence[i];
    num_cnt[sequence[i]]++;
  }

  for (int i = size; i >= 0; i--) {
    while (!f.empty() && num_cnt[f.top()] <= num_cnt[sequence[i]]) f.pop();

    ans[i] = f.empty() ? -1 : f.top();
    f.push(sequence[i]);
  }

  for (int i = 0; i < size; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}