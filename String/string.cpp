#include "string.h"

String::String()
{
  numItems = 0;
  data = new char[0];
}

String::String(char c)
{
  numItems = 1;
  data = new char(c);
}

String::String(const char * c)
{
  if (c)
  {
    unsigned length = 0;
    while (c[length] != '\0')
    {
      length++;
      checkLength(length);  //safety check
    }
    numItems = length;
    data = new char[length];
    for (int i = 0; i < length; i++)
    {
      data[i] = c[i];
    }
  }
  else
  {
    numItems = 0;
    data = new char[0];
  }
}

String::String(const String& s)
{
  checkLength(s.length());  //safety check
  numItems = s.length();
  data = new char[numItems];
  for (int i = 0; i < numItems; i++)
  {
    data[i] = s[i];
  }
}

String::~String()
{
  if (data)
  {
    delete[] data;
  }
}

istream & getline(istream & is, String & s)
{
  char c;
  int counter = 0;
  String temp = String();
  while (is.get(c) && (c != '\n'))
  {
    temp += c;
    counter++;
    assert(counter < max_string_length); //safety check
  }
  s = String(temp);

  return is;
}

String String::operator=(const String & s)
{
  if (this == &s)
  {
    return *this;
  }

  delete data;
  checkLength(s.length());  //safety check
  numItems = s.length();
  data = new char[numItems];
  for (int i = 0; i < numItems; i++)
  {
    data[i] = s[i];
  }
    
  return *this;
}

String String::operator+=(const String & s)
{
  checkLength(s.length());
  int totalLength = numItems + s.length();
  char* tempStr = new char[totalLength];

  for (int i = 0; i < numItems; i++)
  {
    tempStr[i] = data[i];
  }
    
  for (int i = 0; i < s.length(); i++)
  {
    tempStr[numItems + i] = s[i];
  }
    
  delete data;
  numItems = totalLength;
  data = tempStr;
  return *this;
}

String String::operator+=(const char * c)
{
  String cString = String(c);
  int totalLength = numItems + cString.length();
  checkLength(totalLength);    //safety check
  char* tempStr = new char[totalLength];

  for (int i = 0; i < numItems; i++)
  {
    tempStr[i] = data[i];
  }

  for (int i = 0; i < cString.length(); i++)
  {
    tempStr[numItems + i] = cString[i];
  }

  delete data;
  numItems = totalLength;
  data = tempStr;
  return *this;
}

char String::operator[](unsigned index) const
{
  if (index >= numItems)
  {
    throw 1;
  }
  return data[index];
}

char & String::operator[](unsigned index)
{
  if (index >= numItems)
  {
    throw 1;
  }
  return data[index];
}

unsigned String::length() const
{
  return numItems;
}

void String::checkLength(unsigned number)
{
  assert (number < max_string_length);
}

ostream & operator<<(ostream & os, const String & s)
{
  if (s.length() > 0)
  {
    for (int i = 0; i < s.length(); i++)
    {
      os << s[i];
    }   
  }
  else
  {
    os << "";
  }

  return os;
}

istream & operator >> (istream & is, String & s)
{
  char c;
  int counter = 0;
  String temp = String();
  while (is.get(c) && (c != '\n'))
  {
    temp += c;
    counter++;
    assert (counter < max_string_length);
  }  
  s = String(temp);

  return is;
}

String operator+(const String & lhs, const String & rhs)
{
  return String(lhs) += rhs;
}

String operator+(const String & lhs, const char * rhs)
{
  return String(lhs) += String(rhs);
}

String operator+(const char * lhs, const String & rhs)
{
  return String(lhs) += rhs;
}

bool operator==(const String & lhs, const String & rhs)
{
  if (lhs.length() != rhs.length())
  {
    return false;
  }
  bool test = true;

  for (int i = 0; i < lhs.length(); i++)
  {
    if (lhs[i] == rhs[i])
    {
      test = true;
    }
    else 
    {
      return test = false;
    }
  }
  return test;
}

bool operator==(const String & lhs, const char * rhs)
{
  return (lhs == String(rhs));
}

bool operator==(const char * lhs, const String & rhs)
{
  return (String(lhs) == rhs);
}

bool operator!=(const String & lhs, const String & rhs)
{
  return !(lhs == rhs);
}

bool operator!=(const String & lhs, const char * rhs)
{
  return !(lhs == rhs);
}

bool operator!=(const char * lhs, const String & rhs)
{
  return !(lhs == rhs);
}

bool operator>(const String & lhs, const String & rhs)
{
  unsigned longest;
  unsigned index = 0;
  if (lhs.length() < rhs.length())
  {
    longest = lhs.length();
  }
  else
  {
    longest = rhs.length();
  }
  
  while ((index < longest) && (lhs[index] == rhs[index]))
  {
    index++;
  }
  if (index == longest)
  {
    return (lhs.length() > rhs.length());
  }

  
  return lhs[index] > rhs[index];
}

bool operator>(const String & lhs, const char * rhs)
{
  return (lhs > String(rhs));
}

bool operator>(const char * lhs, const String & rhs)
{
  return (String(lhs) > rhs);
}

bool operator<(const String & lhs, const String & rhs)
{
  return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<(const String & lhs, const char * rhs)
{
  return !(lhs == rhs) && !(lhs > rhs);
}

bool operator<(const char * lhs, const String & rhs)
{
  return !(lhs == rhs) && !(lhs > rhs);
}

bool operator>=(const String & lhs, const String & rhs)
{
  return (lhs == rhs) || (lhs > rhs);
}

bool operator>=(const String & lhs, const char * rhs)
{
  return (lhs == rhs) || (lhs > rhs);
}

bool operator>=(const char * lhs, const String & rhs)
{
  return (lhs == rhs) || (lhs > rhs);
}

bool operator<=(const String & lhs, const String & rhs)
{
  return !(lhs > rhs);
}

bool operator<=(const String & lhs, const char * rhs)
{
  return !(lhs > rhs);
}

bool operator<=(const char * lhs, const String & rhs)
{
  return !(lhs > rhs);
}
