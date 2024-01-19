#include <vector>
#include <iostream>

std::vector<int> zfunc(const std::vector<int>& s, int stop) {
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
    if (i == stop) break;
  }

  return z;
}

int main() {
  int n, m; std::cin >> n >> m;
  std::vector<int> colors(n, 0);
  for (int i = 0; i != n; ++i)
    std::cin >> colors[i];

  std::vector<int> zstr{colors};
  zstr.push_back(m + 1);
  zstr.resize(zstr.size() + n);
  for (int k = n / 2; k < n; ++k) {
    int i = 0;
    int last = zstr.size() - i - 1;
    for (; i < k; ++i, --last) {
      zstr[last] = zstr[n - i - 1];
    }

    for (int add = 1; last > n; --last, add += 2){
      zstr[last] = zstr[last + add];
    }

/*     for (int zs : zstr) */
/*       std::cout << zs << " "; */
/*     std::cout << "\n"; */

    auto z = zfunc(zstr, n + 1);

    if (z[n + 1] == n)
      std::cout << k << " ";
    
  }

  std::cout << n;

  return 0;
}
