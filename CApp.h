#pragma once
#include "CGame.h"
class CApp
{
private:
	CGame* m_pGame;
public:
	CApp();
	~CApp();

	void run();
};

