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

    std::string st_answer, ts_answer;

    for (int i = s.size() + 1; i < st.size(); ++i) {
      if (zst[i] == s.size()) {
        st_answer = t;
        break;
      }
    }

    for (int i = t.size() + 1; st_answer.empty() && i < ts.size(); ++i) {
      if (i + zts[i] == zts.size())
        st_answer = s + std::string(t.begin() + zts[i], t.end());
    }

    for (int i = t.size() + 1; i < ts.size(); ++i) {
      if (zts[i] == t.size()) {
        ts_answer = s;
        break;
      }
    }

    for (int i = s.size() + 1; ts_answer.empty() && i < st.size(); ++i) {
      if (i + zst[i] == zst.size()) {
        ts_answer = t + std::string(s.begin() + zst[i], s.end());
      }
    }

    if (ts_answer.empty()) ts_answer = t + s;
    if (st_answer.empty()) st_answer = s + t;

    if (st_answer.size() < ts_answer.size())
      std::cout << st_answer << "\n";
    else
      std::cout << ts_answer << "\n";

  }

  return 0;
}
