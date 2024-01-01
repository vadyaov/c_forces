#include <string>
#include <iostream>
#include <vector>

std::vector<int> ZFunc(const std::string& s) {
  const int sz = s.size();
  std::vector<int> z(sz, 0);

  for (int i = 1, l = 0, r = 0; i != sz; ++i) {
    if (r >= i) {
      if (z[i - l] < r - i + 1)
        z[i] = z[i - l];
      else {
        z[i] = r - i + 1;
        while (i + z[i] < sz && s[i + z[i]] == s[z[i]])
          z[i]++;
        }
    } else {
      while (i + z[i] < sz && s[i + z[i]] == s[z[i]])
        z[i]++;
    }

  if (z[i] > r - i + 1) {
    l = i;
    r = i + z[i] - 1;
  }

  }
  return z;
}

/*
 * Чтобы найти минимальный период строки, ищем такой индекс i: i + z[i] = |s|.
 * Если такой индекс сузествует, значит строка 0 - i-1 минимальный период.
 * Если важно чтобы длина k повторов периода строго совпадала с |s|, дополнительно
 * накладываем условие, что |s| % i == 0.
 */

int main() {
  
  int n;
  std::cin >> n;

  std::vector<std::string> res(n);

  for (int k = 0; k < n; ++k) {
    std::string s;
    std::cin >> s;

    std::vector<int> z = ZFunc(s);
    int i = 1, sz = s.size();
    for (; i < sz; ++i) {
      if (z[i] + i == sz) {
        res[k] = std::string(s.begin(), s.begin() + i);
        break;
      }
    }
    if (i == sz) res[k] = s;

  }

  for (const auto& str : res)
    std::cout << str << std::endl;

  return 0;
}
