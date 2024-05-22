#include "IEntity.h"
#include <iostream>

IEntity::~IEntity()
{
	std::cout << "DESTROYING ENTITY\n";
}

CEmpty::CEmpty()
{
	m_entity_type = ENTITY_TYPE::EMPTY;
	std::cout << "CREATING EMPTY\n";
	
	if (!m_texture.loadFromFile("resources/empty.png"))
	{
		std::cout << "FAILED TO LOAD FILE " << "resources/empty.png\n";
	}
	else
		m_shape.setTexture(&m_texture);
}

CEmpty::~CEmpty()
{
	//std::cout << "DESTROYING EMPTY\n";
}

CCross::CCross()
{
	m_entity_type = ENTITY_TYPE::CROSS;
	std::cout << "CREATING CROSS\n";

	if (!m_texture.loadFromFile("resources/cross.png"))
	{
		std::cout << "FAILED TO LOAD FILE " << "resources/cross.png\n";
	}
	else
		m_shape.setTexture(&m_texture);
}

CCross::~CCross()
{
	std::cout << "DESTROYING CROSS\n";
}

CCircle::CCircle()
{
	m_entity_type = ENTITY_TYPE::CIRCLE;
	std::cout << "CREATING CIRCLE\n";

	if (!m_texture.loadFromFile("resources/circle.png"))
	{
		std::cout << "FAILED TO LOAD FILE " << "resources/circle.png\n";
	}
	else
		m_shape.setTexture(&m_texture);
}

CCircle::~CCircle()
{
	std::cout << "DESTROYING CIRCLE\n";
}

