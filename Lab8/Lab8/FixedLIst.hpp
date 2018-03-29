#pragma once
#include <iostream>
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
	T  operator[](unsigned int index) const;

	template<class T, size_t N>
	friend std::ostream & operator<<(std::ostream & out, const FixedList<T, N> & obj);

private:
	T list[N];
	size_t arrSize;
};

//Constructor
template<class T, size_t N>
inline FixedList<T, N>::FixedList()
	:arrSize{0}
{
}

//Destructor
template<class T, size_t N>
inline FixedList<T, N>::~FixedList()
{
}

//Get an object in specific index
//PRE	: passing index should be unsigned integer
//POST	: NULL
//RETURN: an object in the list with an index
template<class T, size_t N>
inline const T & FixedList<T, N>::get(unsigned int index) const
{
	if (index >= arrSize || index < 0) {
		throw std::invalid_argument("Out of bound!");
	}
	return list[index];
}


//Get index of first matched object in the list
//PRE	: NULL
//POST	: NULL
//RETURN: the index of the first occurance
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

//Get size of list
//PRE	: NULL
//POST	: NULL
//REUTNR: the size of the list
template<class T, size_t N>
inline size_t FixedList<T, N>::size() const
{
	return arrSize;
}

//Get capacity of list
//PRE	: NULL
//POST	: NULL
//RETURN: capacity of list
template<class T, size_t N>
inline size_t FixedList<T, N>::capacity() const
{
	return N;
}

//Add an passed object into list
//PRE	: NULL
//POST	: if the size if not exceeded the capacity
//		  list adds the object
//RETURN: true if it's added successfully
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

//Remove specific object from list
//PRE	: NULL
//POST	: if there is a matched object, remove it from list
//RETURN: removed object
template<class T, size_t N>
inline T FixedList<T, N>::remove(const T & t)
{
	T removed;
	for (size_t i = 0; i < arrSize; ++i) {
		if (list[i] == t) {
			removed = t;
			if (i == 0) {
				--arrSize;
				list[i] = NULL;
				return  removed;
			}
			size_t j;
			for (j = i; j < arrSize; ++j) {
				if (j != arrSize - 1) {
					list[j] = list[j + 1];
				}
			}
			list[j - 1] = NULL;
			--arrSize;

			return removed;

		}
	}
	return NULL;
}

//Overloaded [] operator
template<class T, size_t N>
inline T  FixedList<T, N>::operator[](unsigned int index) const
{
	if (index < 0 || index >= arrSize) {
		throw std::invalid_argument("Out of bound!!");
	}

	return list[index];
}

//Overloaded insertion operator
template<class T, size_t N>
std::ostream & operator<<(std::ostream & out, const FixedList<T, N>& obj)
{
	for (size_t i = 0; i < obj.size(); ++i) {
		out << obj.list[i] << "  ";
	}
	out << std::endl;

	return out;
}