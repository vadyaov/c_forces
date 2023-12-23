#pragma once

#include <string>
#include <vector>

class StringSearch {
  public:
    typedef std::pair<int, int> ipair;

    /* наивный алгоритм, время работы O(nm) */
    /* n = s.size(), m = p.size() */
    /* std::string.find() работает примерно за такое же время */
    std::vector<ipair> SimpleSubStr(const std::string& s, const std::string& p) const noexcept;

    std::vector<ipair> ZSubStr(const std::string& s, const std::string& p) const noexcept;

    // find Z-function of string for O(n^2)
    std::vector<int> ZFunc2(const std::string& str) const noexcept;

    // find Z-function of string for O(n)
    std::vector<int> ZFunc1(const std::string& str) const noexcept;

};
