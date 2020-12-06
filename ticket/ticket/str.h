#pragma once
#include <iostream>

class str
{
public:

	str();
	str(const char* str);
	str(const str& str);

	int get_length();
	bool is_empty();
	void clear();

	char* get_str()
	{
		return str_;
	}

	void operator=(const char* str);
	char operator[](int);
	void operator=(const str& str);
	void operator+=(const char* str_to_add);
	void operator+=(const str& str);
	void operator+=(const char& a);

	template <typename T>
	friend str operator+(const T& str_1, const T& str_2)
	{
		str str_final;
		str_final = str_1;
		str_final += str_2;
		return str_final;
	}

	bool operator==(const str& str);
	bool operator!=(const str& str);
	friend std::ostream& operator<<(std::ostream& out, const str& str);
	friend std::istream& operator>>(std::istream& in, str& str);
	friend std::istream& operator>>(std::fstream& in, str& str);

	~str() = default;

private:
	char* str_;
	int get_size(const char* str);
};