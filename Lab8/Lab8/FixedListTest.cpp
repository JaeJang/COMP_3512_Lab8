#include "FixedLIst.hpp"
#include <iostream>

constexpr size_t SIZE = 10;

int main() {
	using namespace std;

	FixedList<int, SIZE> list;

	for (int i = 0; i < SIZE - 2; ++i) {
		list.add(i);
	}

	cout << list.size() << endl;
	cout << list.capacity() << endl;
	cout << list.get(3) << endl;
	cout << list.getFirstIndex(2) << endl;
	//list[5];
	system("PAUSE");
	

}