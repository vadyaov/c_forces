#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<int> zfunc(const std::string& s) {
  const int sz = s.size();
  std::vector<int> z(sz, 0);

  for (int i = 1, l = 0, r = 0; i != sz; ++i) {
    if (r >= i)
      z[i] = std::min(z[i - l], r - i + 1);
    
    while (i + z[i] < sz && s[i + z[i]] == s[z[i]])
      z[i]++;

    if (r < i + z[i] - 1) {
      l = i;
      r = i + z[i] - 1;
    }

  }

  return z;
}

std::string s, t;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int q; std::cin >> q;
  std::string st, ts;

  while (q--) {
    std::cin >> s >> t;
    st = s + '#' + t;
    ts = t + '#' + s;

    auto zst = zfunc(st);
    auto zts = zfunc(ts);

    std::cout << st << "\n";
    for (int zi : zst) std::cout << zi;
    std::cout << "\n";
    std::cout << ts << "\n";
    for (int zi : zts) std::cout << zi;
    std::cout << "\n";

    int zmax = 0, imax = 0;
    for (int i = st.size() - 1; i > std::min(s.size(), t.size()); --i) {
      if (zst[i] > zmax && i > s.size())
        zmax = zst[i], imax = i;
      if (zts[i] > zmax && i > t.size())
        zmax = zts[i], imax = i;
    }

    /* std::cout << "zmax = " << zmax << " at pos " << imax << "\n"; */

    if (zmax == zst[imax]) {
      // working with st string and zst func

      int k = 0;
      for (int i = st.size() - zmax; i < st.size(); ++i) {
        bool catched = true;
        for (int j = 0; j < st.size() - i; ++j) {
          if (st[j] != st[i + j]) {
            catched = false;
            break;
          }
        }
        if (catched) {
          k = st.size() - i;
          break;
        }
      }

      if (zmax == s.size()) k = zmax;

      std::cout << t + std::string(s.begin() + k, s.end());

    } else {
      // working with ts string and zts func

      int k = 0;
      for (int i = ts.size() - zmax; i < ts.size(); ++i) {
        bool catched = true;
        for (int j = 0; j < ts.size() - i; ++j) {
          if (ts[j] != ts[i + j]) {
            catched = false;
            break;
          }
        }
        if (catched) {
          k = ts.size() - i;
          break;
        }
      }

      if (zmax == t.size()) k = zmax;

      std::cout << s + std::string(t.begin() + k, t.end());

    }

  }

  return 0;
}
