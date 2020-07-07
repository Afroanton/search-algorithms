#include <iostream>
#include "Datageneration.h"
void print(bool* array)
{
	for (int i = 0; i <= 22 ; i++)
	{
		if (array[i])
		{
			std::cout << i << "\n";
		}
	}
}
int main()
{
	
	auto a = find_primes(22);
	print(a);
	std::cout << "hello world" << "\n";
}