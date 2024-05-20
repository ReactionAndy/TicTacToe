#include "CApp.h"
#include <iostream>
#include <Windows.h>

CApp::CApp() : m_pGame(NULL), m_pApp(NULL), m_isPaused(false)
{
	std::cout << "CREATING APP\n";
}

CApp::~CApp()
{
	std::cout << "DESTROYING APP\n";
	delete m_pGame;
	m_pGame = 0;
}

void CApp::pauseGame()
{
	m_isPaused = true;
}

void CApp::test()
{
	std::cout << "App\n";
}

void CApp::run()
{
	m_pGame = new CGame(m_pApp);
	while (true)
	{
		while (!m_pGame->isGameOver() && m_isPaused == false)
		{
			m_pGame->run();
		}
		m_isPaused = true;
		while (m_isPaused)
		{

		}
	}


	system("PAUSE");
}
