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

/*     std::cout << st << "\n"; */
/*     for (int zi : zst) std::cout << zi; */
/*     std::cout << "\n"; */
/*     std::cout << ts << "\n"; */
/*     for (int zi : zts) std::cout << zi; */
/*     std::cout << "\n"; */

    int zmax = 0, imax = 0;
    for (int i1 = s.size() + 1, i2 = t.size() + 1; i1 < zst.size() && i2 < zts.size(); ++i1, ++i2) {
      if (zst[i1] > zmax)
        zmax = zst[i1], imax = i1;
      if (zts[i2] > zmax)
        zmax = zts[i2], imax = i2;
    }

    std::cout << "zmax = " << zmax << " at pos " << imax << "\n";

    if (zmax == zst[imax]) {
      // working with st string and zst func
      std::reverse(st.end() - zmax, st.end());

      int k = 0, last = st.size() - 1, first = 0;
      while (zmax < s.size() && first < zmax && st[last--] == st[first++]) {
        k++;
      }

      std::cout << t + std::string(s.begin() + k, s.end());

    } else {
      // working with ts string and zts func
      std::reverse(ts.end() - zmax, ts.end());

      int k = 0, last = ts.size() - 1, first = 0;
      while (zmax < t.size() && first < zmax && ts[last--] == ts[first++]) {
        k++;
      }

      std::cout << s + std::string(t.begin() + k, t.end());

    }

  }

  return 0;
}
