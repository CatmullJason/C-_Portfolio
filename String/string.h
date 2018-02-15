/***********************************************************************
* Program:
*    Unit 2, Safe String
*    Brother Helfrich, CS 470
* Author:
*    Jason Catmull
* Summary:
*    String Class in its implementation.
************************************************************************/
#include <iostream>
#include <cassert>

using namespace std;

const unsigned max_string_length = 10000;

/**************************************************
* STRING CLASS
* A class that holds strings of characters
***************************************************/
class String
{
public:
  // default constructor : empty and kinda useless
  String();

  // non-default constructors
  String(char c);
  String(const char* c);

  // copy constructor : copy it
  String(const String& s);

  // destructor : free everything
  ~String();

  //clear() clears the string of all items
  void clear() { numItems = 0; data = NULL; }

  /***************************
  * input/output/getline stream operator overloads
  ****************************/
  // ostream
  friend ostream& operator<< (ostream& os, const String& s);
  // istream
  friend istream& operator>> (istream& is, String& s);
  // getline
  friend istream& getline(istream& is, String& s);

  /***************************
  * assign and append overloads
  ****************************/
  // assign
  String operator= (const String& s);
  // append
  String operator+= (const String& s);
  // append
  String operator+= (const char* c);

  friend String operator+ (const String & lhs, const String & rhs);
  friend String operator+ (const String & lhs, const char* rhs);
  friend String operator+ (const char * lhs, const String & rhs);

  /***************************
  * comparison overloads
  ****************************/
  friend bool operator==(const String & lhs, const String & rhs);
  friend bool operator==(const String & lhs, const char* rhs);
  friend bool operator==(const char * lhs, const String & rhs);

  friend bool operator!=(const String & lhs, const String & rhs);
  friend bool operator!=(const String & lhs, const char* rhs);
  friend bool operator!=(const char * lhs, const String & rhs);

  friend bool operator> (const String & lhs, const String & rhs);
  friend bool operator> (const String & lhs, const char* rhs);
  friend bool operator> (const char * lhs, const String & rhs);

  friend bool operator< (const String & lhs, const String & rhs);
  friend bool operator< (const String & lhs, const char* rhs);
  friend bool operator< (const char * lhs, const String & rhs);


  friend bool operator>= (const String & lhs, const String & rhs);
  friend bool operator>= (const String & lhs, const char* rhs);
  friend bool operator>= (const char * lhs, const String & rhs);

  friend bool operator<= (const String & lhs, const String & rhs);
  friend bool operator<= (const String & lhs, const char* rhs);
  friend bool operator<= (const char * lhs, const String & rhs);

  /***************************
  * index operators
  ****************************/
  char  operator[] (unsigned index) const;
  char& operator[] (unsigned index);

  // return length of string
  unsigned length() const;
  

private:
  char * data;
  unsigned numItems;

  // safety check for string length
  void checkLength(unsigned numItems);
};


