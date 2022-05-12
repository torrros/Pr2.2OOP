#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class String
{
	char* str;
public:
	String();
	String(const char* s);
	String(const String& s);
	~String();

	const char* getstr() const { return str; }
	void setstr( char* s) { str = s;}
	
	friend String operator+(const String&s1, const String&s2);
	friend String operator-(const String& s1, const String& s2);

	operator string() const { return str; }
	String& operator=(const String& s);
	friend ostream& operator<<(ostream& out, const String& s);
	friend istream& operator>>(istream& in, String& s);
	
};

