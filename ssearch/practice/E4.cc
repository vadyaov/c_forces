#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::vector<int> zfunc(const std::string& s) {
  const int n = s.size();
  std::vector<int> z(n, 0);

  for (int i = 1, l = 0, r = 0; i != n; ++i) {
    if (r >= i) {
      z[i] = std::min(z[i - l], r - i + 1);
    }

    while (i + z[i] < n && s[z[i]] == s[z[i] + i])
      z[i]++;

    if (r < i + z[i] - 1) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

int main() {
  std::string s, t; std::cin >> s >> t;

  if (s.size() != t.size()) {
    std::cout << "No";
    return 0;
  }

  if (s == t) {
    std::cout << "Yes\n" << 0;
    return 0;
  }

  std::string ot {t};
  std::reverse(t.begin(), t.end());

  std::string st = s + '#' + t;

  auto z = zfunc(st);

  int value = z[s.size() + 1];


  for (int k = 1; k <= value; ++k) {
    bool yes = true;
    for (int a = k, j = 0; yes && a != s.size(); ++a, ++j) {
      if (s[a] != ot[j]) yes = false;
    }
    if (yes == true) {
      std::cout << "Yes\n" << k;
      return 0;
    }
  }

  std::cout << "No";


  return 0;
}
