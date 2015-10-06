
#include "string.h"
#include <iostream>
#include <cstring>
#include <cassert>

// A few freebies to get past the first couple of tests.
// These may need to be modified!
sfw::string::string(void)
{
		m_data = new char[m_size = 1]{ '\0' };
		
		
}

sfw::string::~string()
{
	
	delete[]m_data;
}

size_t sfw::string::length() const
{
	
	return strlen(m_data);
}





sfw::string::string(size_t size)
{
	m_size = size + 1;
	m_data = new char[m_size];
	m_data[0] = '/0';
}

sfw::string::string(const char *a, size_t size)
{
	
	strcpy_s(m_data, size , a);
}

sfw::string::string(const char *a)
{
	//check on this
	delete[] m_data;
	resize(strlen(a) + 1);
	strcpy_s(m_data, m_size , a);
	
}

sfw::string::string(const string &a)
{
	
	*this = a.m_data;
}

sfw::string::string(string &&a)
{
	resize(a.m_size);
	strcpy_s(m_data, a.m_size, a.m_data);
	delete[] a.m_data;
	
}

sfw::string & sfw::string::operator=(const string &a)
{
	//create a new character array of the appropriate size.
	*this = a.m_data;
	return *this;
}

sfw::string & sfw::string::operator=(string && a)
{
	m_data = a.m_data;
	m_size = a.m_size;

	a.m_data = nullptr;
	a.m_size = 0;

	return *this;
}

sfw::string & sfw::string::operator=(const char *a)
{
	delete[] m_data;
	resize(strlen(a) + 1);
	strcpy_s(m_data, m_size, a);
	return *this;
}

sfw::string & sfw::string::operator+=(const string &a)
{
	
	resize(a.m_size);
	strcat_s(m_data, a.m_size, a.m_data);
	return *this;
}

sfw::string & sfw::string::operator+=(const char *a)
{
	*this += a;
	return *this;
}

sfw::string & sfw::string::operator+=(char a)
{
	*this += a;
	return *this;
}

char & sfw::string::operator[](size_t index)
{
	return this->m_data[index];
}

const char & sfw::string::operator[](size_t index) const
{
	return this->m_data[index];
}




size_t sfw::string::size() const
{
	
	return size_t (m_size - 1);
}


/*
	create new array of size 
	copy our existing info into that
	delete our old info
	assign our pointer to that guy
	and set our size to match
	// make sure that the new size is >= 1
	// so that we can be certain it ends w/a
	// terminating character
*/
void sfw::string::resize(size_t size)
{
	if (size < 1) size = 1;
	char *t = new char[size];
	strcpy_s(t, size, m_data);
	m_size = size;
	delete[] m_data;
	m_data = t;

	m_data[size - 1] = '\0';
		 
}

void sfw::string::clear()
{
	// TODO:
}

bool sfw::string::empty() const
{
	// TODO:
	return false;
}

const char * sfw::string::cstring() const
{
	// TODO:
	return nullptr;
}

bool sfw::operator<(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator<(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator<(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator<=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator>(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator>=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator!=(const char * a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const string & a, const string & b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const string & a, const char * b)
{
	// TODO:
	return false;
}

bool sfw::operator==(const char * a, const string & b)
{
	// TODO:
	return false;
}

sfw::string sfw::operator+(const string & a, const string & b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const string & a, const char * b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const char * a, const string & b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(const string & a, char b)
{
	// TODO:
	return string();
}

sfw::string sfw::operator+(char a, const string & b)
{
	// TODO:
	return string();
}

std::ostream & sfw::operator<<(std::ostream & os, const string & p)
{
	// TODO:
	return os;
}

std::istream & sfw::operator>>(std::istream & is, string & p)
{
	// TODO:
	return is;
}

const sfw::string sfw::literals::operator""_sfw(const char * a, size_t len)
{
	// TODO:
	return string();
}
