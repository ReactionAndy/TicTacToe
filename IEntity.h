#pragma once
#include <SFML/Graphics.hpp>
#include <string>

enum ENTITY_TYPE
{
	EMPTY,
	CROSS,
	CIRCLE
};

class IEntity
{
protected:
	sf::RectangleShape m_shape;
	sf::Texture m_texture;
	ENTITY_TYPE m_entity_type;
public:
	virtual sf::RectangleShape& getShape() { return m_shape; }
	ENTITY_TYPE getType() { return m_entity_type; }

	virtual ~IEntity();
private:
};

class CEmpty : public IEntity
{
public:
	CEmpty();
	virtual ~CEmpty();
private:
};

class CCross : public IEntity
{
public:
	CCross();
	virtual ~CCross();

private:
};

class CCircle : public IEntity
{
public:
	CCircle();
	virtual ~CCircle();

private:
};

