#include <iostream>
#include <string>
#include <vector>

int ZFunc(const std::string& s, int t_sz) {
  const int sz = s.size();
  std::vector<int> z (sz, 0);
  int result = -1;

  for (int i = 0, l = 0, r = 0; i != sz; ++i) {
    if (r >= i)
      z[i] = std::min(z[i - l], r - i + 1);

    while (i + z[i] < sz && s[i + z[i]] == s[z[i]])
      z[i]++;

    if (z[i] == t_sz) {
      result = i - t_sz - 1;
      break;
    }

    if (i > 2 * t_sz) break;

    if (r < i + z[i] - 1) {
      l = i;
      r = i + z[i] - 1;
    }

  }

  return result;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<int> res(n);

  for (int k = 0; k < n; ++k) {
    std::string s, t;
    std::cin >> s >> t;

    std::string total {t + '$' + s + s};
    res[k] = ZFunc(total, t.size());
  }

  for (int r : res)
    std::cout << r << std::endl;

  return 0;
}
