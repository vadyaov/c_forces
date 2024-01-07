#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t; std::cin >> t;

  while (t--) {
    int a, b; std::cin >> a >> b;
    if ((a + b) % 2 == 0)
      std::cout << "Bob\n";
    else
      std::cout << "Alice\n";
  }

  return 0;
}
