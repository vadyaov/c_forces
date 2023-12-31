#include "ssearch.h"
#include <iostream>

std::vector<StringSearch::ipair>
StringSearch::SimpleSubStr(const std::string& s, const std::string& p) {
  if (s.empty() || p.empty() || p.size() > s.size())
    return std::vector<StringSearch::ipair>();

  std::vector<StringSearch::ipair> substr_pos;

  const int sz_s = s.size();
  const int sz_p = p.size();

  for (int i = 0; i != sz_s - sz_p + 1; ++i) {
    bool mismatch = false;
    for (int k = 0; k != sz_p; ++k) {
      if (s[i + k] != p[k]) {
        mismatch = true;
        break;
      }
    }
    if (mismatch == false) {
      substr_pos.push_back(std::make_pair(i, i + sz_p - 1));
    }
  }

  return substr_pos;
}

std::vector<int> StringSearch::ZFunc2(const std::string& str) {
  std::vector<int> z(str.size(), 0);

  // z[0] = 0 по определению
  for (std::size_t i = 1; i != str.size(); ++i)
    while (z[i] + i < str.size() && str[z[i] + i] == str[z[i]])
      ++z[i];

  return z;
}

std::vector<int> StringSearch::ZFunc1(const std::string& str) {
  const int n = str.size();

  std::vector<int> z(n, 0);
  int l = 0, r = 0;

  for (int i = 1; i != n; ++i) {
    /* // можем ли использовать [l; r] диапазон ? */
    /* if (r >= i) { */
    /*   if (z[i - l] < r - i + 1) { */
    /*     z[i] = z[i - l]; */
    /*   } else { */
    /*     z[i] = r - i + 1; */
    /*     while (z[i] + i < n && str[z[i] + i] == str[z[i]]) */
    /*       z[i]++; */
    /*   } */
    /*   // если нет, то считаем по наивному алгоритму */
    /* } else { */
    /*   while (z[i] + i < n && str[z[i] + i] == str[z[i]]) */
    /*     z[i]++; */
    /* } */

    if (r >= i)
      z[i] = std::min(z[i - l], r - i + 1);

    while (z[i] + i < n && str[z[i] + i] == str[z[i]])
      z[i]++;

    if (r < z[i] + i - 1) {
      l = i;
      r = z[i] + i - 1;
    }
  }

  return z;
}

std::vector<StringSearch::ipair>
StringSearch::ZSubStr(const std::string& s, const std::string& p) {
  if (s.empty() || p.empty() || p.size() > s.size())
    return std::vector<StringSearch::ipair>();

  std::vector<StringSearch::ipair> substr_pos;

  std::vector<int> z = ZFunc1(p + '#' + s);

  for (std::size_t i = p.size() + 1; i != z.size(); ++i)
    if ((size_t)z[i] == p.size()) {
      substr_pos.push_back(std::make_pair(i - (p.size() + 1), i - 2));
    }

  return substr_pos;
}

/* std::string MakeCyclicShifts(const std::string& str) { */
/*   std::string s; */

/*   for (int i = 0; i < str.size(); ++i) { */
/*     for (int j = i; j < str.size(); ++j) */
/*       s += str[j]; */
/*     for (int k = 0; k < i; ++k) */
/*       s += str[k]; */
/*   } */

/*   return s; */
/* } */

bool StringSearch::IsCyclicShift(const std::string& s, const std::string& t) {
  std::string base = t + '$' + s + s;
  std::vector<int> z = ZFunc1(base);

  for (int n : z)
    if (n == t.size())
      return true;

  return false;
}

std::string StringSearch::LongestEdge(const std::string& s) {
  std::vector<int> z = ZFunc1(s);
  for (int j = 1; j < s.size(); ++j) {
    if (z[j] == s.size() - j) {
      return std::string(s.begin(), s.begin()  + s.size() - j);
    }
  }

  return "";
}
