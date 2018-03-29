#include "FixedLIst.hpp"
#include "TestObject.hpp"
#include <iostream>

constexpr size_t SIZE = 10;

int main() {
	using namespace std;

	FixedList<TObject, SIZE> list;

	for (size_t i = 0; i < SIZE; ++i) {
		list.add(TObject(i));
	}

	cout << list;
	cout << "size = " << list.size() << endl;
	cout << "capacity = " << list.capacity() << endl;
	cout << "index 2 = " << list[2] << endl;
	TObject temp(11);
	cout << "index 2 removed " << list.remove(temp) << endl;
	cout << "index 2 = " << list[2] << endl;
	cout << "size = " << list.size() << endl;

	system("PAUSE");
	

}