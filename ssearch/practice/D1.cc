#include <string>
#include <vector>
#include <iostream>

/*
 *                       КОЛИЧЕСТВО ХОРОШИХ ПОДСТРОК
 * Вам заданы две строки s и t.
 * Назовём подстроку строки s[i…j] хорошей, если она не содержит в качестве
 * подстроки строку t. Одинаковые по содержимому, но разные по позициям подстроки
 * следует учитывать столько раз, сколько они встречаются в строке s.
 * Иными словами, вам надо найти количество таких пар индексов (i,j) (i≤j),
 * что подстрока s[i…j] не содержит вхождение t.
 *
 * ВХОДНЫЕ ДАННЫЕ
 * В первой строке входных данных записано целое число q (1≤q≤100) — количество
 * наборов входных данных в тесте. Каждый набор входных данных состоит из двух
 * строк s и t. Длина строки s от 1 до 50000 символов, длина строки t от
 * 1 до 100 символов. Строки s и t состоят исключительно из строчных букв латинского алфавита.
 * Сумма длин строк по всем s наборам входных данных в тесте не превосходит 50000.
 * Аналогично, сумма длин строк по всем t наборам входных данных в тесте не превосходит 100.
 *
 * ВЫХОДНЫЕ ДАННЫЕ
 * Выведите q целых чисел — для каждой строки выведите искомое количество подстрок.
 */

int Sum(int n) {
  if (n < 1) return 0;
  return n + Sum(n - 1);
}

int main() {

  int n;
  std::cin >> n;

  std::string s[n];
  std::string t[n];

  for (int i = 0; i != n; ++i)
    std::cin >> s[i] >> t[i];

  std::vector<int> r(n);

  for (int q = 0; q != n; ++q) {

    std::vector<int> occurences;

    for (int i = 0, sz_s = s[q].size(), sz_p = t[q].size();
         !(sz_s < sz_p) && i != sz_s - sz_p + 1; ++i) {
      bool match = true;
      for (int k = 0; match && k != sz_p; ++k) {
        if (!(s[q][i + k] == t[q][k]))
          match = false;
      }
      if (match == true)
        occurences.push_back(i);
    }

    int j = 0;
    for (std::size_t i = 0; i != occurences.size(); ++i) {
      r[q] += Sum(occurences[i] + t[q].size() - 1 - j) - Sum(t[q].size() - 2);
      j = occurences[i] + 1;
    }

    r[q] += Sum(s[q].size() - j);

  }

  for (int rr : r)
    std::cout << rr << "\n";

  return 0;
}