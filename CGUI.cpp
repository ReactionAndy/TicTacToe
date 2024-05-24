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
		m_pApp->draw(m_texts[i]->getText());
		m_pApp->draw(m_texts[i]->getRect());
	}
}

void CGUI::createText(TEXT_TYPE type, std::string text, sf::Vector2f pos, float charSize)
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
		p->setCharacterSize(charSize);
		p->setText(text);
		p->setPos(sf::Vector2f(pos.x + m_pos.x, pos.y + m_pos.y));

		if (isOutofScope(sf::Vector2f(p->getRect().getPosition().x + p->getRect().getSize().x, pos.y + (charSize))))
		{
			std::cout << "TEXT IS OUTOFSCOPE";
			delete p;
			p = 0;
			return;
		}
		m_texts.push_back(p);
	}
	else
	{
		std::cout << "TEXT FAILED TO INIZILIE\n";
		delete p;
		p = 0;
	}
}

bool CGUI::isOutofScope(sf::Vector2f pos)
{
	if (pos.x >= m_pos.x + m_size.x)
		return true;
	else if (pos.y >= m_pos.y + m_size.y)
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

void IText::setText(std::string txt)
{
	m_text.setString(txt);

	m_rect.setSize(sf::Vector2f(m_text.getGlobalBounds().width, m_text.getGlobalBounds().height));
}

void IText::setPos(sf::Vector2f pos)
{
	m_text.setPosition(pos);
	m_originalPos = pos;
	m_rect.setPosition(sf::Vector2f(pos.x, pos.y + (m_text.getCharacterSize() - m_text.getGlobalBounds().getSize().y + 1)));
}

void IText::setCharacterSize(float size)
{
	m_text.setCharacterSize(size);
}

CTitle::CTitle()
{
	std::cout << "CTitle Created\n";
	m_text.setStyle(sf::Text::Bold);
	m_text.setFillColor(sf::Color::White);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(1);

	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Green);
	m_rect.setOutlineThickness(1);
}

CTitle::~CTitle()
{
	std::cout << "CTitle Destroyed\n";
}

CText::CText()
{
	std::cout << "CText Created\n";
	m_text.setFillColor(sf::Color::White);
	m_text.setOutlineColor(sf::Color::Black);
	m_text.setOutlineThickness(1);

	m_rect.setFillColor(sf::Color::Transparent);
	m_rect.setOutlineColor(sf::Color::Green);
	m_rect.setOutlineThickness(1);
}

CText::~CText()
{
	std::cout << "CText Destroyed\n";
}
