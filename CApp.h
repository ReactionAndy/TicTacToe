#pragma once
#include "CGame.h"

class CGame;

class CApp
{
private:
	CGame* m_pGame;
	CApp* m_pApp;

	bool m_isPaused;
public:
	CApp();
	~CApp();

	void pauseGame();

	void passApp(CApp& App) { m_pApp = &App; } // passing app reference into class

	void test();

	void run();
};

