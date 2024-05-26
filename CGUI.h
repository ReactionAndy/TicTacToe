#pragma once
#include <SFML/Graphics.hpp>
#include "CApp.h"
#include <vector>
#include <functional>
class CApp;
class CGame;

class IText
{
protected:
	sf::Text m_text;
	sf::Font m_font;
	sf::RectangleShape m_rect;
	sf::Vector2f m_originalPos;
public:
	virtual ~IText();

	virtual const sf::Text getText() const { return m_text; }
	virtual const sf::RectangleShape getRect() const { return m_rect; }

	virtual void setFont(std::string fontName);
	virtual void setText(std::string txt);
	virtual void setPos(sf::Vector2f pos);
	virtual void setCharacterSize(unsigned int size);
private:
};

class CTitle : public IText
{
public:
	CTitle();
	virtual ~CTitle();
private:

};

class CText : public IText
{
public:
	CText();
	virtual ~CText();
private:

};

enum TEXT_TYPE
{
	TITLE, // CTitle
	NORMAL, // CText
};

class CGUI
{
public:
	CGUI(CApp* pApp, sf::Vector2f pos, sf::Vector2f size);
	~CGUI();
	void draw();

	void createText(TEXT_TYPE type, std::string text, sf::Vector2f pos, unsigned int charSize);
private:
	sf::RectangleShape m_shape;
	CApp* m_pApp;
	CGame* m_pGame;
	std::vector<IText*> m_texts;

	sf::Vector2f m_pos, m_size;

	bool isOutofScope(sf::Vector2f pos);
};

