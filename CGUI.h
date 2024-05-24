#pragma once
#include <SFML/Graphics.hpp>
#include "CApp.h"
#include <vector>
class CApp;

class IText
{
protected:
	sf::Text m_text;
	sf::Font m_font;
public:
	virtual ~IText();

	virtual sf::Text getText() { return m_text; }

	virtual void setFont(std::string fontName);
	virtual void setText(std::string txt) { m_text.setString(txt); }
	virtual void setPos(sf::Vector2f pos) { m_text.setPosition(pos); }
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

	void createText(TEXT_TYPE type, std::string text, sf::Vector2f pos);
private:
	sf::RectangleShape m_shape;
	CApp* m_pApp;
	std::vector<IText*> m_texts;

	sf::Vector2f m_pos, m_size;

	bool isOutsideScope(sf::Text text);
};

