#pragma once
#include <vector>
#include "CApp.h"
#include "IEntity.h"
class CApp; // Forward declaration

class CGame
{
public:
	CGame(CApp* pApp);
	~CGame();

	void checkMouseInput(sf::Vector2i mouse_pos);

	void run();

	bool isGameWon();

private:
	CApp* m_pApp;

	int m_board[3][3];

	std::vector<IEntity*> m_pEntities;

	IEntity* createEntity(const ENTITY_TYPE Entity_Type, const sf::Vector2f pos, const sf::Vector2f size);

	int isBoxClicked(sf::Vector2i mouse_pos);
	bool isBoxTaken(int index);
	void switchBox(int index);

	void destroyLastElement();

	bool m_playerIsX;
	void switchPlayer() { m_playerIsX = !m_playerIsX; }

	bool didPlayerThisWin(int x);
};

/*#pragma once
#include "CPlayer.h"
#include <vector>
#include "CApp.h"

class CApp; // Forward declaration

enum GAME_STATE
{
	NONE,
	WINNER_X,
	WINNER_O,
	WINNER_NONE,
	DEBUG,
	FORCE_QUIT,
	PAUSE,
};

class CGame
{
private:
	CApp* m_pApp;

	static const int m_boardMAXSIZE = 9;
	char m_board[9];
	CPlayer m_player;
	GAME_STATE m_game_state;

	void draw();

	bool input();
	bool isSpotTaken(int choice);

	const bool update();
	bool checkWinpattern(char playerChar);
public:
	CGame(CApp* pApp);
	~CGame();

	void resumeGame();

	void run();

	const bool isGameOver();
};
*/