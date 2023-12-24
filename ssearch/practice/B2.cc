#include <string>
#include <cmath>
#include <iostream>

/*
 *                    Z-функция строки Грея
 *
 * Последовательность строк Грея g1,g2,… выглядит следующим образом:
 *
 * g1=«a»
 * g2=«aba»
 * g3=«abacaba»
 * g4=«abacabadabacaba»
 * ...
 * gi=gi−1+ci+gi−1, где ci — это i-й символ алфавита
 * ... 
 *
 * Заметим, что длины строки Грея очень быстро растут (длина i-й строки равна 2i−1),
 * но они имеют регулярную фрактальную структуру.
 * Часто на строках Грея удобно разбирать работу различных строковых алгоритмов.
 *
 * В этой задаче вам надо по заданному индексу k строки Грея и по числу j
 * вывести z[j] — значение z-функции строки g[k] в индексе j.
 */

int FindGrayZFunc(int k, int j) {
  int sz = std::pow(2, k) - 1;
  int mid = sz / 2;

  if (k == 1) return 0;

  if (j > mid) {
    int delta = j == mid + 1 ? std::pow(2, k - 1) - 1 : 0;
    return delta + FindGrayZFunc(k - 1, j - mid - 1);
  } else if (j < mid)
    return FindGrayZFunc(k - 1, j);
  else
    return 0;
}

int main() {

  int n;
  std::cin >> n;

  int k[n];
  int j[n];

  for (int i = 0; i != n; ++i)
    std::cin >> k[i] >> j[i];

  for (int i = 0; i != n; ++i)
    std::cout << FindGrayZFunc(k[i], j[i]) << "\n";

  return 0;
}
