#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    const int arraySize = 10;
    std::vector<int> numbers;
    numbers.resize(arraySize);

    std::srand(static_cast<unsigned int>(std::time(NULL)));

    for (int i = 0; i < arraySize; ++i)
    {
        numbers[i] = std::rand();
    }

    for (int i = 0; i < arraySize; ++i)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    Span	span(static_cast<unsigned int>(arraySize));
    span.addSequence(numbers.begin(), numbers.end());
    std::cout << span.shortestSpan() << std::endl;
    std::cout << span.longestSpan() << std::endl;
    try
    {
	    span.addNumber(10);
    }
    catch (std::exception &e)
    {
	    std::cout << e.what() << std::endl;
    }
    return 0;
}
