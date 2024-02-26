#include <bits/stdc++.h>

using namespace std;

constexpr int max_ = 1e9;

struct m_segtree {
  vector<int> tree;
  int size;

  void init(int n) {
    size = 1;
    while (size < n) size <<= 1;
    tree.assign(2 * size - 1, max_);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }

    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }

    tree[x] = std::min(tree[2 * x + 1], tree[2 * x + 2]);
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  int min(int l, int r, int x, int lx, int rx) {
    if (rx <= l || lx >= r) {
      return max_;
    }

    if (lx >= l && rx <= r) {
      return tree[x];
    }

    int m = (lx + rx) / 2;

    int lm = min(l, r, 2 * x + 1, lx, m);
    int rm = min(l, r, 2 * x + 2, m, rx);

    return std::min(lm, rm);
  }

  int min(int l, int r) {
    return min(l, r, 0, 0, size);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  int m; cin >> m;

  m_segtree t;
  t.init(n);

  for (int i = 0; i != n; ++i) {
    int v; cin >> v;
    t.set(i, v);
  }

  for (int j = 0; j != m; ++j) {
    int c; cin >> c;
    if (c == 1) {
      int i, v; cin >> i >> v;
      t.set(i, v);
    } else {
      int l, r; cin >> l >> r;
      cout << t.min(l, r) << '\n';
    }
  }

  return 0;
}
