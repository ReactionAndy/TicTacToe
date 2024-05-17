#include "CApp.h"

CApp::CApp()
{
	m_pGame = new CGame();
}

CApp::~CApp()
{
	delete m_pGame;
	m_pGame = 0;
}

void CApp::run()
{
	m_pGame->draw();
	while (!m_pGame->isGameOver())
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		m_pGame->run();
	}
	system("PAUSE");
}
