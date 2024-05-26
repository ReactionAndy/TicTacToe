#include "CApp.h"
#include <iostream>
#include <Windows.h>

CApp::CApp() : m_window(sf::VideoMode(800, 600), "TicTacToe"), m_pApp(NULL)
{
	std::cout << "CREATING APP\n";
	m_window.setVerticalSyncEnabled(true);
}

CApp::~CApp()
{
	std::cout << "DESTROYING APP\n";
}

void CApp::handleEvent()
{
	sf::Event evnt;
	while (m_window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			m_window.close();
			break;
		case sf::Event::MouseButtonPressed:
			m_pGame->checkMouseInput(sf::Mouse::getPosition(m_window));
			break;
		default:
			break;
		}
	}
}

void CApp::run()
{
	m_pGame = std::make_shared<CGame>(m_pApp);

	m_pGUI = std::make_unique<CGUI>(m_pApp, sf::Vector2f(0, 0), (sf::Vector2f(400, 200))); // TEMP NUMBERS | App Pointer | Start Pos | Max Size

	m_pGUI->createText(TEXT_TYPE::TITLE, "GUI", sf::Vector2f(0, 0), 36);
	m_pGUI->createText(TEXT_TYPE::NORMAL, "Debug", sf::Vector2f(0, 50), 24);
	m_pGUI->createText(TEXT_TYPE::NORMAL, "Forsen", sf::Vector2f(300, 175), 24);
	while (m_window.isOpen())
	{
		handleEvent();
		clear();
		switch (m_pGame->getGameState())
		{
		case GAME_STATE::NONE:
			m_pGame->run();
			break;
		case GAME_STATE::WIN_O:
			restartGame();
			std::cout << "Player O Won\n";
			break;
		case GAME_STATE::WIN_X:
			restartGame();
			std::cout << "Player X Won\n";
			break;
		case GAME_STATE::DRAW:
			restartGame();
			std::cout << "No Winner Draw\n";
			break;
		case GAME_STATE::PAUSE:
			restartGame();
			break;
		default:
			break;
		}
		m_pGUI->draw();
		display();
	}
}

void CApp::restartGame()
{
	m_pGame.reset();
	m_pGame = std::make_unique<CGame>(m_pApp);
}


/*CApp::CApp() : m_window(sf::VideoMode(800, 600), "TicTacToe"), m_pGame(NULL), m_pApp(NULL), m_isRunning(true)
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
			std::cout << "MENU CHOICE NOT FOUND\n";
			system("PAUSE");
			break;
		}
	}
	system("PAUSE");
}*/
