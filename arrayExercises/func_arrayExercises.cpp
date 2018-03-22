
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string.h>
#include "func_arrayExercises.h"




// fill array
void setList(std::vector<int> &list, int listSize) {
	int num, count;
	
	std::cout << "enter " << listSize << " integer: " << std::endl;;
	
	for (int row = 0; row < listSize; row++) {
		std::cout << "[" << row << "]";
		std::cin >> num;
		list.push_back(num);
	}
	count = 0;
	
}

// display list
void dispList(std::vector<int> &list) {
	for (unsigned int row = 0; row < list.size(); row++) {
		std::cout << list[row] << " ";
	}
}

/*a function, remove, that takes three parameters: an array of integers,
the number of elements in the array, and an integer (say, removeItem). The
function should find and delete the first occurrence of removeItem in the
array. If the value does not exist or the array is empty, output an appropriate
message. (Note that after deleting the element, the number of elements in
the array is reduced by 1.) Assume that the array is unsorted.*/

void remove(std::vector<int> &list, int removeItem) {
	int loc, temp, finder;
	bool found;

	found = false;
	finder = 0;

	// find removeItem
	// get location of removeItem
	while (!found && finder < list.size()) {		
		if (list[finder] == removeItem) { // if found then delete from the list
			loc = finder;
			found = true;
			// shift elements
			for (int row = loc; row < list.size() - 1; row++) {
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
		std::cout << "integer " << removeItem << " not in the list" << std::endl;
	}	
}

/*removeAt, that takes three parameters: an array of
integers, the number of elements in the array, and an integer (say,
index). The function should delete the array element indicated by
index. If index is out of range or the array is empty, output an appropriate
message. (Note that after deleting the element, the number of elements in
the array is reduced by 1.) Assume that the array is unsorted.*/

void removeAtLoc(std::vector<int> &listTable, int loc) {

	// if location is found then delete the element at location
	if (loc > 0 && loc <= listTable.size()) {
		// shift elements
		for (int row = loc; row < listTable.size() - 1; row++) {
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

void removeAllOccur(std::vector<int> &listTable, int removeItem) {	
	int loc, shift;
	bool found = false;

	loc = 0;
	shift = 0;
	for (unsigned int search = 0; search < listTable.size() - 1; search++) { // search whole list				
		//search for removeItem
		while (removeItem == listTable[search] && search != listTable.size()) {
			// shift elements
			for (unsigned int loc = search; loc < listTable.size() - 1; loc++) {
				listTable[loc] = listTable[loc + 1];
			}
			// set the removeItem element to 0
			shift++;
			listTable[listTable.size() - shift] = 0;
			found = true;
		}
	}
	// delete the remove item from the list
	for (int row = 0; row < shift; row++) {
		listTable.pop_back();
	}
	
	

	// error message if value does not exist
	if (!found) {
		std::cout << std::endl;
		std::cout << "the value is not in the list....";
	}

	// display list after remove
	std::cout << std::endl;
	std::cout << "list after remove: ";
	for (unsigned int row = 0; row < listTable.size(); row++) {
		std::cout << listTable[row] << " ";
	}
}