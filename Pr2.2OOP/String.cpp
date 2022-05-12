#include "String.h"
#include <iostream>
#include <string>

using namespace std;

String::String(const char* s)
{
	int size = strlen(s) + 1;
	str = new char[size];
	strcpy_s(str, size, s);
}

String::String(const String& s)
{
	*this = s;
}

String::String()
{
	str = nullptr;
}

String::~String()
{
	if (str != nullptr)
		delete[] str;
}

String& String::operator=(const String& s)
{
	if (&s == this) return *this;
	if (str != nullptr)
		delete[] str;

	int size = strlen(s.str) + 1;
	str = new char[size];
	strcpy_s(str, size, s.str);

	return *this;
}

String operator+ (const String& s1, const String& s2)
{
	string s3 = string(s1) + string(s2);
	return s3.c_str();
}

String operator- (const String& s1, const String& s2)
{
	string s = string(s1);
	size_t i = s.find(s2);
	if (i != string::npos)
		s.erase(i, string(s2).length());
	return s.c_str();
}


ostream& operator<< (ostream & os, const String& s)
{
	os << (string)s;
	return os;
}

istream& operator>> (istream & is, String& s)
{
	cout << "Enter string - ";
	string str;
    getline	(is, str);
	s = str.c_str();
	return is;
	
}