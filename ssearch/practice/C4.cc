#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

std::vector<int> countGreaterOrEqual(const std::vector<int>& arr) {
    int n = arr.size();

    int max_val = *std::max_element(arr.begin(), arr.end());

    std::vector<int> count(max_val + 1, 0);

    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }

    for (int i = max_val - 1; i >= 0; --i) {
        count[i] += count[i + 1];
    }

    std::vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            res[i] = count[arr[i] - 1];
        }
    }

    return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::vector<std::vector<int>> res(n);

  for (int k = 0; k != n; ++k) {
    std::string s;
    std::cin >> s;

    res[k].resize(s.size(), 1);
    std::vector<int> z = ZFunc(s);

    for (int i = 1; i != z.size(); ++i) {
      while(z[i]--)
        res[k][z[i]]++;
    }
  }

  for (const auto& ivec : res) {
    for (int i : ivec)
      std::cout << i << " ";
    std::cout << std::endl;
  }

  return 0;
}
