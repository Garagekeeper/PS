#include <algorithm>
#include <iostream>
#include <set>
#include <string>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  int count = 0;
  std::set<std::string> s;

  std::cin >> n >> m;
  while (n--) {
    std::string temp;
    std::cin >> temp;
    s.insert(temp);
  }

  while (m--) {
    std::string temp;
    std::cin >> temp;
    if (s.find(temp) != s.end()) count++;
  }

  std::cout << count << "\n";
}
