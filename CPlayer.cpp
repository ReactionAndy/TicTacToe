#include "CPlayer.h"
#include <iostream>

CPlayer::CPlayer(const bool isX) : m_isX(isX)
{
	std::cout << "PLAYER CREATED\n";
}

CPlayer::~CPlayer()
{
	std::cout << "PLAYER DESTROYED\n";
}
