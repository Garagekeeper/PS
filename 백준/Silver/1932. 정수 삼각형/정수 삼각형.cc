#include <bits/stdc++.h>

long long arr[200000];
long long max = 0;
int n;

int main() {
  scanf("%d", &n);
  int cnt   = 1;
  int index = 2;
  scanf("%d", &arr[1]);
  max       = arr[1];
    
  for (int i = 2; i <= n; i++, cnt++) {
    for (int j = 1; j <= i; j++, index++) {
      int temp;
      scanf("%d", &temp);
      if (j == 1) {
        arr[index] = temp + arr[index - cnt];
      } else if (j == i) {
        arr[index] = temp + arr[index - (cnt + 1)];
      } else {
        arr[index] = std::max(arr[index - (cnt + 1)], arr[index - cnt]) + temp;
      }
      max = max > arr[index] ? max : arr[index];
    }
  }

  printf("%d\n", max);
}
