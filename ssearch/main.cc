#include "ssearch.h"

#include <iostream>

int main() {
  StringSearch ss;

  std::string source = "abacababa";
  auto occurences = StringSearch::SimpleSubStr(source, "aba");
  std::cout << occurences.size() << " occurences:\n";
  for (const auto& pair : occurences)
    std::cout << pair.first << ' ' << pair.second << "\n";

  for (int i : ss.TestZ("abacaba"))
    std::cout << i << " ";

  return 0;
}
