#include "CApp.h"
#include <iostream>
#include <Windows.h>

CApp::CApp() : m_pGame(NULL), m_pApp(NULL), m_isRunning(true)
{
	std::cout << "CREATING APP\n";
}

CApp::~CApp()
{
	std::cout << "DESTROYING APP\n";
	delete m_pGame;
	m_pGame = NULL;
}

void CApp::forceQuit()
{
	std::cout << "FORCE QUITTING APP\n";
	m_isRunning = false;
}

void CApp::restartGame()
{
	delete m_pGame;
	m_pGame = 0;
	m_pGame = new CGame(m_pApp);
	m_isRunning = true;
}

void CApp::run()
{
	m_pGame = new CGame(m_pApp);
	while (m_isRunning)
	{
		m_pGame->run();
		system("PAUSE");
		switch (m_menu.run())
		{
		case MENU_CHOICE::RESUME:
			m_pGame->resumeGame();
			break;
		case MENU_CHOICE::RESTART:
			restartGame();
			break;
		case MENU_CHOICE::EXIT:
			forceQuit();
			break;
		default:
			break;
		}
	}
	system("PAUSE");
}
