#include <iostream>
#include <algorithm>
#include <vector>

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

  std::string s;
  std::cin >> s;

  int answ = 0;
  std::string suff;

  for (int n = s.size(), i = n - 1; i >= 0; --i) {
    suff = s[i] + suff;

    auto z = zfunc(suff);
    int pref_sz = *std::max_element(z.begin(), z.end());

    while (pref_sz < suff.size()) {
      ++pref_sz;
      answ += pref_sz;
    }
  }

  std::cout << answ;

  return 0;
}
