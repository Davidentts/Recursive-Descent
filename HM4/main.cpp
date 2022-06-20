#include <iostream>
#include "Header.h"

//S → aE
//E → bAA | cAB | a
//A → aD
//D → Ca | b
//C → abH | cC
//H → cA | AB
//B → CAa



char str[] = " ";
int index_of_arr = 0;

int main()
{
	std::cin >> str;
	S();
	std::cout << "The chain is output!"; 
	return 0;
}

char getSymb()
{
	char a = str[index_of_arr];
	index_of_arr++;
	return a;
}

void error()
{
	std::cout << "FAILED!\nThe chain is not output!";
	exit(1);
}

void S() 
{
	char a = getSymb();
	if (a != 'a')
		error();

	E();

	if (strlen(str) != index_of_arr)
		error();
}

void E()
{
	char a = getSymb();
	if (a == 'b')
	{
		A();
		A();
	}
	else if (a == 'c')
	{
		A();
		B();
	}
	else if (a != 'a')
		error();
}

void A()
{
	char a = getSymb();
	if (a != 'a')
		error();
	D();
}

void D()
{
	char a = getSymb();
	if (a != 'b')
	{
		index_of_arr--;
		C();
		a = getSymb();
		if (a != 'a')
			error();
	}
}

void C()
{
	char a = getSymb();
	if (a == 'a')
	{
		a = getSymb();
		if (a != 'b')
			error();
		H();
	}
	else if (a == 'c')
	{
		C();
	}else error();

}

void B()
{
	C();
	A();
	char a = getSymb();
	if (a != 'a')
		error();
}

void H()
{
	char a = getSymb();
	if(a == 'c')
	{
		A();
	}
	else 
	{
		A();
		B();
	}
}