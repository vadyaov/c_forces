#include <iostream>
#include <string>
#include <vector>

std::vector<int> ZFunc(const std::string& s) {
  const int sz = s.size();
  std::vector<int> z(sz, 0);

  for (int i = 1, l = 0, r = 0; i != sz; ++i) {
    if (r >= i)
      z[i] = std::min(z[i - l], r - i + 1);

    while (i + z[i] < sz && s[z[i]] == s[i + z[i]])
      z[i]++;

    if (r < i + z[i] - 1) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

int main() {
  std::string s;
  std::cin >> s;

  std::string s2 = s + std::string{s.rbegin(), s.rend()};
  auto z = ZFunc(s2);

  for (int i = s.size(); i != z.size(); ++i) {
    if (i + z[i] == z.size()) {
      std::cout << z[i];
      break;
    }
  }

  return 0;
}
