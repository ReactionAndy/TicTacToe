/*#include "CMenu.h"
#include <iostream>

void CMenu::draw()
{
	system("CLS");
	std::cout << "Menu:\n"
		<< "Resume (1)\n"
		<< "Restart (2)\n"
		<< "Exit (3)\n\n"
		<< "Choice: ";
}

int CMenu::input()
{
	int choice = 0;
	std::cin >> choice;
	return choice;
}

CMenu::CMenu()
{
	std::cout << "CREATING MENU\n";
}

CMenu::~CMenu()
{
	std::cout << "DESTROYING MENU\n";
}

MENU_CHOICE CMenu::run()
{
	while (true)
	{
		draw();
		switch (input())
		{
		case 1:
			return MENU_CHOICE::RESUME;
			break;
		case 2:
			return MENU_CHOICE::RESTART;
			break;
		case 3:
			return MENU_CHOICE::EXIT;
		default:
			break;
		}
	}
}
*/