#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;
typedef char* Iterator;
class String {
	size_t m_capacity;
	char* m_data;
	size_t m_size;
public:
	String();
	String(const String&);
	String(const char*);
	String(size_t, char);
	String(const String&, size_t);
	String& operator=(const String&);
	String& operator=(const char*);
	~String();
	Iterator begin()const;
	Iterator end()const;
	size_t size() const;
	size_t length() const;
	size_t capacity() const;
	bool empty() const;
	void clear();
	void resize(size_t n, const char c = ' ');
	void reserve(size_t res_arg);

	char& operator[] (size_t pos) const;
	char& operator[] (size_t pos);

	void push_back(const char c);
	void pop_back(const char c);
	String& append(const char* s);
	String& append(const char c, size_t n = 1);
	String& append(const String& s);
	const char* c_str()const;
	size_t find(const char c, size_t pos = 0)const;
	size_t find(const char* c, size_t pos = 0)const;
	size_t find(const String& t, size_t pos = 0)const;
	size_t rfind(const char c, size_t pos = 0)const;
	size_t rfind(const char* s, size_t pos = 0)const;
	size_t rfind(const String& t, size_t pos = 0)const;
	String substr(size_t pos = 0, size_t n = 0)const;
	String& operator+=(const char c);
	String& operator+=(const String& s);
	String& operator+=(const char* s);
	friend String operator+(const char* s, const String& t);
	String operator+(const char* s)const;
	String operator+(const String& t)const;

	bool operator<(const String& t)const;
	bool operator>(const String& t)const;
	bool operator<=(const String& t)const;
	bool operator>=(const String& t)const;
	bool operator==(const String& t)const;
	bool operator!=(const String& t)const;

	bool operator<(const char* s)const;
	bool operator>(const char* s)const;
	bool operator<=(const char* s)const;
	bool operator>=(const char* s)const;
	bool operator==(const char* s)const;
	bool operator!=(const char* s)const;

	friend bool operator<(const char* t1, const String& t2);
	friend bool operator>(const char* t1, const String& t2);
	friend bool operator<=(const char* t1, const String& t2);
	friend bool operator>=(const char* t1, const String& t2);
	friend bool operator==(const char* t1, const String& t2);
	friend bool operator!=(const char* t1, const String& t2);
	friend istream& operator>>(istream& is, String& t);
	friend ostream& operator<<(ostream& os, const String& t);
	friend istream& getline(istream&  is, String& str, char n);
	friend istream& getline(istream&  is, String& str);
};

