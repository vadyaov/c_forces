#include <iostream>
#include <string>

/*
 *                    ПРЕФИКСНЫЕ И СУФФИКСНЫЕ ПОДСТРОКИ
 * Задана строка s.
 * Найдите количество таких её подстрок s[i…j], которые равны префиксу строки s,
 * либо равны суффиксу строки s. Если подстрока s[i…j] равна одновременно и
 * префиксу и суффиксу, то учитывать её не надо. Одинаковые по содержимому, но
 * разные по позициям подстроки следует учитывать столько раз, сколько они
 * встречаются в строке s.
 * Иными словами, вам надо найти количество таких пар индексов (i,j) (i≤j), что
 * подстрока s[i…j] совпадает либо c префиксом s, либо с суффиксом s.
 */

bool EqualPrefix(const std::string& s, int i, int j) {
  for (int k = 0; k <= j; ++k, ++i) {
    if (s[k] != s[i]) return false;
  }

  return true;
}

bool EqualSuffix(const std::string& s, int i, int j) {
  for (int k = 0; k <= j; ++k, ++i) {
    if (s[s.size() - j + k - 1] != s[i])
      return false;
  }

  return true;
}

int main() {
  int t;
  std::cin >> t;
  int result[t];

  for (int k = 0; k < t; ++k) {
    std::string s;
    std::cin >> s;

    int sz = s.size();
    int n = 0;
    for (int i = 0; i != sz; ++i) {
      for (int j = 0; i + j != sz; ++j) {
        bool eq_pref = EqualPrefix(s, i, j);
        bool eq_suff = EqualSuffix(s, i, j);

        if ((eq_pref || eq_suff) && !(eq_pref && eq_suff))
          n++;
      }
    }
    result[k] = n;
  }

  for (int r : result)
    std::cout << r << "\n";

  return 0;
}
