#pragma once
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
