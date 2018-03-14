#include "stdafx.h"
#include "CppUnitTest.h"
#include "../arrayExercises/header_arrayExercises.h"

#include <vector>
#include <iostream>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1_arrayExercises
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
	
		/*a function, remove, that takes three parameters: an array of integers,
		the number of elements in the array, and an integer (say, removeItem). The
		function should find and delete the first occurrence of removeItem in the
		array. If the value does not exist or the array is empty, output an appropriate
		message. (Note that after deleting the element, the number of elements in
		the array is reduced by 1.) Assume that the array is unsorted.*/

		TEST_METHOD(removeItem_check) {
			std::vector<int> listTable(1);
			int removeItem, lastElem, temp, loc;
			int size;
			bool found;

			found = false;
			removeItem = 2;

			// fill list
			for (int row = 0; row < 5; row++) {
				listTable.push_back(row + 1);			
			}
			Assert::AreEqual(listTable[0], 0, L"at 0 value is 0");
			Assert::AreEqual(listTable[1], 1, L"at 1 value is 1");
			Assert::AreEqual(listTable[2], 2, L"at 2 value is 2");
			Assert::AreEqual(listTable[3], 3, L"at 3 value is 3");
			Assert::AreEqual(listTable[4], 4, L"at 4 value is 4");
			Assert::AreEqual(listTable[5], 5, L"at 5 value is 5");

			// get location of removeItem
			loc = 0;
			for (unsigned int row = 0; row < listTable.size(); row++) {
				if (listTable[row] == removeItem) {
					loc = row;
					found = true;
					Assert::AreEqual(loc, 2, L"wrong location");
				}
			}
			
			// copy the element equivalent to removeItem to temp
			temp = listTable[loc];
			
			size = listTable.size();
			Assert::AreEqual(size, 6, L"wrong size");

			// shift elements from removeItem location
			for ( int row = loc; row < 5; row++) {
				listTable[row] = listTable[row + 1];
			}
			Assert::AreEqual(listTable[3], 4, L"at 3");
			Assert::AreEqual(listTable[4], 5, L"at 4");
			Assert::AreEqual(listTable[5], 5, L"at 5");

			// remove the last element
			listTable.pop_back();
			
			Assert::AreEqual(listTable[3], 4);
			Assert::AreEqual(listTable[4], 5);
			size = listTable.size();			

			if (!found) {
				Logger::WriteMessage("item not in the list");
			}
			
		}


		/*removeAt, that takes three parameters: an array of
		integers, the number of elements in the array, and an integer (say,
		index). The function should delete the array element indicated by
		index. If index is out of range or the array is empty, output an appropriate
		message. (Note that after deleting the element, the number of elements in
		the array is reduced by 1.) Assume that the array is unsorted.*/

		TEST_METHOD(removeItemAtLoc_check) {
			std::vector<int> listTable;
			int listSize, loc;
			
			listSize = 5;

			// fill array
			for (unsigned int row = 0; row < listSize; row++) {
				listTable.push_back(row + 2);
			}

			Logger::WriteMessage("Checking elements in the list");
			// check list
			Assert::AreEqual(listTable[0], 2, L"at 0 value is 2");
			Assert::AreEqual(listTable[1], 3, L"at 1 value is 3");
			Assert::AreEqual(listTable[2], 4, L"at 2 value is 4");
			Assert::AreEqual(listTable[3], 5, L"at 3 value is 5");
			Assert::AreEqual(listTable[4], 6, L"at 4 value is 6");

			// get location
			loc = 1;

			if (loc > 0 && loc <= listSize) {
				// if location is found then delete the element at location
				// shift elements
				for (int row = loc; row < listSize - 1; row++) {
					listTable[row] = listTable[row + 1];
				}

				// delete last element
				listTable.pop_back();

				Logger::WriteMessage("Checking elements in the list after pop back");
				Assert::AreEqual(listTable[0], 2, L"at 0 value is 2");
				Assert::AreEqual(listTable[1], 4, L"at 1 value is 3");
				Assert::AreEqual(listTable[2], 5, L"at 2 value is 4");
				Assert::AreEqual(listTable[3], 6, L"at 3 value is 5");
				//Assert::AreEqual(listTable[4], 6, L"at 4 value is 6");

			}
			else {
				Logger::WriteMessage("Location not found!!!");
			
			}
			
		}


		/*removeAll, that takes three parameters: an array of integers,
		the number of elements in the array, and an integer (say, removeItem). The
		function should find and delete all of the occurrences of removeItem in the
		array. If the value does not exist or the array is empty, output an appropriate
		message. (Note that after deleting the element, the number of elements in the
		array is reduced.) Assume that the array is unsorted.*/

		TEST_METHOD(removeAllOccur_check) {			
			std::vector<int> listTable;
			int listSize, removeItem, finder, loc;
			bool found = false;
			
			// set array size
			listSize = 5;

			// fill list
			listTable.push_back(2);
			listTable.push_back(3);
			listTable.push_back(56);
			listTable.push_back(3);
			listTable.push_back(7);

			// check list
			Logger::WriteMessage("checking list at removeAllOccur");
			Assert::AreEqual(listTable[0], 2, L"at [0]");
			Assert::AreEqual(listTable[1], 3, L"at [1]");
			Assert::AreEqual(listTable[2], 56, L"at [2]");
			Assert::AreEqual(listTable[3], 3, L"at [3]");
			Assert::AreEqual(listTable[4], 7, L"at [4]");

			// set removeItem
			removeItem = 3;
			
			finder = 0;
			loc = 0;
			while (finder < listTable.size()) {
				if (removeItem == listTable[finder]) {
					loc = finder;
					found = true;
					// remove all occurrences of removeItem
					// shift elements					
					for (unsigned int row = loc; row < listTable.size() - 1; row++) {
						listTable[row] = listTable[row + 1];
					}
					// delete last element
					listTable.pop_back();
				}
				finder++;
				
			}

			// error message if value does not exist
			if (!found) {
				Logger::WriteMessage("the value is not in the list....");
			}
			else {
				Logger::WriteMessage("checking list after remove");
				Assert::AreEqual(listTable[0], 2, L"at [0]");
				Assert::AreEqual(listTable[1], 56, L"at [1]");
				Assert::AreEqual(listTable[2], 7, L"at [2]");
			}
			

		}


		//------ END OF TEST CLASS --------------
	};
}