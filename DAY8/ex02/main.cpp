#include "MutantStack.hpp"
int main()
{
	{
	std::cout << "			Start of first test" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	std::cout << "			End of first test" << std::endl;
	}
	{
	std::cout << "			Start of second test" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(10);

    std::cout << "Elements in MutantStack using iterator:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) 
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int>::iterator it = mstack.begin();
    ++it;
    *it = 20;

    std::cout << "Modified elements in MutantStack using iterator:" << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) 
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
	std::cout << "			End of second test" << std::endl;
	}
}
