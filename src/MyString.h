#pragma once
#include <ostream>

class MyString
{
public:
   MyString();
   MyString(const char* s);
   MyString(const MyString& other);
   MyString(MyString&& other) noexcept;
   ~MyString();

   MyString& operator=(const char* s);
   MyString& operator=(const MyString& other);
   MyString& operator=(MyString&& other) noexcept;

   MyString& operator+=(const char* s);
   MyString& operator+=(const MyString& other);

   MyString operator+(const char* s);
   MyString operator+(const MyString& other);
   friend MyString operator+(const char* s, const MyString& other);

   bool operator==(const MyString& other) const;
   bool operator!=(const MyString& other) const;
   bool operator< (const MyString& other) const;
   bool operator<=(const MyString& other) const;
   bool operator> (const MyString& other) const;
   bool operator>=(const MyString& other) const;

   friend std::ostream& operator<<(std::ostream& os, const MyString& itself);

   size_t size() const { return m_size; }
   size_t length() const { return m_size; }
   bool is_greater_insensitive(const MyString& other) const;

private:
   size_t m_size = 0;
   char* m_begin;


   void copy(const char* s);
   void add(const char* s);
};