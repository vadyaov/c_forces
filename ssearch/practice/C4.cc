#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> ZFunc(const std::string& s) {
  const int sz = s.size();
  std::vector<int> z(sz, 0);

  for (int i = 1, l = 0, r = 0; i != sz; ++i) {
    if (r >= i)
      z[i] = std::min(z[i - l], r - i + 1);

    while (z[i] + i < sz && s[i + z[i]] == s[z[i]])
      z[i]++;

    if (z[i] > r - i + 1) {
       l = i;
       r = i + z[i] - 1;
    }
  }

  return z;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int32_t n;
  std::cin >> n;

  std::string s;
  for (int k = 0; k != n; ++k) {
    std::cin >> s;

    std::vector<int> z = ZFunc(s);
    std::vector<int> freqs(s.size(), 0);

    for (int len : z) {
      if (len > 0) {
        ++freqs[len - 1];
      }
    }
    freqs.back() = 1;

    for (int i = freqs.size() - 1; i >= 1; --i)
      freqs[i - 1] += freqs[i];

    for (int f : freqs)
      std::cout << f << " ";
    std::cout << "\n";
  }

  return 0;
}
