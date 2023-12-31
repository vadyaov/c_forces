#include <string>
#include <vector>
#include <iostream>

const std::string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {

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

    /*
    int alphabet = 'a';
    std::string s(sz[k], alphabet);

    for (int i = 1; i != sz[k];) {
      if (z[k][i - 1] > 1) i--;
      if (z[k][i] > sz[k] - i) break;

      if (z[k][i] == 0) {
          s[i++] = ++alphabet;
          if (alphabet == 'z')
            alphabet = 'z' - 1;
      } else {
        for (int j = 0; j < z[k][i]; ++j) {
          s[i + j] = s[j];
        }
        i += z[k][i];
      }
    }
    */

    std::string s;
    int prefixLength = 0;
    int j;
    int newCharacter = 0;

    for (int i = 0; i != sz[k]; ++i) {
      if (z[k][i] == 0 && prefixLength == 0) {
        if (newCharacter < alphabet.size()) {
            s += alphabet[newCharacter++];
        } else {
          s += alphabet[newCharacter - 1];
        }
      }

      if (z[k][i] > prefixLength) {
        prefixLength = z[k][i];
        j = 0;
      }

      if (prefixLength > 0) {
        s += s[j++];
        prefixLength--;
      }
    }

    std::vector<int> valid_z(sz[k], 0);
    for (int i = 1; i != sz[k]; ++i) {
      while (i + valid_z[i] < sz[k] && s[i + valid_z[i]] == s[valid_z[i]])
        valid_z[i]++;
    }

    if (z[k] != valid_z) s = '!';

    std::cout << s << "\n";

  }

  return 0;
}
