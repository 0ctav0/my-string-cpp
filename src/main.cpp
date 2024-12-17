#include <iostream>
#include <vector>
#include <algorithm>
#include "MyString.h"

int main(int argc, char** argv)
{
   std::vector<MyString> strings;
   for (int i = 1; i < argc; i++) strings.push_back(argv[i]);
   std::sort(strings.begin(), strings.end(),
      [](const MyString& a, const MyString& b) {return a.is_greater_insensitive(b); });
   for (const auto& s : strings) std::cout << s << std::endl;
}
