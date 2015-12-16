#ifndef UTILITY_STRING_CONVERSIONS_H
#define UTILITY_STRING_CONVERSIONS_H

#include <string>
#include <sstream>

namespace std {
  template <typename T>
  std::string to_string(T value)
  {
      std::ostringstream os;
      os << value;
      return os.str();
  }

  int stoi(const std::string& str);
}

#endif //UTILITY_STRING_CONVERSIONS_H
