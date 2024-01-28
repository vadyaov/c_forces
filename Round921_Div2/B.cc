#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  int t; std::cin >> t;
  while (t--) {
    int x, n; std::cin >> x >> n;
    int answer = 1;
    for (int i = 1; i <= i * i; ++i) {
      if (x % i == 0) {
        if (n <= x / i)
          answer = std::max(answer, i);
        if (n <= i)
          answer = std::max(answer, x / i);
      }
    }
    std::cout << answer << "\n";
  }
  return 0;
}
