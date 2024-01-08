#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

std::vector<int> zfunc(const std::string& s) {
  const int n = s.size();
  std::vector<int> z(n, 0);

  for (int i = 1, l = 0, r = 0; i != n; ++i) {
    if (r >= i) {
      z[i] = std::min(z[i - l], r - i + 1);
    }

    while (i + z[i] < n && s[z[i]] == s[z[i] + i])
      z[i]++;

    if (r < i + z[i] - 1) {
      l = i;
      r = i + z[i] - 1;
    }
  }

  return z;
}

int main() {
  std::string s, t; std::cin >> s >> t;

  std::reverse(t.begin(), t.end());
  std::string st = s + '#' + t;

  /* std::cout << "st = " << st << "\n"; */
  auto z = zfunc(st);

  int pos = s.size() + 1;
  for (int i = s.size() + 1; i < st.size(); ++i) {
    if (i + z[i] == st.size()) {
      pos = i;
      break;
    }
  }

  if (pos + z[pos] == st.size() && pos != s.size() + 1) {
    std::reverse(st.begin() + pos, st.begin() + pos + z[pos]);
    pos = pos - s.size() - 1;
  } else {
    std::reverse(st.begin() + pos + z[pos], st.end());
    pos = pos + z[pos] == st.size() ? 1 : z[pos];
  }

  /* std::cout << "st = " << st << "\n"; */

  z = zfunc(st);
  if (z[s.size() + 1] == t.size()) {
    std::cout << "Yes\n" << pos;
  } else {
    std::cout << "No";
  }

  return 0;
}
