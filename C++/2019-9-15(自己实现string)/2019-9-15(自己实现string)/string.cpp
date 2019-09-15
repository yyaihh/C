#include "string.h"
Iterator String::begin()const {
	return m_data;
}
Iterator String::end() const{
	return m_data + m_size;
}
String::String() :m_size(0),
				m_capacity(15),
				m_data(new char[m_capacity]) 
{
	memset(m_data, 0, m_capacity);
}
String::String(const String& t) {
	if (this == &t) {
		return;
	}
	m_size = t.m_size;
	m_capacity = 15;
	reserve(t.m_capacity);
	m_capacity = t.m_capacity;
	strcpy(m_data, t.m_data);
}
String::String(const char* t) {
	m_capacity = 15;
	m_data = new char[m_capacity];
	m_size = 0;
	size_t size = strlen(t);
	reserve(size);
	m_size = size;
	strcpy(m_data, t);
}
String::String(size_t n, char c) {
	m_capacity = 15;
	m_data = new char[m_capacity];
	m_size = 0;
	reserve(n);
	m_size = n;
	memset(m_data, c, n);
}
String::String(const String& t, size_t n) {
	m_capacity = 15;
	m_data = new char[m_capacity];
	m_size = 0;
	reserve(n);
	m_size = n;
	strncpy(m_data, t.m_data, n);
}
	 
String::~String() {	
	if (m_data) {
		delete[]m_data;
	}
	m_data = nullptr;
	m_size = 0;
	m_capacity = 0;
}
String& String::operator=(const String& t) {
	if (this == &t) {
		return *this;
	}
	reserve(t.m_capacity);
	strcpy(m_data, t.m_data);
	m_size = t.m_size;
	return *this;
}
String& String::operator=(const char* s) {
	if (!strcmp(m_data, s)) {
		return *this;
	}
	size_t size = strlen(s) + m_size;
	reserve(size);
	m_size = size;
	strcpy(m_data, s);
	return *this;
}
size_t String::size() const {
	return m_size;
}
size_t String::length() const {
	return m_size;
}
size_t String::capacity() const {
	return m_capacity;
}
bool String::empty() const {
	return m_size == 0;
}
void String::clear() {
	m_size = 0;
}
void String::resize(size_t n, const char c) {
	if (n > m_size) {
		size_t m = m_size;
		reserve(n);
		m_size = n;
		/*for (size_t i = m - 1; i < m_size; ++i) {
			m_data[i] = c;
		}*/
		memset(m_data + m, c, m_capacity - m);
	}
}
void String::reserve(size_t res_arg = 0) {
	if (res_arg >= m_capacity) {
		m_capacity = (res_arg / m_capacity + 1) * 16 - 1;
		m_data = (char*)realloc(m_data, m_capacity);
		memset(m_data + m_size, 0, m_capacity - m_size);
	}
}

char& String::operator[] (size_t pos) const {
	return m_data[pos];
}
char& String::operator[] (size_t pos) {
	return m_data[pos];
}
void String::push_back(const char c) {
	reserve(m_size);
	m_data[m_size++] = c;
}
void String::pop_back(const char c) {
	if (m_size) {
		--m_size;
	}
}
String& String::append(const char* s) {
	int size = strlen(s) + m_size;
	reserve(size);
	strcat(m_data, s);
	m_size = size;
	return *this;
}
String& String::append(const char c) {
	push_back(c);
	return *this;
}
String& String::append(const String& str) {
	int size = str.m_size + m_size;
	reserve(size);
	strcat(m_data, str.m_data);
	m_size = size;
	return *this;
}
String& String::operator+=(const String&str) {
	int size = str.m_size + m_size;
	reserve(size);
	strcat(m_data, str.m_data);
	m_size = size;
	return *this;
}
String& String::operator+=(const char* s) {
	int size = strlen(s) + m_size;
	reserve(size);
	strcat(m_data, s);
	m_size = size;
	return *this;
}
String& String::operator+=(const char c) {
	push_back(c);
	return *this;
}
String operator+(const char* s, const String& t) {
	String res;
	res = s;
	int size = res.m_size + t.m_size;
	res.reserve(size);
	strcat(res.m_data, t.m_data);
	res.m_size = size;
	return res;
}
String String::operator+(const char* s)const {
	String res = *this;
	int size = strlen(s) + m_size;
	res.reserve(size);
	strcat(res.m_data, s);
	res.m_size = size;
	return res;
}
String String::operator+(const String& t)const {
	String res = *this;
	int size = res.m_size + t.m_size;
	res.reserve(size);
	strcat(res.m_data, t.m_data);
	res.m_size = size;
	return res;
}
const char* String::c_str()const {
	return m_data;
}
size_t String::find(const char c, size_t pos)const {
	if (pos < 0 || pos >= m_size) {
		return -1;
	}
	char* tmp = strchr(m_data + pos, c);
	if (tmp) {
		return tmp - m_data;
	}
	else {
		return -1;
	}
}
size_t String::find(const char* c, size_t pos) const {
	if (pos < 0 || pos >= m_size) {
		return -1;
	}
	char* tmp = strstr(m_data + pos, c);
	if (tmp) {
		return tmp - m_data;
	}
	else {
		return -1;
	}
}
size_t String::find(const String& t, size_t pos)const {
	if (pos < 0 || pos >= m_size) {
		return -1;
	}
	char* tmp = strstr(m_data + pos, t.m_data);
	if (tmp) {
		return tmp - m_data;
	}
	else {
		return -1;
	}
}
//istream& operator>>(istream& os, String& t) {
//
//}
ostream& operator<<(ostream& os, const String& t) {
	for (auto i : t) { 
		os << i;
	}
	return os;
}

//size_t String::rfind(const char c, size_t pos) {
//
//}
//String String::substr(size_t pos, size_t n)const {
//	   
//}