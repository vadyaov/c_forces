#pragma once

#include <string>
#include <vector>

class StringSearch {
  public:
    typedef std::pair<int, int> ipair;

    /* наивный алгоритм, время работы O(nm) */
    /* n = s.size(), m = p.size() */
    /* std::string.find() работает примерно за такое же время */
    static std::vector<ipair> SimpleSubStr(const std::string& s, const std::string& p);

    static std::vector<ipair> ZSubStr(const std::string& s, const std::string& p);

    // find Z-function of string for O(n^2)
    static std::vector<int> ZFunc2(const std::string& str);

    // find Z-function of string for O(n)
    static std::vector<int> ZFunc1(const std::string& str);

    static bool IsCyclicShift(const std::string& s, const std::string& t);

    static std::string LongestEdge(const std::string& s);
};
