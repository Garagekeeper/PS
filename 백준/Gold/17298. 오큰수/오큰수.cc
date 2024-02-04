#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int sequence[MAX];
int ans[MAX];
stack<int> st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int size;
  cin >> size;
  for (int i = 0; i < size; i++) {
    cin >> sequence[i];
  }

  for (int i = size - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= sequence[i]) st.pop();

    ans[i] = st.empty() ? -1 : st.top();
    st.push(sequence[i]);
  }

  for (int i = 0; i < size; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
