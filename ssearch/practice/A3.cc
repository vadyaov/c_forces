#include <string>
#include <vector>
#include <iostream>

int main() {

  std::string s;
  std::cin >> s;

  std::vector<int> z(s.size(), 0);

  int l = 0, r = 0;
  for (int i = 1; i != z.size(); ++i) {
    if (r >= i) {
      if (z[i - l] < r - i + 1) {
        z[i] = z[i - l];
      } else {
        z[i] = r - i + 1;
        while (i + z[i] < z.size() && s[i + z[i]] == s[z[i]])
          z[i]++;
      }
    } else {
      while (i + z[i] < z.size() && s[i + z[i]] == s[z[i]])
        z[i]++;
    }

    if (r < i + z[i] - 1) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  for (int z_ : z)
    std::cout << z_ << " ";

  return 0;
}
