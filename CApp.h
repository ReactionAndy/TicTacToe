#pragma once
#include "CGame.h"
#include "CMenu.h"

class CGame; // Forward declaration

class CApp
{
private:
	CApp* m_pApp;
	CGame* m_pGame;
	CMenu m_menu;

	bool m_isRunning;
public:
	CApp();
	~CApp();

	void passApp(CApp& app) { m_pApp = &app; }

	void forceQuit();

	void restartGame();

	void run();
};
