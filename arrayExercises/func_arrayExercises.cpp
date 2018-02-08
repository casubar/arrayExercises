
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
		// if found then delete from the list
		if (list[finder] == removeItem) {
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