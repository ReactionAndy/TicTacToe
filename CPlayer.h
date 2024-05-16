#pragma once
class CPlayer
{
private:
	bool m_isX;
public:
	CPlayer(const bool isX);
	~CPlayer();

	const char getChar() { if (m_isX) return 'X'; else return 'O'; }
	const char getReverseChar() { if (m_isX) return 'O'; else return 'X'; }
	const bool getIsX() { return m_isX; }
	void switchPlayer() { m_isX = !m_isX; }
};

