#pragma once
#include "CGame.h"
#include "CMenu.h"

class CGame;

class CApp
{
private:
	CGame* m_pGame;
	CApp* m_pApp;
	CMenu* m_pMenu;

	bool m_isPaused;
public:
	CApp();
	~CApp();

	void pauseGame();

	void passApp(CApp& App) { m_pApp = &App; } // passing app reference into class

	void test();

	void run();
};

