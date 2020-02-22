// String ADT
//

#include "string.hpp"
String::String() {
	stringSize = 1;
	str = new char[stringSize];
	str[0] = 0;
}

String::String(char ch) {
	stringSize = 2;
	str = new char[stringSize];
	str[0] = ch;
	str[1] = 0;
}

String::String(const char chArr[]) {
	int count = 0;
	while (chArr[count] != 0) ++count;
	stringSize = count + 1;
	str = new char[stringSize];
	for (int i = 0; i < stringSize; ++i) {
		str[i] = chArr[i];
	}
	str[stringSize - 1] = 0;
}

String::String(int size) {
	stringSize = size;
	str = new char[stringSize];
	str[0] = 0;
}

String::String(int size, const char chArr[]) {
	int count = 0;
	while (chArr[count] != 0) ++count;
	if (size < count) size = count;
	stringSize = size;
	str = new char[stringSize];
	for (int i = 0; i < stringSize; ++i) {
		str[i] = chArr[i];
	}
	str[stringSize - 1] = 0;
}

void String::resetCapacity(int size) {
	if (size < length()) std::cout << "Loss of contents prohibited\n"; return;
	char *temp = new char[size];
	for (int i = 0; i <= length(); ++i)
		temp[i] = str[i];
	delete [] str;
	stringSize = size;
	str = new char[stringSize];
	for (int i = 0; i < stringSize; ++i)
		str[i] = temp[i];
		
}

String::String(const String& actual) {
	stringSize = actual.stringSize;
	str = new char[stringSize];
	for (int i = 0; i < stringSize; ++i) {
		str[i] = actual.str[i];
	}
	str[stringSize - 1] = 0;
}

String::~String() {
	delete [] str;
}

void String::swap(String& rhs) {
	int temp = stringSize;
	stringSize = rhs.stringSize;
	rhs.stringSize = temp;
	char *tmp = str;
	str = rhs.str;
	rhs.str = tmp;
}

String& String::operator=(String rhs) {
	swap(rhs);
	return *this;
}

char& String::operator[](int index) {
	assert(index >= 0);
	assert(index <= stringSize);
	return str[index];
}

char String::operator[] (int index) const {
	assert(index >= 0);
	assert(index <= stringSize);
	return str[index];
}

int String::capacity() const {
	return stringSize - 1;
}

int String::length() const {
	int index = 0;
	while(str[index] != 0)
		++index;
	return index;
}

String String::substr(int start, int end) const {
	if (start < 0) start = 0;
	if (end > length()) end = length();
	if (end < start) return "";
	String sub(end - start + 2); // original +1;
	for (int i = 0; i <= end - start; ++i) {
		sub.str[i] = str[i + start]; 
	}
	sub.str[sub.stringSize - 1] = 0;
	return sub;
}

int String::findch(int pos, char ch) const {
	if (pos < 0) pos = 0;
	if (pos > length()) pos = length();
	while (pos < length()){
		if(str[pos] == ch)
			return pos;
		++pos;
	}
	return -1;
}

int String::findstr(int pos, const String& strToFind) const {
	if (pos < 0) pos = 0;
	if (pos > length()) pos = length();
	while(pos <= length() - strToFind.length()) {
		if (substr(pos, pos + strToFind.length() - 1) == strToFind)
			return pos;
		++pos;
	}
	return -1;
}

int String::toInt() {
	int index = 0;
	int result = 0;
	while (index < length()) {
		result *= 10;
		result += str[index] - '0';
		++index;
	}
	return result;
}

String String::operator+(const String& rhs) const {
	String result(capacity() + rhs.capacity() + 1);
	//std::cout << "concat start" << std::endl;
	for (int i = 0; i < stringSize; ++i)
		result.str[i] = str[i];
	int offset = result.length();
	for (int i = 0; i < rhs.stringSize; ++i) {
		result.str[i + offset] = rhs.str[i];
	}
	result.str[result.stringSize - 1] = 0;
	//std::cout << "Concat finished" << std::endl;
	return result;
}

String& String::operator+= (const String& rhs) {
	*this = *this + rhs;
	return *this;
}

bool String::operator==(const String& rhs) const {
	int size = (length() < rhs.length() ? length() : rhs.length());
	for (int i = 0; i <= size; ++i) {
		if(str[i] != rhs.str[i])
			return false;
	}
	return true;
}

bool String::operator<(const String& rhs) const {
	int index = 0;
	int size = (length() < rhs.length() ? length() : rhs.length());
	while (str[index] == rhs.str[index] && index < size)
		++index;
	return str[index] < rhs.str[index];
}

std::vector<String> String::split(char ch) const {
	std::vector<String> result;
	int start = 0;
	int end = 0;
	while (end != -1) {
		end = findch(start, ch);
		if (end == -1) break;
		if (end == 0) {
			result.push_back("");
			start = end + 1;
			continue;
		}
		result.push_back(substr(start, end - 1));
		start = end + 1;
	}
	if (length() == 1 && str[0] != ch) 
		result.push_back(substr(0, 0));
	else if (start != length()) 
		result.push_back(substr(start, length() - 1));
	else if (start == length()) 
		result.push_back("");
	return result;
} 

std::istream& operator>>(std::istream& in, String& rhs) {
	char temp[256];
	in >> temp;
	int count = 0;
	while (temp[count] != 0) ++count;
	delete [] rhs.str;
	rhs.stringSize = count;
	rhs.str = new char[rhs.stringSize];
	for (int i = 0; i < rhs.stringSize; ++i)
		rhs.str[i] = temp[i];
	rhs.str[rhs.stringSize] = 0;
	return in;
}

std::ostream& operator<<(std::ostream& out, const String& rhs) {
	int index = 0;
	while (index < rhs.length()) {
		out << rhs.str[index];
		++index;
	}	
	return out;
}


String operator+(const char chArr[],  const String& rhs) {
	String lhs(chArr);
	return lhs + rhs;
}

String operator+(char ch, const String& rhs) {
	String lhs(ch);
	return lhs + rhs;
}

bool operator==(const char chArr[], const String& rhs) {
	return rhs == chArr;
}

bool operator==(char ch, const String& rhs) {
	return rhs == ch;
}

bool operator< (const char chArr[], const String& rhs) {
	String lhs(chArr);
	return lhs < rhs;
}

bool operator<(char ch, const String& rhs) {
	String lhs(ch);
	return lhs < rhs;
}

bool operator<=(const String& lhs, const String& rhs) {
	return (lhs < rhs || lhs == rhs);
}
/*
bool operator<=(const char chArr[], const String& rhs) {
	String lhs(chArr);
	return lhs <= rhs;
}

bool operator<=(char ch, const String& rhs) {
	String lhs(ch);
	return lhs <= rhs;
}*/

bool operator!=(const String& lhs, const String& rhs) {
	return !(lhs == rhs);
}
/*
bool operator!=(const char chArr[], const String& rhs) {
	return rhs != chArr;
}

bool operator!=(char ch, const String& rhs) {
	return rhs != ch;
}*/

bool operator>=(const String& lhs, const String& rhs) {
	return (rhs < lhs || lhs == rhs);
}
/*
bool operator>=(const char chArr[], const String& rhs) {
	return (rhs < chArr || rhs == chArr);
}

bool operator>=(char ch, const String& rhs) {
	return (rhs < ch || rhs == ch);
}*/

bool operator>(const String& lhs, const String& rhs) {
	return rhs < lhs;
}
/*
bool operator>(const char chArr[], const String& rhs) {
	return rhs < chArr;
}

bool operator>(char ch, const String& rhs) {
	return rhs < ch;
}*/
