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
	size_t maxIndex;
};

template<class T, size_t N>
inline FixedList<T, N>::FixedList()
	:maxIndex{-1}
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
	if (index > maxIndex || index < 0) {
		throw std::invalid_argument("Out of bound!");
	}
}

template<class T, size_t N>
inline int FixedList<T, N>::getFirstIndex(const T & t) const
{
	for (int i = 0; i < maxIndex + 1; ++i) {
		if (list[i] == t) {
			return i;
		}
	}
	return -1;
}

template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return maxIndex + 1 ;
}

template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return N;
}

template<class T, size_t N>
inline bool FixedList<T, N>::add(const T & t)
{
	if (maxIndex + 1 >= N) {
		return false;
	}
	++maxIndex;
	list[maxIndex] = t;
	return true;
}

template<class T, size_t N>
inline T FixedList<T, N>::remove(const T & t)
{
	T removed;
	for (int i = 0; i < maxIndex + 1; ++i) {
		if (list[i] == t) {
			removed = t;
			if (i == 0) {
				--maxIndex;
				list[i] = NULL;
				return  removed;
			}
			int j;
			for (j = i; j < maxIndex + 1; ++j) {
				if(j != maxIndex)
					list[j] = list[j + 1];
			}
			list[j] = NULL;
			--maxIndex;

			return removed;

		}
	}
	return NULL;
}

template<class T, size_t N>
inline T & FixedList<T, N>::operator[](unsigned int index) const
{
	if (index < 0 || index > maxIndex) {
		throw std::invalid_argument("Out of bound!!");
	}

	return list[index];
}
