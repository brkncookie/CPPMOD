#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual	~IMateriaSource() {}
		virtual void learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(const std::string &type) = 0;
};

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *amaterias[4];
	public:
		~MateriaSource(void);
		MateriaSource (void);
		MateriaSource(const MateriaSource &obj);
		MateriaSource &operator=(const MateriaSource &obj);

		void learnMateria(AMateria *);
		AMateria	*createMateria(const std::string &type);
};
