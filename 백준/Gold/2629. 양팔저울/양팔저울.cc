#include <bits/stdc++.h>
#define MAX 15001
using namespace std;

bool dp[31][MAX];
int balance_weight[31];
int num_of_balance_weight, num_of_marble;

// dp[x][y]: x까지의 추들을 사용해서 y를 만들수 있는가?
void ps(int i, int w) {
  if (i > num_of_balance_weight || dp[i][w]) return;
  dp[i][w] = 1;
  ps(i + 1, w + balance_weight[i]);
  ps(i + 1, abs(balance_weight[i] - w));
  ps(i + 1, w);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int prifix_sum = 0;
  cin >> num_of_balance_weight;

  for (int i = 0; i < num_of_balance_weight; i++) {
    cin >> balance_weight[i];
  }

  ps(0, 0);

  cin >> num_of_marble;
  for (int i = 1; i <= num_of_marble; i++) {
    int temp;
    cin >> temp;
    if (temp > 15000)
      cout << "N ";
    else {
      if (dp[num_of_balance_weight][temp])
        cout << "Y ";
      else
        cout << "N ";
    }
  }
}
