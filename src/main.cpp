#include <iostream>
#include "MyString.h"

int main()
{
   while (true)
   {
      MyString str;
      MyString str2 = "world";
      MyString res = std::move(str2);
      std::cout << res << " " << res.size() << std::endl;
   }
}
