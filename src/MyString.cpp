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
   copy(other);
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
   copy(other);
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
   return *this;
}

MyString& MyString::operator+=(const MyString other)
{
   return *this;
}

MyString& MyString::operator+(const MyString other)
{
   return *this;
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
   size_t i = 0;
   for (; i < m_size; i++) m_begin[i] = s[i];
   m_begin[i] = 0;
}

void MyString::copy(const MyString& other)
{
   copy(other.m_begin);
}