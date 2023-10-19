#include <bits/stdc++.h>

int n;
int main() {
  std::priority_queue<int> pq;
    
  scanf("%d", &n);
    
  while (n--) {
    int temp;
    scanf("%d\n", &temp);
      
    if (temp == 0) {
      if (pq.size() == 0) {
        printf("0\n");
      } else {
        printf("%d\n", pq.top());
        pq.pop();
      }
    } else {
      pq.push(temp);
    }
  }
}
