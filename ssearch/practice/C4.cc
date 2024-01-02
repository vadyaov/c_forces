#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/* #include <sstream> */
/* #include <iterator> */

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
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> res(n);

  for (int k = 0; k != n; ++k) {
    std::string s;
    std::cin >> s;

    res[k].reserve(s.size());
    std::vector<int> z = ZFunc(s);
    
    for (int i = 1; i != s.size(); ++i) {
      res[k].push_back(1 + std::count_if(z.begin() + 1, z.end() - i + 1, [i](int a) {
            return a >= i;}
            ));
    }
    res[k].push_back(1);
  }

  for (const auto& ivec : res) {
    for (int i : ivec)
      std::cout << i << " ";
    std::cout << std::endl;
    /* std::stringstream result; */
    /* std::copy(ivec.begin(), ivec.end(), std::ostream_iterator<int>(result, " ")); */
    /* std::cout << result.str() << std::endl; */
  }

  return 0;
}
