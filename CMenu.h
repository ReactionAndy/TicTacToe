#pragma once
enum MENU_CHOICE
{
	RESUME,
	RESTART,
	EXIT,
};

class CMenu
{
private:
	void draw();
	int input();
public:
	CMenu();
	~CMenu();

	MENU_CHOICE run();
};

