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
	T list[N];
	size_t arrSize;
};

template<class T, size_t N>
inline FixedList<T, N>::FixedList()
	:arrSize{0}
{
}

template<class T, size_t N>
inline FixedList<T, N>::~FixedList()
{
	//delete[] list;
}

template<class T, size_t N>
inline const T & FixedList<T, N>::get(unsigned int index) const
{
	if (index >= arrSize || index < 0) {
		throw std::invalid_argument("Out of bound!");
	}
	return list[index];
}

template<class T, size_t N>
inline int FixedList<T, N>::getFirstIndex(const T & t) const
{
	for (size_t i = 0; i < arrSize; ++i) {
		if (list[i] == t) {
			return i;
		}
	}
	return -1;
}

template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return arrSize;
}

template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return N;
}

template<class T, size_t N>
inline bool FixedList<T, N>::add(const T & t)
{
	if (arrSize >= N) {
		return false;
	}
	++arrSize;
	list[arrSize - 1] = t;
	return true;
}

template<class T, size_t N>
inline T FixedList<T, N>::remove(const T & t)
{
	T removed;
	for (int i = 0; i < arrSize; ++i) {
		if (list[i] == t) {
			removed = t;
			if (i == 0) {
				--arrSize;
				list[i] = NULL;
				return  removed;
			}
			int j;
			for (j = i; j < arrSize; ++j) {
				if(j != arrSize - 1)
					list[j] = list[j + 1];
			}
			list[j] = NULL;
			--arrSize;

			return removed;

		}
	}
	return NULL;
}

template<class T, size_t N>
inline T & FixedList<T, N>::operator[](unsigned int index) const
{
	if (index < 0 || index >= arrSize) {
		throw std::invalid_argument("Out of bound!!");
	}

	return list[index];
}
