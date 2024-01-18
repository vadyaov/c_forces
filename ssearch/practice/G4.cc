#include <vector>
#include <iostream>

std::vector<int> zfunc(const std::vector<int>& s) {
  /* std::cout << " s = " << s << "\n"; */
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
  std::vector<int> colors(n, 0);
  for (int i = 0; i != n; ++i)
    std::cin >> colors[i];

  for (int k = n / 2; k > 0; --k) {
    std::vector<int> zstr{colors};
    zstr.insert(zstr.end(), m + 1);
    zstr.insert(zstr.end(), colors.rbegin(), colors.rend() - k);
    zstr.insert(zstr.end(), colors.begin() + k, colors.end());

    auto z = zfunc(zstr);

    if (z[z.size() - n] == n)
      std::cout << n - k << " ";
    
  }

  std::cout << n;

  return 0;
}
