#pragma once
#include <iostream>
class TObject {

public:
	TObject() {};
	TObject(int _data) : data(_data) {};
	TObject(const TObject & obj) { data = obj.data; }
	friend void swap(TObject & lhs, TObject & rhs) { std::swap(lhs.data, rhs.data); }
	TObject & operator=(TObject rhs) { swap(*this, rhs); return *this; }
	friend std::ostream & operator<<(std::ostream & out, const TObject & obj) {
		out << obj.data;
		return out;
	}
	friend bool operator==(const TObject & lhs, const TObject & rhs) {
		if (lhs.data == rhs.data)
			return true;
		return false;
	}



private:
	int data;
};