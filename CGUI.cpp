#include "CGUI.h"
#include <iostream>

CGUI::CGUI(CApp* pApp, sf::Vector2f pos, sf::Vector2f size) : m_pApp(pApp), m_pos(pos), m_size(size)
{
	m_shape.setPosition(m_pos);
	m_shape.setSize(m_size);
	m_shape.setFillColor(sf::Color(0, 0, 0, 150));
	m_shape.setOutlineColor(sf::Color(0, 0, 0, 255));
	m_shape.setOutlineThickness(2);
}

CGUI::~CGUI()
{
	for (unsigned int i = 0; i < m_texts.size(); i++)
	{
		delete m_texts[i];
		m_texts[i] = 0;
	}
}

void CGUI::draw()
{
	m_pApp->draw(m_shape);
	for (unsigned int i = 0; i < m_texts.size(); i++)
	{
		if (!isOutsideScope(m_texts[i]->getText()))
		{
			m_pApp->draw(m_texts[i]->getText());
		}
	}
}

void CGUI::createText(TEXT_TYPE type, std::string text, sf::Vector2f pos)
{
	IText* p = NULL;
	switch (type)
	{
	case TITLE:
		p = new CTitle();
		break;
	case NORMAL:
		p = new CText();
		break;
	default:
		break;
	}
	if (p)
	{
		p->setFont("SANTELLO.ttf");
		p->setText(text);
		p->setPos(sf::Vector2f(pos.x + m_pos.x, pos.y + m_pos.y));
		m_texts.push_back(p);
	}
	else
	{
		std::cout << "TEXT FAILED TO INIZILIE\n";
		delete p;
		p = 0;
	}
}

bool CGUI::isOutsideScope(sf::Text text)
{
	if (text.getPosition().x > m_pos.x + m_size.x)
		return true;
	else if (text.getPosition().y > m_pos.x + m_size.y)
		return true;
	return false;
}

IText::~IText()
{
	std::cout << "IText Destroyed\n";
}

void IText::setFont(std::string fontName = "SANTELLO.ttf")
{
	if (!m_font.loadFromFile("resources/fonts/" + fontName))
	{
		std::cout << "FONT FAILED TO LOAD[" << fontName << "]\n";
		system("pause");
	}
	m_text.setFont(m_font);
}

CTitle::CTitle()
{
	std::cout << "CTitle Created\n";
	m_text.setCharacterSize(36);
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::White);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(1);
}

CTitle::~CTitle()
{
	std::cout << "CTitle Destroyed\n";
}

CText::CText()
{
	std::cout << "CText Created\n";
	m_text.setCharacterSize(24);
	m_text.setFillColor(sf::Color::White);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(1);
}

CText::~CText()
{
	std::cout << "CText Destroyed\n";
}
