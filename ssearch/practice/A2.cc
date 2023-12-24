#include <string>
#include <vector>
#include <iostream>

/*
 *                    Z-функция (простая версия)
 * Напишите программу, которая выведет z-функцию заданной строки s.
 */

int main() {

  std::string s;
  std::cin >> s;

  const int sz = s.size();
  std::vector<int> z(sz, 0);

  for (int i = 1; i != sz; ++i) {
    while (i + z[i] < sz && s[z[i] + i] == s[z[i]])
      z[i]++;
  }

  for (int i : z)
    std::cout << i << " ";

  return 0;
}
