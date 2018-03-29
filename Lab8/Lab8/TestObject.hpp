#pragma once
#include <iostream>
class TObject {

public:
	//Default constructor for template
	TObject() {};

	//Consturctor
	TObject(int _data) : data(_data) {};

	//Copy constructor
	TObject(const TObject & obj) { data = obj.data; }

	//Swap two objects
	//PRE	: both objects are same class
	//POST	: data of two objects are exchanged
	friend void swap(TObject & lhs, TObject & rhs);

	TObject & operator=(TObject rhs) { swap(*this, rhs); return *this; }

	//Overloaded insertion operator
	friend std::ostream & operator<<(std::ostream & out, const TObject & obj) {
		out << obj.data;
		return out;
	}

	//Overloaded == operator
	friend bool operator==(const TObject & lhs, const TObject & rhs) {
		if (lhs.data == rhs.data)
			return true;
		return false;
	}

	//Get data
	int getData() { return data; }


private:
	int data;
};

void swap(TObject & lhs, TObject & rhs) { std::swap(lhs.data, rhs.data); }