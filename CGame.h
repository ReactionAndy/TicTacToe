#pragma once
#include "CPlayer.h"
#include <Windows.h>
#include <iostream>
#include <vector>

enum GAME_STATE
{
	NONE,
	WINNER_X,
	WINNER_O,
	WINNER_NONE,
	DEBUG,
	FORCE_QUIT,
};

class CGame
{
private:
	static const int m_boardMAXSIZE = 9;
	char m_board[9];
	CPlayer m_player;
	GAME_STATE m_game_state;

	void draw();

	bool input();
	bool isSpotTaken(int choice);

	bool isGameWon();
	void isGameDraw();
	bool checkWinpattern(char playerChar);
public:
	CGame();
	~CGame();

	void run();

	bool isGameOver();

	void setGameState(GAME_STATE state) { m_game_state == state; }

};

