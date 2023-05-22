#pragma once

#include <iostream>

class Base
{
	public:
		virtual	~Base(void);
};

class A: public Base 
{
	public:
		~A(void);
};
class B: public Base
{
	public:
		~B(void);
};
class C: public Base
{
	public:
		~C(void);
};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);
