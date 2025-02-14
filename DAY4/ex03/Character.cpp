#include "Character.hpp"

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		if(amaterias[i])
			delete amaterias[i];
}

Character::Character(void): name("defacto")
{
	for (int i = 0; i < 4; i++)
		amaterias[i] = NULL;
}

Character::Character(const std::string str): name(str)
{
	for (int i = 0; i < 4; i++)
		amaterias[i] = NULL;
}

Character::Character(const Character &obj): name(obj.name)
{
	for (int i = 0; i < 4; i++)
		amaterias[i] = NULL;
	*this = obj;
}

Character	&Character::operator=(const Character &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		for (int i = 0; i < 4; i++)
			if(amaterias[i])
				delete amaterias[i];
		for (int i = 0; i < 4; i++)
			if (obj.amaterias[i])
				this->amaterias[i] = obj.amaterias[i]->clone();
	}
	return (*this);
}

const std::string	&Character::getName(void) const
{
	return (this->name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if(!(this->amaterias[i]))
		{
			this->amaterias[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx > 3 || idx < 0)
		return ;
	if (this->amaterias[idx])
		this->amaterias[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx > 3 || idx < 0)
		return ;
	if (this->amaterias[idx])
		this->amaterias[idx]->use(target);
}
