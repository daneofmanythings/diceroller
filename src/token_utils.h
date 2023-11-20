#ifndef _TOKEN_UTILS_H_
#define _TOKEN_UTILS_H_

#include <algorithm>
#include <array>
#include <cctype>
#include <iostream>

namespace util {

template <size_t N> bool find(const std::array<char, N> arr, const char c) {
  return std::find(arr.begin(), arr.end(), c) != arr.end();
}

inline bool isdigit(const char &c) {
  return static_cast<bool>(std::isdigit(static_cast<unsigned char>(c)));
}

inline bool isalpha(const char &c) {
  return static_cast<bool>(std::isalpha(static_cast<unsigned char>(c)));
}

inline bool ispunct(const char &c) {
  return static_cast<bool>(std::ispunct(static_cast<unsigned char>(c)));
}

inline bool iswhitespace(const char &c) {
  return static_cast<bool>(std::isspace(static_cast<unsigned char>(c)));
}

} // namespace util

#endif // !_TOKEN_UTILS_H_
