#include "CGame.h"
#include <iostream>
#include "helper.h"

CGame::CGame() : m_player(true), m_game_state(GAME_STATE::NONE),
	m_board{
	'.', '.', '.', 
	'.', '.', '.', 
	'.', '.', '.' }
{
}

CGame::~CGame()
{
}

void CGame::run()
{
	input();
	if (!isGameWon())
		isGameDraw();
	draw();
}

bool CGame::input()
{
	std::cout << "Choice (1-9):";
	int choice;
	std::cin >> choice;
	switch (choice)
	{
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
	default:
		return false;
		break;
	}
	return false;
}

void CGame::draw()
{
	system("CLS");
	int tempVal = 1;

	gotoxy(0, 0);

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

bool CGame::isSpotTaken(int choice)
{
	if (m_board[choice] == 'X' || m_board[choice] == 'O')
	{
		return true;
	}
	return false ;
}

bool CGame::isGameWon()
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
	return false;
}

void CGame::isGameDraw()
{
	for (size_t i = 0; i < m_boardMAXSIZE; i++)
	{
		if (m_board[i] == '.')
			return;
	}
	std::cout << "GAME DRAW";
	m_game_state = GAME_STATE::WINNER_NONE;
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

bool CGame::isGameOver()
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
	default:
		return  false;
		break;
	}
	return false;
}

