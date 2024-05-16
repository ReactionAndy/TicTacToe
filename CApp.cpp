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
	bool keepRunning = true;
	m_pGame->draw();
	while (keepRunning)
	{
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		else if (m_pGame->m_game_state == GAME_STATE::NONE)
		{
			m_pGame->run();
		}
		else
		{
			system("CLS");
			if (m_pGame->m_game_state == GAME_STATE::WINNER_O)
			{
				std::cout << "Player O has Won the game\n";
				keepRunning = false;
			}
			else if (m_pGame->m_game_state == GAME_STATE::WINNER_X)
			{
				std::cout << "Player X has Won the game\n";
				keepRunning = false;
			}
			else if (m_pGame->m_game_state == GAME_STATE::WINNER_NONE)
			{
				std::cout << "Game has been delcared a Draw\n";
				keepRunning = false;
			}
		}

	}
	system("PAUSE");
}
