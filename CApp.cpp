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
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		else
			m_pGame->input();
	}
}
