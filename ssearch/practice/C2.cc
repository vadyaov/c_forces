#include <string>
#include <vector>
#include <iostream>

// очень наивный вариант решения, который точно не пройдет кучу тестов
// принцип такой: смотрим на первое ненулевое значение z[i] и в зависимости от
// него конструируем z[i] элементов строки начиная с текущего (копируем префикс).
// наивно потому что тут пропускаются все значения z[i] от i до i + z[i] и ориентир
// идет только на значение z[i]. но может оказаться так что то значение кроторое стоит
// после текущего, не валидно. нужно как то это учесть. Самое простое решение которое 
// приходит в голову - сделать валидацию данной z-функции и z-функции, которую составим по готовой строке.
//
// проблема: это будет долго, так что должен быть более разумный и быстрый способ это сделать
// подумаю о нем завтра

int main() {

  /* const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', */
  /*                          'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', */
  /*                          'u', 'v', 'w', 'x', 'w', 'z'}; */

  // small letters 97-122 (26)
  // big letters 65-90 (26)

  int t;
  std::cin >> t;

  int sz[t];
  std::vector<std::vector<int>> z(t);

  for (int i = 0; i != t; ++i) {
    std::cin >> sz[i];
    z[i].resize(sz[i]);
    for (int j = 0; j != sz[i]; ++j)
      std::cin >> z[i][j];
  }

  for (int k = 0; k != t; ++k) {

    int small_begin = 97;
    /* int big_begin = 65; */
    std::string s(sz[k], small_begin);

    if (z[k][0] != 0) s = '!';

    else
    for (int i = 1; i != sz[k]; ++i) {
      if (z[k][i] > sz[k] - i) {
        s = '!'; break;
      } else if (z[k][i] == 0) {
        s[i] = ++small_begin;

        if (small_begin == 122) {
          small_begin = 65;
        } else if (small_begin == 90 && i < sz[k] - 1) {
          s = '!';
          break;
        }

      } else {
        for (int j = 0; j < z[k][i]; ++j) {
          s[i + j] = s[j];
        }
        i += z[k][i] - 1;
      }
    }

    std::cout << s << "\n";

  }

  return 0;
}
