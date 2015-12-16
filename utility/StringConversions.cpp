#include "StringConversions.h"

#include <string>
#include <sstream>
#include <stdio.h>

std::string todos_utility::IntToString(int value)
{
    std::ostringstream os;
    os << value;
    return os.str();
}

int todos_utility::StringToInt(const std::string &str)
{
  int i = 0;
  sscanf(str.c_str(), "%d", &i);

  return i;
}
