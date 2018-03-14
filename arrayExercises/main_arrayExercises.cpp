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
	std::vector<int> main_list;

	//remove(main_list, 6, 14);
	std::cout << std::endl;
	std::cout << std::endl;

	removeAt(main_list, 6, 8);
	std::cout << std::endl;
	removeAllOccur(main_list, 5, 3);


	std::cout << std::endl;
	std::cout << "continue--->";
	std::cin >> cont;
    return 0;
}

