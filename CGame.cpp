#include "CGame.h"
#include <iostream>
#include <algorithm>

CGame::CGame(CApp* pApp) : m_pApp(pApp), m_playerIsX(true), m_game_state(GAME_STATE::NONE), m_board{
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0} }
{
	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(100, 100), sf::Vector2f(50, 50)));
	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(200, 100), sf::Vector2f(50, 50)));
	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(300, 100), sf::Vector2f(50, 50)));

	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(100, 200), sf::Vector2f(50, 50)));
	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(200, 200), sf::Vector2f(50, 50)));
	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(300, 200), sf::Vector2f(50, 50)));

	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(100, 300), sf::Vector2f(50, 50)));
	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(200, 300), sf::Vector2f(50, 50)));
	m_pEntities.push_back(createEntity(ENTITY_TYPE::EMPTY, sf::Vector2f(300, 300), sf::Vector2f(50, 50)));

}

CGame::~CGame()
{
	for (unsigned int i = 0; i < m_pEntities.size(); i++)
	{
		std::cout << "index: " << i << ": ";
		delete m_pEntities[i];
		m_pEntities[i] = 0;
	}
	m_pEntities.clear();
}

void CGame::checkMouseInput(sf::Vector2i mouse_pos)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		int index = isBoxClicked(mouse_pos);
		if (index)
		{
			std::cout << index << " BOX CLICKED\n";
			if (!isBoxTaken(index - 1))
			{
				switchBox(index - 1);
			}
		}
	}
}

void CGame::run()
{
	for (unsigned int i = 0; i < m_pEntities.size(); i++)
	{
		m_pApp->draw(m_pEntities[i]->getShape());
	}
	isGameWon();
}

bool CGame::isGameWon()
{
	if (didPlayerThisWin(1))
	{
		m_game_state = GAME_STATE::WIN_X;
		return true;
	}
	else if (didPlayerThisWin(2))
	{
		m_game_state = GAME_STATE::WIN_O;
		return true;
	}
	return false;
}

IEntity* CGame::createEntity(const ENTITY_TYPE Entity_Type, const sf::Vector2f pos, const sf::Vector2f size)
{
	IEntity* entity = NULL;

	switch (Entity_Type)
	{
	case EMPTY:
		entity = new CEmpty();
		entity->getShape().setPosition(pos);
		entity->getShape().setSize(size);
		break;
	case CROSS:
		entity = new CCross();
		entity->getShape().setPosition(pos);
		entity->getShape().setSize(size);
		break;
	case CIRCLE:
		entity = new CCircle();
		entity->getShape().setPosition(pos);
		entity->getShape().setSize(size);
		break;
	default:
		break;
	}


	return entity;
}

int CGame::isBoxClicked(sf::Vector2i mouse_pos)
{
	for (unsigned int i = 0; i < m_pEntities.size(); i++)
	{
		sf::Vector2f entityPos = m_pEntities[i]->getShape().getPosition();
		sf::Vector2f entitySize = m_pEntities[i]->getShape().getSize();
		if (mouse_pos.x > entityPos.x && mouse_pos.x < entityPos.x + entitySize.x)
			if (mouse_pos.y > entityPos.y && mouse_pos.y < entityPos.y + entitySize.y)
				return i + 1; // + 1 for indexing starting at 0 would cause 0 to be returned
	}
	int tempX = 0;
	for (unsigned int i = 0; i < 9; i++)
	{
		tempX++;
		if (i >= 6)
			std::cout << m_board[2][i - 6];
		else if (i >= 3)
			std::cout << m_board[1][i - 3];
		else
			std::cout << m_board[0][i];
		if (tempX == 3)
		{
			tempX = 0;
			std::cout << '\n';
		}
	}
	return 0;
}

bool CGame::isBoxTaken(int index)
{
	if (m_pEntities[index]->getType() == ENTITY_TYPE::CROSS || m_pEntities[index]->getType() == ENTITY_TYPE::CIRCLE)
		return true;
	return false;
}

void CGame::switchBox(int index)
{
	if (m_playerIsX)
	{ 
		m_pEntities.push_back(createEntity(ENTITY_TYPE::CROSS, m_pEntities[index]->getShape().getPosition(), m_pEntities[index]->getShape().getSize()));
		if (index >= 6)
			m_board[2][index - 6] = 1;
		else if (index >= 3)
			m_board[1][index - 3] = 1;
		else
			m_board[0][index] = 1;
	}
	else
	{
		m_pEntities.push_back(createEntity(ENTITY_TYPE::CIRCLE, m_pEntities[index]->getShape().getPosition(), m_pEntities[index]->getShape().getSize()));
		if (index >= 6)
			m_board[2][index - 6] = 2;
		else if (index >= 3)
			m_board[1][index - 3] = 2;
		else
			m_board[0][index] = 2;
	}
	std::iter_swap(m_pEntities.begin() + index, m_pEntities.begin() + (m_pEntities.size() - 1));
	destroyLastElement();
	switchPlayer();
}

void CGame::destroyLastElement()
{
	delete m_pEntities[m_pEntities.size() - 1];
	m_pEntities[m_pEntities.size() - 1] = 0;
	m_pEntities.pop_back();
}

bool CGame::didPlayerThisWin(int x)
{
	if (m_board[0][0] == x && m_board[0][1] == x && m_board[0][2] == x)
		return true;
	else if (m_board[1][0] == x && m_board[1][1] == x && m_board[1][2] == x)
		return true;
	else if (m_board[2][0] == x && m_board[2][1] == x && m_board[2][2] == x)
		return true;
	else if (m_board[0][0] == x && m_board[1][0] == x && m_board[2][0] == x)
		return true;
	else if (m_board[0][1] == x && m_board[1][1] == x && m_board[2][1] == x)
		return true;
	else if (m_board[0][2] == x && m_board[1][2] == x && m_board[2][2] == x)
		return true;
	else if (m_board[0][0] == x && m_board[1][1] == x && m_board[2][2] == x)
		return true;
	else if (m_board[0][2] == x && m_board[1][1] == x && m_board[2][0] == x)
		return true;
	return false;
}

/*#include "CGame.h"
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
	std::cout << "Current Player: " << m_player.getChar();
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
	std::cout << "Choice (1-9) (10 = pause):";
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
		system("PAUSE");
		return true;
		break;
	case WINNER_O:
		system("CLS");
		std::cout << "Player O has Won the game\n";
		system("PAUSE");
		return true;
		break;
	case WINNER_NONE:
		system("CLS");
		std::cout << "Game has been delcared a Draw\n";
		system("PAUSE");
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

*/