
#include "string.h"
#include <iostream>
#include <cstring>
#include <cassert>
#include <climits>

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
	m_size = size;
	m_data = new char[m_size];
	m_data[0] = '\0';
}


sfw::string::string(const char *a, size_t size)
{
	m_size = size;
	m_data = new char[size];
	//strncpy_s(m_data, a, _TRUNCATE);
	
	strncpy_s(m_data, m_size, a, _TRUNCATE);

	m_data[size - 1] = '\0';
}

sfw::string::string(const char *a)
{
	//check on this
	//delete[] m_data;
	if (a != nullptr)
	{
		m_data = new char[m_size = strlen(a) + 1];
		strcpy_s(m_data, m_size, a);
	}

	else
	{
		m_data = new char[m_size = 1]{ '\0' };
	}
}

sfw::string::string(const string &a)
{
	if (this != &a)
	{
		m_size = a.m_size;
		m_data = new char[m_size];
		strcpy_s(m_data, m_size, a.m_data);
	}
	else
	{
		m_data = new char[m_size = 1]{ '\0' };
	}
}

sfw::string::string(string &&a)
{
//	if (m_data != nullptr)
//	{
//		delete[] m_data;
//	}

	m_size = a.m_size;
	m_data = a.m_data;
	a.m_size = 1;
	a.m_data = new char[a.m_size];
	a.m_data[0] = '\0';
}

sfw::string & sfw::string::operator=(const string &a)
{
	//if we are assigning to ourself, DON'T DO ANYTHING!
	if (this == &a) return *this;
	//create a new character array of the appropriate size.
	*this = a.m_data;
	return *this;
}

sfw::string & sfw::string::operator=(string && a)
{
	if (m_data != nullptr)
	{
		delete[] m_data;
	}
	
	m_data = a.m_data;
	m_size = a.m_size;

	a.m_size = 1;
	a.m_data = new char[a.m_size];
	a.m_data[0] = '\0';

	return *this;
}

sfw::string & sfw::string::operator=(const char *a)
{	
	resize(strlen(a) + 1);
	strcpy_s(m_data, m_size, a);
	return *this;
}

sfw::string & sfw::string::operator+=(const string &a)
{
	return *this = *this + a;
}

sfw::string & sfw::string::operator+=(const char *a)
{
	//string *a = new string[m_size];
	//char tempA = *a;
	//resize(tempA);
	//strcat_s(m_data, m_size , tempA);
	//*this += a;
	
	return *this;
}

sfw::string & sfw::string::operator+=(char a)
{
	resize(a);
	//strcat(m_data, a);
	//*this += a;
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
	
	return size_t (m_size);
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
	strncpy_s(t, size, m_data, _TRUNCATE);

	//for (int i = 0; i < size; ++i)
		//t[i] = m_data[i];
	

	//strcpy_s(t, size, m_data);
	m_size = size;
	delete[] m_data;
	m_data = t;

	m_data[size - 1] = '\0';
	//UINT16MAX;
}

void sfw::string::clear()
{
	m_data[0] = '\0';
}

bool sfw::string::empty() const
{
	if (m_data[0] == '\0')
	{
		return true;
	}

	else 
	{
		return false;
	}
}

const char * sfw::string::cstring() const
{
	
	return m_data;
}

bool sfw::operator<(const string &a, const string &b)
{
	
	if (strcmp(a.cstring(), b.cstring()) <0) { return true; }
	else { return false; }
}

bool sfw::operator<(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) <0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator<(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) <0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator<=(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) <=0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator<=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) <=0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator<=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) <= 0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator>(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) >0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator>(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) >0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator>(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) >0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator>=(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) >=0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator>=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) >= 0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator>=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) >= 0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator!=(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) != 0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator!=(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) != 0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator!=(const char * a, const string & b)
{
	if (strcmp(a, b.cstring()) != 0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator==(const string & a, const string & b)
{
	if (strcmp(a.cstring(), b.cstring()) == 0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator==(const string & a, const char * b)
{
	if (strcmp(a.cstring(), b) == 0) { return true; }
	else { return false; }
	return false;
}

bool sfw::operator==(const char *a, const string &b)
{
	if (strcmp(a, b.cstring()) == 0) { return true; }
	else { return false; }
	return false;
}

sfw::string sfw::operator+(const string &a, const string &b)
{
	int tempSize = a.length() + b.length() + 1;

	// form a new string that can fit both strings
	char * temp = new char[tempSize];

	// copy the first term
	strcpy_s(temp, tempSize, a.cstring());

	// cat the second term
	strcat_s(temp, tempSize, b.cstring());
	
	string retVal(temp);

	delete temp;

	return retVal;
}

sfw::string sfw::operator+(const string &a, const char *b)
{
	int tempSize = a.length() + strlen(b) + 1;

	// form a new string that can fit both strings
	char * temp = new char[tempSize];

	// copy the first term
	strcpy_s(temp, tempSize, a.cstring());

	// cat the second term
	strcat_s(temp, tempSize, b);

	string retVal(temp);

	delete temp;

	return retVal;
}

sfw::string sfw::operator+(const char *a, const string &b)
{
	int tempSize = strlen(a) + b.length() + 1;

	// form a new string that can fit both strings
	char * temp = new char[tempSize];

	// copy the first term
	strcpy_s(temp, tempSize, a);

	// cat the second term
	strcat_s(temp, tempSize, b.cstring());

	string retVal(temp);

	delete temp;

	return retVal;
}

sfw::string sfw::operator+(const string & a, char b)
{
	int tempSize = a.length() + b + 1;
	 
	// form a new string that can fit both strings
	char * temp = new char[tempSize];

	// copy the first term
	strcpy_s(temp, tempSize, a.cstring());

	// cat the second term
	strcat_s(temp, tempSize, b);

	string retVal(temp);

	delete temp;

	return retVal;
	
}

sfw::string sfw::operator+(char a, const string & b)
{
	int tempSize = a + b.length() + 1;

	// form a new string that can fit both strings
	char * temp = new char[tempSize];

	// copy the first term
	strcpy_s(temp, tempSize, a);

	// cat the second term
	strcat_s(temp, tempSize, b.cstring());

	string retVal(temp);

	delete temp;

	return retVal;
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
	 
	return string(a , len + 1);
}
