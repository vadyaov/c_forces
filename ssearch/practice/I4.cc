#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> zfunc(const std::string& s) {
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
  std::string t; std::cin >> t;
  std::string p; std::cin >> p;
  int         k; std::cin >> k;

  std::string t_rev(t.rbegin(), t.rend());
  std::string p_rev(p.rbegin(), p.rend());

  const int n = t.size();
  const int m = p.size();

  auto forw_z = zfunc(p + '#' + t);
  auto revr_z = zfunc(p_rev + '#' + t_rev);

  int a, b;
  for (int l = 0; l < n - m + 1; ++l) {
    a = forw_z[m + l];
  }

  return 0;
}
