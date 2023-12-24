#include <iostream>
#include <string>

/*
 *                    НАИДЛИННЕЙШИЙ ПАЛИНДРОМНЫЙ ПРЕФИКС
 * Задана строка s.
 * Найдите длину её наиболее длинного префикса, который является палиндромом.
 */

int main() {
  int sz;
  std::cin >> sz;
  std::string str[sz];
  for (int i = 0; i < sz; ++i)
    std::cin >> str[i];

  for (const std::string& s : str) {
    int i = s.size() - 1;
    while (i) {
      int j = i, k = 0;
      while (j >= k && s[j] == s[k]) {
        j--;
        k++;
      }
      if (j < k) break;
      i--;
    }
    std::cout << i + 1 << "\n";
  }

  return 0;
}
