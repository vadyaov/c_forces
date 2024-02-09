#include <vector>
#include <iostream>

std::vector<int> zFunc(const std::vector<int>& s) {
  const int n = s.size();
  std::vector<int> z(n, 0);

  for (int i = 1, l = 0, r = 0; i != n; ++i) {
    if (r >= i)
      z[i] = std::min(z[i - l], r - i + 1);

    while (i + z[i] < n && s[i + z[i]] == s[z[i]])
      z[i]++;

    if (r < i + z[i] - 1) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

int main() {
  int n, m; std::cin >> n >> m;
  std::vector<int> colors(n);
  for (int i = 0; i != n; ++i)
    std::cin >> colors[i];

  for (int i = 0; i < n; ++i)
    colors.push_back(colors[n - i - 1]);

  auto z = zFunc(colors);

  for (int k = n % 2 == 0 ? n / 2 : n / 2 + 1; k < n; ++k)
    if (z[2 * k] >= n - k) std::cout << k << " ";

  std::cout << n;

  return 0;
}
