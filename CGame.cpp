#include "CGame.h"
#include <iostream>
#include "helper.h"

CGame::CGame(CApp* pApp) : m_pApp(pApp), m_player(true), m_game_state(GAME_STATE::NONE),
	m_board{
	'.', '.', '.', 
	'.', '.', '.', 
	'.', '.', '.' }
{
	std::cout << "GAME CREATED\n";
	m_game_state = GAME_STATE::NONE;
}

CGame::~CGame()
{
	std::cout << "GAME DESTROYED\n";
}

void CGame::resumeGame()
{
	m_game_state = GAME_STATE::NONE;
}

void CGame::draw()
{
	system("CLS");
	for (unsigned int i = 0; i < m_boardMAXSIZE; i++)
	{
		if (i % 3 == 0)
		{
			std::cout << std::endl;
		}
		std::cout << m_board[i];
	}
	gotoxy(0, 6);
}

bool CGame::input()
{
	std::cout << "Choice (1-9) (0 = exit) (10 = pause):";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 0:
		m_game_state = GAME_STATE::FORCE_QUIT;
		break;
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		if (!isSpotTaken(choice - 1))
		{
			m_board[choice - 1] = m_player.getChar();
			m_player.switchPlayer();
			return true;
		}
		break;
	case 10:
		m_game_state = GAME_STATE::PAUSE;
		return true;
		break;
	default:
		return false;
		break;
	}
	return false;
}

bool CGame::isSpotTaken(int choice)
{
	if (m_board[choice] == 'X' || m_board[choice] == 'O')
	{
		return true;
	}
	return false ;
}

const bool CGame::update()
{
	if (checkWinpattern('X'))
	{
		m_game_state = GAME_STATE::WINNER_X;
		std::cout << "GAME WON [X]";
		return true;
	}
	else if (checkWinpattern('O'))
	{
		m_game_state = GAME_STATE::WINNER_O;
		std::cout << "GAME WON [O]";
		return true;
	}
	for (size_t i = 0; i < m_boardMAXSIZE; i++) // Draw
	{
		if (m_board[i] == '.')
			return false;
	}
	std::cout << "GAME DRAW";
	m_game_state = GAME_STATE::WINNER_NONE;
	return true;
}

bool CGame::checkWinpattern(char playerChar)
{
	if (m_board[0] == playerChar && m_board[1] == playerChar && m_board[2] == playerChar)
		return true;
	else if (m_board[3] == playerChar && m_board[4] == playerChar && m_board[5] == playerChar)
		return true;
	else if (m_board[6] == playerChar && m_board[7] == playerChar && m_board[8] == playerChar)
		return true;

	else if (m_board[0] == playerChar && m_board[3] == playerChar && m_board[6] == playerChar)
		return true;
	else if (m_board[1] == playerChar && m_board[4] == playerChar && m_board[7] == playerChar)
		return true;
	else if (m_board[2] == playerChar && m_board[5] == playerChar && m_board[8] == playerChar)
		return true;

	else if (m_board[0] == playerChar && m_board[4] == playerChar && m_board[8] == playerChar)
		return true;
	else if (m_board[2] == playerChar && m_board[4] == playerChar && m_board[6] == playerChar)
		return true;
	return false;
}

void CGame::run()
{
	while (!isGameOver())
	{
		draw();
		input();
		update();
	}
}

const bool CGame::isGameOver()
{
	switch (m_game_state)
	{
	case NONE:
		return false;
		break;
	case WINNER_X:
		system("CLS");
		std::cout << "Player X has Won the game\n";
		return true;
		break;
	case WINNER_O:
		system("CLS");
		std::cout << "Player O has Won the game\n";
		return true;
		break;
	case WINNER_NONE:
		system("CLS");
		std::cout << "Game has been delcared a Draw\n";
		return true;
		break;
	case DEBUG:
		break;
	case FORCE_QUIT:
		system("CLS");
		std::cout << "FORCE EXITED GAME\n";
		m_pApp->forceQuit();
		return true;
		break;
	case PAUSE:
		system("CLS");
		std::cout << "PAUSED GAME\n";
		return true;
	default:
		return  false;
		break;
	}
	return false;
}

