#include <iostream>
#include <string>
#include <vector>

std::string s, t;

int main() {
  int q; std::cin >> q;
  std::string st, ts;

  while (q--) {
    std::cin >> s >> t;
    st = s + '#' + t;
    ts = t + '#' + s;

    std::vector<int> zst(st.size(), 0);
    std::vector<int> zts(st.size(), 0);

    int zmax = 0, imax = 0;
    for (int i = 1, l1 = 0, r1 = 0, l2 = 0, r2 = 0; i != st.size(); ++i) {
      if (r1 >= i)
        zst[i] = std::min(zst[l1 - i], r1 - i + 1);

      if (r2 >= i)
        zts[i] = std::min(zts[l2 - i], r2 - i + 1);

      while (i + zst[i] < st.size() && st[i + zst[i]] == st[zst[i]])
        zst[i]++;

      while (i + zts[i] < st.size() && ts[i + zts[i]] == ts[zts[i]])
        zts[i]++;

      if (zst[i] > zmax && (i == s.size() + 1 || i + zst[i] == st.size() || zst[i] == s.size())) {
        zmax = zst[i];
        imax = i;
      }

      if (zts[i] > zmax && (i == t.size() + 1 || i + zts[i] == ts.size() || zts[i] == t.size())) {
        zmax = zts[i];
        imax = i;
      }

      if (r1 < i + zst[i] - 1) {
        l1 = i;
        r1 = i + zst[i] - 1;
      }

      if (r2 < i + zts[i] - 1) {
        l2 = i;
        r2 = i + zts[i] - 1;
      }
    }

    /* std::cout << "zmax " << zmax << " at pos " << imax << "\n"; */

    if (zst[imax] == zmax) {
      std::cout << t + std::string(s.begin() + zmax, s.end());
    } else {
      std::cout << s + std::string(t.begin() + zmax, t.end());
    }
    std::cout << "\n";

  }

  return 0;
}
