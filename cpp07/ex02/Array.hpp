#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template<typename T>
class Array
{
public:
	Array() : length_(0)
	{
		arr_ = new T[0];
	}

	Array(unsigned int n) : length_(n)
	{
		arr_ = new T[n];
	}

	Array(const Array &other)
	{
		*this = other;
	}

	Array &operator=(const Array &rhs)
	{
		length_ = rhs.length_;
		arr_ = new T[length_];
		for (unsigned int i = 0; i < length_; ++i)
		{
			arr_[i] = rhs.arr_[i];
		}
		return (*this);
	}

	~Array()
	{
		delete[] arr_;
	}

	T &operator[](unsigned int idx)
	{
		if (length_ <= idx)
			throw std::exception();
		return (arr_[idx]);
	}

	const T &operator[](unsigned int idx) const
	{
		if (length_ <= idx)
			throw std::exception();
		return (arr_[idx]);
	}

	unsigned int size() const
	{
		return (length_);
	}

private:
	unsigned int length_;
	T *arr_;
};

#endif // !ARRAY_HPP
