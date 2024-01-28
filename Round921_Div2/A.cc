#include <string>
#include <iostream>

// A. Покрыть все!

/*

Вам дано два положительных целых числа n и k.

Ваша задача найти строку s такую, что все возможные строки длины n,
которые состоят из первых k прописных букв латинского алфавита,
присутствуют в s как подпоследовательность.

Если существует несколько ответов, выведите ответ минимальной длины.
Если таких ответов существует несколько — можно вывести любой.

Примечание: Строка a называется подпоследовательностью другой строки b,
если a может быть получена удалением нескольких (возможно нуля) символов из b
без изменения порядка оставшихся символов.

*/

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t; std::cin >> t;

  while (t--) {
    int n, k; std::cin >> n >> k;
    while (n--) {
      for (char i = 'a'; i != 'a' + k; ++i)
        std::cout << i;
    }
    std::cout << "\n";
  }

  return 0;
}

/*
 *
 * 1. The smallest length of such string is n * k. Why ?
 *
 * - To have the string aaa...a as a subsequence, you need to have at least
 *   'n' characters in the string as 'a'. Similary for all 'k' different characters.
 *   So, that gives you total length of at least n * k.
 *
 * 2. In fact, it is always possible to construct a string of length n * k
 *    that satisfies this property. One such string is
 *    (a1a2a3…ak)(a1a2a3…ak)(a1a2a3…ak)… n times where 'a' i is the ith letter
 *    of English alphabet. For example, the answer for n=3,k=4 can be abcdabcdabcd.
 *    It is not hard to see that the first letter of the subsequence can be from
 *    the first group of k letters, second letter from the second group and so on.
 *
 */
