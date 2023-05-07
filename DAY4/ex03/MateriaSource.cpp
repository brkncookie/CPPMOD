#include "MateriaSource.hpp"

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		if(amaterias[i])
			delete amaterias[i];
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		amaterias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
	for (int i = 0; i < 4; i++)
		amaterias[i] = NULL;
	*this = obj;
}

MateriaSource	&MateriaSource::operator=(const MateriaSource &obj)
{
	for (int i = 0; i < 4; i++)
		if (obj.amaterias[i])
			this->amaterias[i] = obj.amaterias[i]->clone();
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!(this->amaterias[i]))
		{
			this->amaterias[i] = m;
			return ;
		}
	}

}

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->amaterias[i] && this->amaterias[i]->getType() == type)
			return (this->amaterias[i]->clone());
	}
	return (NULL);
}
