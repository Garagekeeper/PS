#include <bits/stdc++.h>
#define MAX 1000001
using namespace std;

int number[MAX];
int n;
int a;
int length = 0;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin >> number[0];
  length++;

  for (int i = 1; i < n; i++) {
    cin >> a;

    if (number[length - 1] < a) {
      number[length++] = a;
    } else {
      auto temp = lower_bound(number, number + length, a);
      if (temp == number + length) continue;
      int index = temp - number;
      number[index] = a;
    }
  }

  cout << length;
}