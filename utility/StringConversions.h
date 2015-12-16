#ifndef UTILITY_STRING_CONVERSIONS_H
#define UTILITY_STRING_CONVERSIONS_H

#include <string>

namespace todos_utility {
  std::string IntToString(int value);
  int StringToInt(const std::string& str);
}

#endif //UTILITY_STRING_CONVERSIONS_H
