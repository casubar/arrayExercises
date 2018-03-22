// arrayExercises.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string.h>

#include "header_arrayExercises.h"

int main()
{
	char cont;
	int choyz, removeItem, loc;
	std::vector<int> main_list;

	

	do {
		setList(main_list, 5);

		std::cout << "---M E N U---" << std::endl;
		std::cout << "(1) remove" << std::endl;
		std::cout << "(2) remove at location" << std::endl;
		std::cout << "(3) remove all occurence" << std::endl;
		std::cout << "Your choice? --> ";
		std::cin >> choyz;

		switch (choyz) {
		case 1: {			
			std::cout << "integer to remove: ";
			std::cin >> removeItem;
			remove(main_list, removeItem);
			break;
		}
		case 2: {
			std::cout << "location of integer:";
			std::cin >> loc;
			removeAtLoc(main_list, loc);

			break;
		}
		case 3: {
			std::cout << "integer to remove: ";
			std::cin >> removeItem;
			removeAllOccur(main_list, removeItem);
			
			break;
		}
		default: {
			break;
			std::cout << "Invalid....Exiting app!";
			std::cin >> cont;
			return 0;

		}
			
		}


		std::cout << std::endl;
		std::cout << "Press 'Y' to continue--->";
		std::cin >> cont;
	} while (cont == 'Y' || cont == 'y');



	
    return 0;
}

