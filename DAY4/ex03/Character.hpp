#pragma once

#include "AMateria.hpp"

class AMateria;
class ICharacter
{
	public:
		virtual	~ICharacter() {}
		virtual const std::string &getName() const = 0;
		virtual void equip(AMateria *m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter &target) = 0;
};

class Character: public ICharacter
{

	private:
		std::string name;
		AMateria *amaterias[4];
	public:
		~Character(void);
		Character(void);
		Character(const Character &obj);
		Character(const std::string str);
		Character	&operator=(const Character &obj);


		const std::string &getName(void) const;
		void equip(AMateria *m);
		void unequip(int idx);
		void use(int idx, ICharacter &target);
};
