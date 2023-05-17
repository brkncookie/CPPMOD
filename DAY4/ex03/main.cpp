#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
    {
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete src;
    }
    {
    ICharacter* me = new Character("me");

    AMateria* tmp;
    tmp = new Ice;
    me->equip(tmp);
    tmp = new Cure;
    me->equip(tmp);
    me->unequip(1);

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    delete tmp;
    }
    {
    ICharacter* me = new Character("me");

    AMateria* tmp;
    AMateria* tmp1;
    tmp = new Ice;
    tmp1 = new Cure;

    tmp->use(*me);
    tmp1->use(*me);

    delete me;
    delete tmp;
    delete tmp1;
    }
}
