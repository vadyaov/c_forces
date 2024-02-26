#include <bits/stdc++.h>
using namespace std;

class mc_segtree {

  public:
    struct node {
      int min;
      int count;
    };

    mc_segtree(int n) : size{1} {
      while (size < n) size *= 2;
      tree.assign(2 * size - 1, {INT_MAX, 0});
    }

    mc_segtree(const vector<int>& a) : mc_segtree(a.size()) {
      build(a);
    }

    void build(const vector<int>& a) { build(a, 0, 0, size); }

    void set(int i, int v) { set(i, v, 0, 0, size); }

    node calc(int l, int r) { return calc(l, r, 0, 0, size); }

  private:
    vector<node> tree;
    int size;

    node combine(const node& lhs, const node& rhs) {
      if (lhs.min < rhs.min) return lhs;
      if (lhs.min > rhs.min) return rhs;

      return {lhs.min, lhs.count + rhs.count};
    }

    void build(const vector<int>& a, int x, int lx, int rx) {
      if (rx - lx == 1) {
        if (lx < a.size())
          tree[x] = {a[lx], 1};
      } else {
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);

        tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
      }
    }

    void set(int i, int v, int x, int lx, int rx) {
      if (rx - lx == 1) {
        tree[x] = {v, 1};
        return;
      }

      int m = (lx + rx) / 2;
      if (i < m)
        set(i, v, 2 * x + 1, lx, m);
      else
        set(i, v, 2 * x + 2, m, rx);

      tree[x] = combine(tree[2 * x + 1], tree[2 * x + 2]);
    }

    node calc(int l, int r, int x, int lx, int rx) {
      if (lx >= r || rx <= l) {
        return {INT_MAX, 0};
      }

      if (lx >= l && rx <= r) {
        return tree[x];
      }

      int m = (lx + rx) / 2;

      node mc1 = calc(l, r, 2 * x + 1, lx, m);
      node mc2 = calc(l, r, 2 * x + 2, m, rx);

      return combine(mc1, mc2);
    }

};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  int m; cin >> m;

  vector<int> a(n);

  for (int i = 0; i != n; ++i) {
    cin >> a[i];
  }

  mc_segtree t(a);

  for (int j = 0; j != m; ++j) {
    int c; cin >> c;
    if (c == 1) {
      int i, v; cin >> i >> v;
      t.set(i, v);
    } else {
      int l, r; cin >> l >> r;
      auto res = t.calc(l, r);
      cout << res.min << ' ' << res.count << '\n';
    }
  }

  return 0;
}
