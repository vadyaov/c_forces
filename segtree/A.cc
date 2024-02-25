#include <bits/stdc++.h>
using namespace std;

struct segtree {
  vector<long long> tree; // long long because sum can be greater maxint
  int size;               // size of array (not of tree)

  // procedure of creating segment tree for n-size array
  void init(int n) {
    size = 1;
    while (size < n) size *= 2;
    tree.assign(size * 2 - 1, 0);
  }

  void build(const vector<int>& a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < a.size()) tree[x] = a[lx];
    } else {
      int m = (lx + rx) / 2;
      build(a, 2 * x + 1, lx, m);
      build(a, 2 * x + 2, m, rx);
      tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }
  }

  void build(const vector<int>& a) {
    init(a.size());
    build(a, 0, 0, size);
  }

  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      tree[x] = v;
      return;
    }

    int m = (lx + rx) / 2;

    if (i < m)
      set(i, v, 2 * x + 1, lx, m);
    else
      set(i, v, 2 * x + 2, m, rx);

    tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
  }

  void set(int i, int v) {
    set(i, v, 0, 0, size);
  }

  long long sum(int l, int r, int x, int lx, int rx) {
    if (rx <= l || lx >= r) {
      return 0;
    }

    if (lx >= l && rx <= r) {
      return tree[x];
    }

    int m = (lx + rx) / 2;
    long long s1 = sum(l, r, 2 * x + 1, lx, m);
    long long s2 = sum(l, r, 2 * x + 2, m, rx);

    return s1 + s2;
  }

  long long sum(int l, int r) {
    return sum(l, r, 0, 0, size);
  }

  void print() {
    int spce = size;
    for (int k = 0, i = 0; k != size / 2; ++k) {
      for (int j = 0; j != 1 << k; ++j, ++i) {
        cout << setw(spce) << tree[i] << " ";
      }
      spce >>= 1;
      cout << '\n';
    }
  }
};

int main() {
  /* ios_base::sync_with_stdio(false); */
  /* cin.tie(nullptr); */

  int n; cin >> n;
  int m; cin >> m;

  vector<int> a(n);

  for (int i = 0; i != n; ++i) cin >> a[i];

  segtree t;
  t.build(a);

  for (int i = 0; i != m; ++i) {
    int choice; cin >> choice;
    int l, r; cin >> l >> r;

    if (choice == 2)
      cout << t.sum(l, r) << '\n';
    else
      t.set(l, r);
  }


  return 0;
}
