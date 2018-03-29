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
	size_t index;
};

template<class T, size_t N>
inline FixedList<T, N>::FixedList()
	:index {0}
{
	list = new T[N];
}

template<class T, size_t N>
inline FixedList<T, N>::~FixedList()
{
	delete[] list;
}

template<class T, size_t N>
inline const T & FixedList<T, N>::get(unsigned int index) const
{
	
}

template<class T, size_t N>
inline int FixedList<T, N>::getFirstIndex(const T & t) const
{
	return 0;
}

template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return size_t();
}

template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return N;
}

template<class T, size_t N>
inline bool FixedList<T, N>::add(const T & t)
{
	return false;
}

template<class T, size_t N>
inline T FixedList<T, N>::remove(const T & t)
{
	return T();
}

template<class T, size_t N>
inline T & FixedList<T, N>::operator[](unsigned int index) const
{
	// TODO: insert return statement here
}
