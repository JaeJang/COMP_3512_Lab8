#include "../Lab8/FixedLIst.hpp"
#include "../Lab8/TestObject.hpp"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:


		TEST_CLASS_INITIALIZE(methodName)
		{
			
		}
		
		TEST_METHOD(Add)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 9; ++i) {
				list.add(TObject(i));
			}
			Assert::AreEqual(true, list.add(TObject(10)));
		}

		TEST_METHOD(AddException)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 10; ++i) {
				list.add(TObject(i));
			}
			Assert::AreEqual(false, list.add(11));
		}

		TEST_METHOD(Get)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 9; ++i) {
				list.add(TObject(i));
			}
			bool sameOrNot = false;
			TObject temp(1);
			if (temp == list.get(1)) {
				sameOrNot = true;
			}
			Assert::AreEqual(true, sameOrNot);
		}
		TEST_METHOD(GetException)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 9; ++i) {
				list.add(TObject(i));
			}
			bool exception_thrown = false;
			try {
				list.get(11);
			}
			catch (std::invalid_argument & err) {
				exception_thrown = true;
			}

			Assert::AreEqual(true, exception_thrown);
		}

		TEST_METHOD(Remove)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 9; ++i) {
				list.add(TObject(i));
			}
			TObject temp(2);
			int removed = list.remove(temp).getData();
			Assert::AreEqual(2, removed);
		}
		
		TEST_METHOD(nothingRemoved)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 9; ++i) {
				list.add(TObject(i));
			}
			TObject temp(11);
			int removed = list.remove(temp).getData();
			Assert::AreEqual(NULL, removed);
		}

		TEST_METHOD(Size)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 8; ++i) {
				list.add(TObject(i));
			}
			
			Assert::AreEqual((size_t)8, list.size());
		}

		TEST_METHOD(Capacity)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 8; ++i) {
				list.add(TObject(i));
			}

			Assert::AreEqual((size_t)10, list.capacity());
		}

		TEST_METHOD(operatorTest)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 8; ++i) {
				list.add(TObject(i));
			}
			int temp = list[1].getData();

			Assert::AreEqual(1, temp);
		}

		TEST_METHOD(operatorTestException)
		{
			FixedList<TObject, 10> list;
			for (size_t i = 0; i < 8; ++i) {
				list.add(TObject(i));
			}
			bool exception_thrown = false;
			try {
				list[10];
			}
			catch (std::invalid_argument & err) {
				exception_thrown = true;
			}

			Assert::AreEqual(true, exception_thrown);
		}
	};
}