#include "str.h"
#include <iostream>

str::str() :
	str_(nullptr)
{}
str::str(const char* str)
{
	int size = get_size(str);

	str_ = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		str_[i] = str[i];
	}
	str_[size] = '\0';
}
str::str(const str& str)
{
	if (str.str_ != nullptr)
	{
		int size = get_size(str.str_);
		str_ = new char[size + 1];
		for (int i = 0; i < size; i++)
		{
			str_[i] = str.str_[i];
		}
		str_[size] = '\0';
	}
	else
	{
		str_ = nullptr;
	}
}

void str::operator=(const char* str)
{
	if (str_ != nullptr)
		delete[] str_;

	int size = get_size(str);

	str_ = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		str_[i] = str[i];
	}
	str_[size] = '\0';
}

void str::operator=(const str& str)
{
	if (str_ != nullptr)
		delete[] str_;

	int size = get_size(str.str_);

	str_ = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		str_[i] = str.str_[i];
	}
	str_[size] = '\0';
}

void str::operator+=(const char* str_to_add)
{
	if (str_ == nullptr)
	{
		int str_to_add_size = get_size(str_to_add);
		str_ = new char[str_to_add_size + 1];
		for (int i = 0; i < str_to_add_size; i++)
		{
			str_[i] = str_to_add[i];
		}
		str_[str_to_add_size] = '\0';
	}
	else
	{
		int old_str_size = get_size(str_);
		int str_to_add_size = get_size(str_to_add);

		int new_size = old_str_size + str_to_add_size;

		char* old_str = new char[old_str_size + 1];

		for (int i = 0; i < old_str_size; i++)
		{
			old_str[i] = str_[i];
		}
		old_str[old_str_size] = '\0';

		delete[] str_;

		str_ = new char[new_size + 1];

		for (int i = 0; i < old_str_size; i++)
		{
			str_[i] = old_str[i];
		}
		for (int i = old_str_size; i < new_size; i++)
		{
			str_[i] = str_to_add[i - old_str_size];
		}
		str_[new_size] = '\0';

		delete[] old_str;
	}
}

void str::operator+=(const str& str_to_add)
{
	if (str_to_add.str_ != nullptr)
	{
		if (str_ == nullptr)
		{
			int str_to_add_size = get_size(str_to_add.str_);
			str_ = new char[str_to_add_size + 1];
			for (int i = 0; i < str_to_add_size; i++)
			{
				str_[i] = str_to_add.str_[i];
			}
			str_[str_to_add_size] = '\0';
		}
		else
		{
			int old_str_size = get_size(str_);
			int str_to_add_size = get_size(str_to_add.str_);

			int new_size = old_str_size + str_to_add_size;

			char* old_str = new char[old_str_size + 1];

			for (int i = 0; i < old_str_size; i++)
			{
				old_str[i] = str_[i];
			}

			old_str[old_str_size] = '\0';
			delete[] str_;

			str_ = new char[new_size + 1];

			for (int i = 0; i < old_str_size; i++)
			{
				str_[i] = old_str[i];
			}
			for (int i = old_str_size; i < new_size; i++)
			{
				str_[i] = str_to_add.str_[i - old_str_size];
			}
			str_[new_size] = '\0';

			delete[] old_str;
		}
	}
}

void str::operator+=(const char& a)
{
	if (str_ == nullptr)
	{
		delete[] str_;
		str_ = new char[1];
		str_[0] = a;
	}
	else
	{
		char* strHelper = new char[get_size(str_)];
		delete[] str_;
		str_ = new char[get_size(strHelper) + 1];
		str_ = strHelper;
		str_[get_size(strHelper)] = a;
		delete[] strHelper;
	}
}

bool str::operator==(const str& str)
{
	if (str_ == nullptr && str.str_ == nullptr)
	{
		return true;
	}
	if (str_ == nullptr && str.str_ != nullptr || str_ != nullptr && str.str_ == nullptr)
	{
		return false;
	}
	else if (get_size(str_) != get_size(str.str_))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < get_size(str_); i++)
		{
			if (str_[i] != str.str_[i])
				return false;
		}
		return true;
	}
}

char str::operator[](int i)
{
	return str_[i];
}

bool str::operator!=(const str& str)
{
	return !operator==(str);
}

std::ostream& operator<<(std::ostream& out, const str& str)
{
	if (str.str_ != nullptr)
		out << str.str_;
	else
		out << "\0";
	return out;
}
std::istream& operator>>(std::istream& in, str& str)
{
	in.rdbuf()->sgetc();
	int size = in.rdbuf()->in_avail();
	size--;

	if (str.str_ != nullptr)
		delete[] str.str_;

	str.str_ = new char[size + 1];
	in >> str.str_;
	str.str_[size] = '\0';

	return in;
}

int str::get_size(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
int str::get_length()
{
	if (str_ != nullptr)
	{
		int i = 0;
		while (str_[i] != '\0')
		{
			i++;
		}
		return i;
	}
	else
	{
		return 0;
	}
}
bool str::is_empty()
{
	return str_ == nullptr;
}
void str::clear()
{
	if (str_ != nullptr)
	{
		delete[] str_;
		str_ = nullptr;
	}
}