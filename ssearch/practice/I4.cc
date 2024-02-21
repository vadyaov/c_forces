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

  const int n = t.size();
  const int m = p.size();

  auto forw_z = zfunc(p + '#' + t);

  std::reverse(t.begin(), t.end());
  std::reverse(p.begin(), p.end());

  auto revr_z = zfunc(p + '#' + t);

  std::vector<int> answ;

  for (int l = 0; l < n - m + 1; ++l) {
    int a = forw_z[m + l + 1];
    int b = revr_z[n - l + 1];

    if (a + b >= m - k)
      answ.push_back(l + 1);
  }

  std::cout << answ.size() << "\n";
  for (int answer : answ)
    std::cout << answer << " ";

  return 0;
}
