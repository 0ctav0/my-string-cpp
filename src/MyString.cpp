#include "MyString.h"

MyString::MyString()
{
   copy("");
}

MyString::MyString(const char* s)
{
   copy(s);
}

MyString::MyString(const MyString& other)
{
   copy(other.m_begin);
}

MyString::MyString(MyString&& other) noexcept
{
   m_size = other.m_size;
   m_begin = other.m_begin;
   other.m_size = 0;
   other.m_begin = nullptr;
}

MyString::~MyString()
{
   delete[] m_begin;
}

MyString& MyString::operator=(const char* s)
{
   delete[] m_begin;
   copy(s);
   return *this;
}

MyString& MyString::operator=(const MyString& other)
{
   delete[] m_begin;
   copy(other.m_begin);
   return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept
{
   if (this != &other)
   {
      delete[] m_begin;
      m_size = other.m_size;
      m_begin = other.m_begin;
      other.m_size = 0;
      other.m_begin = nullptr;
   }
   return *this;
}

MyString& MyString::operator+=(const char* s)
{
   add(s);
   return *this;
}

MyString& MyString::operator+=(const MyString& other)
{
   add(other.m_begin);
   return *this;
}

MyString MyString::operator+(const char* s)
{
   MyString result{ m_begin };
   result.add(s);
   return result;
}

MyString MyString::operator+(const MyString& other)
{
   MyString result{ m_begin };
   result.add(other.m_begin);
   return result;
}

MyString operator+(const char* s, const MyString& other)
{
   MyString result{ s };
   result.add(other.m_begin);
   return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& itself)
{
   os << itself.m_begin;
   return os;
}

void MyString::copy(const char* s)
{
   m_size = strlen(s);
   m_begin = new char[m_size + 1];
   memcpy(m_begin, s, m_size + 1);
}

void MyString::add(const char* s)
{
   auto old_size = m_size;
   auto other_size = strlen(s);
   m_size += other_size;
   auto temp = new char[m_size + 1];
   memcpy(temp, m_begin, old_size);
   memcpy(&temp[old_size], s, other_size + 1);
   delete[] m_begin;
   m_begin = temp;
}