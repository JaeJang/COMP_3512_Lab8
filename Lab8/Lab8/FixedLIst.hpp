#pragma once
#include <stdexcept>

template<class T, size_t N>
class FixedList {

public:
	FixedList();
	~FixedList();
	const T& get(unsigned int index) const;
	int getFirstIndex(const T& t) const;
	size_t size() const;
	size_t capacity() const;
	bool add(const T & t);
	T remove(const T& t);
	T & operator[](unsigned int index) const;
private:
	T[] list;
};

