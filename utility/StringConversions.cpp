#include "StringConversions.h"

#include <stdio.h>

int std::stoi(const std::string &str)
{
  int i = 0;
  sscanf(str.c_str(), "%d", &i);

  return i;
}
