#include <iostream>
#include "MyString.h"

int main()
{
   while (true)
   {
      MyString str;
      MyString str2 = "hello";
      MyString res = std::move(str2);
      //res += " 2" + MyString{ " divine" } + MyString{ " new" } + " world";
      res = MyString{} + "hey" + " atom";
      std::cout << res << " " << res.size() << std::endl;
   }
}
