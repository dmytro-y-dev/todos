#ifndef UTILITY_STRING_CONVERSIONS_H
#define UTILITY_STRING_CONVERSIONS_H

#include <string>
#include <QDateTime>

namespace todos_utility {
  std::string IntToString(int value);
  int StringToInt(const std::string& str);

  QDateTime StringToQDateTime(const std::string& str);
  std::string QDateTimeToString(const QDateTime& date);
}

#endif //UTILITY_STRING_CONVERSIONS_H
