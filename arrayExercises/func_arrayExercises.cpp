
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string.h>
#include "func_arrayExercises.h"


/*a function, remove, that takes three parameters: an array of integers,
the number of elements in the array, and an integer (say, removeItem). The
function should find and delete the first occurrence of removeItem in the
array. If the value does not exist or the array is empty, output an appropriate
message. (Note that after deleting the element, the number of elements in
the array is reduced by 1.) Assume that the array is unsorted.*/

void remove(std::vector<int> &list, int listSize, int removeItem) {
	int loc, temp, finder;
	bool found;

	found = false;
	
	// fill list
	for (int row = 0; row < listSize; row++) {
		list.push_back(row * 3 + 5);
	}
	// display full list
	for (unsigned int row = 0; row < list.size(); row++) {
		std::cout << list[row] << "-";
	}

	finder = 0;
	// find removeItem
	while (!found && finder < list.size()) {		
		if (list[finder] == removeItem) { // if found then delete from the list
			loc = finder;
			found = true;
			// shift elements
			for (int row = loc; row < listSize - 1; row++) {
				list[row] = list[row + 1];
			}
			// delete last element
			list.pop_back();
			
			std::cout << std::endl;
			// display edited list
			for (unsigned int row = 0; row < list.size(); row++) {
				std::cout << list[row] << "-";
			}
		}
		finder++;
	}

	if (!found) {
		std::cout << std::endl;
		std::cout << "Item not in the list" << std::endl;
	}	
}

/*removeAt, that takes three parameters: an array of
integers, the number of elements in the array, and an integer (say,
index). The function should delete the array element indicated by
index. If index is out of range or the array is empty, output an appropriate
message. (Note that after deleting the element, the number of elements in
the array is reduced by 1.) Assume that the array is unsorted.*/

void removeAt(std::vector<int> &listTable, int listSize, int loc) {
	// fill array
	for (int row = 0; row < listSize; row++) {
		listTable.push_back(row + 2);
	}

	// display list
	for (unsigned int row = 0; row < listTable.size(); row++) {
		std::cout << listTable[row] << " ";
	}

	
	// if location is found then delete the element at location
	if ((loc > 0 && loc <= listSize)) {
		// shift elements
		for (int row = loc; row < listSize - 1; row++) {
			listTable[row] = listTable[row + 1];
		}
		// delete last element
		listTable.pop_back();

		// display edited list
		std::cout << std::endl;
		for (unsigned int row = 0; row < listTable.size(); row++) {
			std::cout << listTable[row] << " ";
		}
	}
	else { // display error when location is not found
		std::cout << std::endl;
		std::cout << "Location " << loc << " not found!!!";
	}
	
}



/*removeAll, that takes three parameters: an array of integers,
the number of elements in the array, and an integer (say, removeItem). The
function should find and delete all of the occurrences of removeItem in the
array. If the value does not exist or the array is empty, output an appropriate
message. (Note that after deleting the element, the number of elements in the
array is reduced.) Assume that the array is unsorted.*/

void removeAllOccur(std::vector<int> &listTable, int listSize, int removeItem) {	
	int finder, loc;
	bool found = false;

	// fill list
	listTable.push_back(2);
	listTable.push_back(3);
	listTable.push_back(56);
	listTable.push_back(3);
	listTable.push_back(7);

	// display initial list
	for (unsigned int row = 0; row < listTable.size(); row++) {
		std::cout << listTable[row] << " ";
	}

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
		std::cout << std::endl;
		std::cout << "the value is not in the list....";
	}

	// display list after remove
	std::cout << std::endl;
	for (unsigned int row = 0; row < listTable.size(); row++) {
		std::cout << listTable[row] << " ";
	}
}