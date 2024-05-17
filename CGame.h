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
};

class CGame
{
private:
	static const int m_boardMAXSIZE = 9;
	char m_board[9];
	CPlayer m_player;
public:
	CGame();
	~CGame();

	void run();
	bool input();
	void draw();
	bool isSpotTaken(int choice);

	bool isGameWon();
	void isGameDraw();
	bool checkWinpattern(char playerChar);

	bool isGameOver();

	GAME_STATE m_game_state;
};

