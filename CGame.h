#pragma once
#include "CPlayer.h"
#include <vector>
#include "CApp.h"

enum GAME_STATE
{
	NONE,
	WINNER_X,
	WINNER_O,
	WINNER_NONE,
	DEBUG,
	FORCE_QUIT,
};

class CApp;

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

	const bool isGameWon();
	void isGameDraw();
	bool checkWinpattern(char playerChar);
public:
	CGame(CApp* pApp);
	~CGame();

	void run();

	const bool isGameOver();
};
