#include <vector>
#include <iostream>

int zfunc(const std::vector<int>& s, int n) {
  /* const int n = s.size(); */
  int z = 0;

  /* for (int i = stop, l = 0, r = 0; i != n; ++i) { */
  /*   if (r >= i) */
  /*     z[i] = std::min(z[i - l], r - i + 1); */

    while (s[n + z] == s[z])
      z++;

    /* if (r < i + z[i] - 1) { */
    /*   l = i; */
    /*   r = i + z[i] - 1; */
    /* } */
    /* if (i == stop) break; */
  /* } */

  return z;
}

int main() {
  int n, m; std::cin >> n >> m;
  std::vector<int> colors(n);
  for (int i = 0; i != n; ++i)
    std::cin >> colors[i];

  std::vector<int> zstr{colors};
  zstr.push_back(m + 1);
  zstr.resize(zstr.size() + n / 2 + 1);
  for (int k = n % 2 == 0 ? n / 2 : n / 2 + 1; k < n; ++k) {

    for (int i = 0; i < n - k; ++i)
      zstr[n + n - k - i] = zstr[n - k + i];

    int z = zfunc(zstr, n + 1);

    if (z >= n - k)
      std::cout << k << " ";
    
  }

  std::cout << n;

  return 0;
}
