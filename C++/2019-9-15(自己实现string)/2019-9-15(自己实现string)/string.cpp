#include "string.h"
String::Iterator String::begin()const {
	return m_data;
}
String::Iterator String::end() const{
	return m_data + m_size;
}
String::String() :m_size(0),
				m_capacity(15),
				m_data(new char[m_capacity]) 
{
	memset(m_data, 0, m_capacity);
}
String::String(const String& t):m_size(0)
							,m_capacity(15)
							,m_data(new char[m_capacity])
{
	if (this == &t) {
		return;
	}
	memset(m_data, 0, m_capacity);
	reserve(t.m_capacity);
	m_size = t.m_size;
	m_capacity = t.m_capacity;
	strncpy(m_data, t.m_data, m_size);
}
String::String(const char* t) :m_size(0)
							, m_capacity(15)
							, m_data(new char[m_capacity]) 
{
	if (t == nullptr) {
		assert(false);
	}
	size_t size = strlen(t);
	reserve(size);
	m_size = size;
	strcpy(m_data, t);
}
String::String(size_t n, char c) :m_size(0)
								, m_capacity(15)
								, m_data(new char[m_capacity])
{
	reserve(n);
	m_size = n;
	memset(m_data, c, n);
}
String::String(const String& t, size_t n) :m_size(0)
										, m_capacity(15)
										, m_data(new char[m_capacity])
{
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
	if (s == nullptr) {
		assert(false);
	}
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
	if (res_arg > m_capacity) {
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
	if (s == nullptr) {
		assert(false);
	}
	int size = strlen(s) + m_size;
	reserve(size);
	strcpy(m_data + m_size, s);
	m_size = size;
	return *this;
}
String& String::append(size_t n, const char c) {
	while (n--) {
		push_back(c);
	}
	return *this;
}
String& String::append(const String& str) {
	int size = str.m_size + m_size;
	reserve(size);
	strncpy(m_data + m_size, str.m_data, str.m_size);
	m_size = size;
	return *this;
}
String& String::operator+=(const String&str) {
	int size = str.m_size + m_size;
	reserve(size);
	strncpy(m_data + m_size, str.m_data, str.m_size);
	m_size = size;
	return *this;
}
String& String::operator+=(const char* s) {
	if (s == nullptr) {
		assert(false);
	}
	int size = strlen(s) + m_size;
	reserve(size);
	strcpy(m_data + m_size, s);
	m_size = size;
	return *this;
}
String& String::operator+=(const char c) {
	push_back(c);
	return *this;
}
String operator+(const char* s, const String& t) {
	if (s == nullptr) {
		assert(false);
	}
	String res;
	res = s;
	int size = res.m_size + t.m_size;
	res.reserve(size);
	strncpy(res.m_data + res.m_size, t.m_data, t.m_size);
	res.m_size = size;
	return res;
}

String String::operator+(const char* s)const {
	if (s == nullptr) {
		assert(false);
	}
	String res = *this;
	int size = strlen(s) + m_size;
	res.reserve(size);
	strcpy(res.m_data + res.m_size, s);
	res.m_size = size;
	return res;
}
String String::operator+(const String& t)const {
	String res = *this;
	int size = res.m_size + t.m_size;
	res.reserve(size);
	strncpy(res.m_data + res.m_size, t.m_data, t.m_size);
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
	if (c == nullptr) {
		assert(false);
	}
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
size_t String::rfind(const char c, size_t pos)const{
	char* tmp = nullptr;
	strncpy(tmp, m_data, pos);
	char* m = nullptr;
	if (tmp) {
		m = strchr(tmp, c);
	}
	if (m) {
		return m - tmp;
	}
	else {
		return -1;
	}
}		 
size_t String::rfind(const char* s, size_t pos)const {
	if (s == nullptr) {
		assert(false);
	}
	char* tmp = nullptr;
	strncpy(tmp, m_data, pos);
	char* m = nullptr;
	if (tmp) {
		m = strstr(tmp, s);
	}
	if (m) {
		return m - tmp;
	}
	else {
		return -1;
	}
}
size_t String::rfind(const String& t, size_t pos)const {
	char* tmp = new char[pos + 1];
	tmp[pos] = 0;
	strncpy(tmp, m_data, pos);
	char* m = nullptr;
	if (tmp) {
		m = strstr(tmp, t.c_str());
	}
	if (m) {
		return m - tmp;
		delete[]tmp;
	}
	else {
		return -1;
		delete[]tmp;
	}
}
String String::substr(size_t pos, size_t n)const {
	String res;
	if (pos > m_size)return res;
	if (pos + n > m_size) {
		n = m_size - pos;
	}
	res.reserve(n);
	res.m_size = n;
	strncpy(res.m_data, m_data + pos, n);
	return res;
}
istream& operator>>(istream& is, String& t) {
	char ch;
	t.m_size = 0;
	is >> ch;
	while (ch != '\n') {
		t.push_back(ch);
		ch = getchar();
	}
	return is;
}
ostream& operator<<(ostream& os, const String& t) {
	for (auto i : t) { 
		os << i;
	}
	return os;
}
istream& getline(istream&  is, String& t, char n) {
	char ch;
	t.m_size = 0;
	is >> ch;
	while (ch != n) {
		t.push_back(ch);
		ch = getchar();
	}
	return is;
	return is;
}
istream& getline(istream&  is, String& t) {
	char ch;
	t.m_size = 0;
	is >> ch;
	while (ch != '\n') {
		t.push_back(ch);
		ch = getchar();
	}
	return is;
}

bool String::operator<(const String& t)const {
	size_t n;
	m_size < t.m_size ? n = m_size : n = t.m_size;
	return strncmp(m_data, t.m_data, n) < 0;
}
bool String::operator>(const String& t)const {
	size_t n;
	m_size < t.m_size ? n = m_size : n = t.m_size;
	return strncmp(m_data, t.m_data, n) > 0;
}
bool String::operator<=(const String& t)const {
	//size_t n;
	//m_size < t.m_size ? n = m_size : n = t.m_size;
	//return strncmp(m_data, t.m_data, n) < 0 || m_size == t.m_size && !strncmp(m_data, t.m_data, n);
	return *this < t || *this == t;
}
bool String::operator>=(const String& t)const {
	//size_t n;
	//m_size < t.m_size ? n = m_size : n = t.m_size;
	//return strncmp(m_data, t.m_data, n) > 0 || m_size == t.m_size && !strncmp(m_data, t.m_data, n);
	return *this > t || *this == t;
}
bool String::operator==(const String& t)const {
	size_t n;
	m_size < t.m_size ? n = m_size : n = t.m_size;
	return m_size == t.m_size && !strncmp(m_data, t.m_data, n);
}
bool String::operator!=(const String& t)const {
	//size_t n;
	//m_size < t.m_size ? n = m_size : n = t.m_size;
	//return m_size != t.m_size || !strncmp(m_data, t.m_data, n);
	return !(*this == t);
}

bool String::operator<(const char* s)const {
	if (s == nullptr) {
		assert(false);
	}
	size_t n = strlen(s);
	m_size < n ? n = m_size : n;
	return strncmp(m_data, s, n) < 0;
}
bool String::operator>(const char* s)const {
	if (s == nullptr) {
		assert(false);
	}
	size_t n = strlen(s);
	m_size < n ? n = m_size : n;
	return strncmp(m_data, s, n) > 0;
}
bool String::operator<=(const char* s)const{
	if (s == nullptr) {
		assert(false);
	}
	return *this < s || *this == s;
}
bool String::operator>=(const char* s)const{
	if (s == nullptr) {
		assert(false);
	}
	return *this > s || *this == s;
}
bool String::operator==(const char* s)const{
	if (s == nullptr) {
		assert(false);
	}
	size_t L = strlen(s);
	size_t n;
	m_size < L ? n = m_size : n = L;
	return m_size == strlen(s) && !strncmp(m_data, s, n);
}
bool String::operator!=(const char* s)const{
	if (s == nullptr) {
		assert(false);
	}
	return !(*this == s);
}

bool operator<(const char* t1, const String& t2) {
	if (t1 == nullptr) {
		assert(false);
	}
	/*size_t n;
	size_t size = strlen(t1);
	size < t2.m_size ? n = size : n = t2.m_size;
	return strncmp(t1, t2.m_data, n) < 0;*/
	return t2 > t1;
}
bool operator>(const char* t1, const String& t2) {
	if (t1 == nullptr) {
		assert(false);
	}
	/*size_t n;
	size_t size = strlen(t1);
	size < t2.m_size ? n = size : n = t2.m_size;
	return strncmp(t1, t2.m_data, n) > 0;*/
	return t2 < t1;
}
bool operator<=(const char* t1, const String& t2){
	if (t1 == nullptr) {
		assert(false);
	}
	return  t2 >= t1;
	/*size_t n;
	size_t size = strlen(t1);
	size < t2.m_size ? n = size : n = t2.m_size;
	return strncmp(t1, t2.m_data, n) < 0 || size == t2.m_size && !strncmp(t1, t2.m_data, n);*/
}
bool operator>=(const char* t1, const String& t2){
	if (t1 == nullptr) {
		assert(false);
	}
	return t2 <= t1;
	/*size_t n;
	size_t size = strlen(t1);
	size < t2.m_size ? n = size : n = t2.m_size;
	return strncmp(t1, t2.m_data, n) > 0 || size == t2.m_size && !strncmp(t1, t2.m_data, n);*/
}
bool operator==(const char* t1, const String& t2){
	if (t1 == nullptr) {
		assert(false);
	}
	/*size_t n;
	size_t size = strlen(t1);
	size < t2.m_size ? n = size : n = t2.m_size;
	return size == t2.m_size && !strncmp(t1, t2.m_data, n);*/
	return t2 == t1;
}
bool operator!=(const char* t1, const String& t2){
	if (t1 == nullptr) {
		assert(false);
	}
	//return !(t1 == t2);
	return !(t2 == t1);
}