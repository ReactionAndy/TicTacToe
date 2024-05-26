#pragma once
#include <SFML/Graphics.hpp>
#include "CGame.h"
#include "CGUI.h"
//#include "CMenu.h"
class CGame; // Forward declaration
class CGUI;

class CApp
{
public:
	CApp();
	~CApp();

	void passApp(CApp* app) { m_pApp = app; }
	std::shared_ptr<CGame> getGame() { return m_pGame; }

	void handleEvent();
	void run();
	void clear() { m_window.clear(sf::Color(150, 75, 200)); }
	void draw(sf::RectangleShape shape) { m_window.draw(shape); }
	void draw(sf::Sprite sprite) { m_window.draw(sprite); }
	void draw(sf::Text text) { m_window.draw(text); }
	void display() { m_window.display(); }

private:
	sf::RenderWindow m_window;
	CApp* m_pApp;
	std::shared_ptr<CGame> m_pGame;

	std::unique_ptr<CGUI> m_pGUI;

	void restartGame();
};

/*class CApp
{
private:
	CApp* m_pApp;
	CGame* m_pGame;
	CMenu m_menu;

	bool m_isRunning;
public:
	CApp();
	~CApp();

	void passApp(CApp& app) { m_pApp = &app; }

	void forceQuit();

	void restartGame();

	void run();
};*/
