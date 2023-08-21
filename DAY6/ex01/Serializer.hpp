#pragma once

#include <iostream>

struct Data
{
	char x;
};

class Serializer
{
	private:
		Serializer(void);
		~Serializer(void);
		Serializer(const Serializer &obj);
		Serializer	&operator=(const Serializer &obj);
	public:
		static uintptr_t	serialize(Data *ptr);
		static Data		*deserialize(uintptr_t raw);
};
