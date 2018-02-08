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
			Assert::AreEqual(listTable[0], 0, L"at 0");
			Assert::AreEqual(listTable[1], 1, L"at 1");
			Assert::AreEqual(listTable[2], 2, L"at 2");
			Assert::AreEqual(listTable[3], 3, L"at 3");
			Assert::AreEqual(listTable[4], 4, L"at 4");
			Assert::AreEqual(listTable[5], 5, L"at 5");

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



	};
}