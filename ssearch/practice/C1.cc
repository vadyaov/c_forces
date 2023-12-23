#include <iostream>
#include <string>
#include <vector>

/*
 *               ПОИСК ПОДСТРОКИ В СТРОКЕ С ДЖОКЕРАМИ В ОБРАЗЦЕ
 * Задан текст t и образец p.
 * Текст состоит из строчных букв латинского алфавита.
 * Образец состоит из строчных букв латинского алфавита и может содержать 0 или
 * более специальных символов '?' (джокеров). Джокер это такой спецсимвол образца,
 * который можно считать равным любому символу текста.
 *
 * Выведите все вхождения образца в текст. Найдите все такие индексы текста i,
 * что начиная с индекса i текста есть вхождение образца.
 *
 * ВХОДНЫЕ ДАННЫЕ
 * В первой строке входных данных записано целое число q (1≤q≤100) — количество
 * наборов входных данных в тесте. Каждый набор входных данных состоит из двух
 * строк t и p. Длина строки t от 1 до 50000 символов, длина строки p от 1 до 100
 * символов. Строки t и p состоят исключительно из строчных букв латинского алфавита,
 * кроме того образец p может содержать джокеры '?'.
 * Сумма длин строк t по всем q наборам входных данных в тесте не превосходит 50000.
 * Аналогично, сумма длин строк p по всем q наборам входных данных в тесте не превосходит 100.
 *
 * ВЫХОДНЫЕ ДАННЫЕ
 * Для каждого из q наборов входных данных выведите ответ в виде двух строк.
 * В первую строку выведите количество вхождений, во вторую — индексы стартов
 * вхождений в возрастающем порядке. Обратите внимание, что следует использовать
 * 0-индексацию.
 *
 */

int main() {

  int q;
  std::cin >> q;

  std::vector<int> occurences[q];
  for (int t = 0; t != q; ++t) {

    std::string s;
    std::string p;

    std::cin >> s >> p;

    for (int i = 0, sz_s = s.size(), sz_p = p.size();
         !(sz_s < sz_p) && i != sz_s - sz_p + 1; ++i) {
      bool match = true;
      for (int k = 0; match && k != sz_p; ++k) {
        if (!(s[i + k] == p[k] || p[k] == '?'))
          match = false;
      }
      if (match == true)
        occurences[t].push_back(i);
    }
  }

  for (int i = 0; i != q; ++i) {
    std::cout << occurences[i].size() << "\n";
    for (int j : occurences[i])
      std::cout << j << " ";
    std::cout << "\n";
  }

  return 0;
}
