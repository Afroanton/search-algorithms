#include <iostream>
#include "Datageneration.h"
void print(std::vector<int>* vector)
{
	for (int i = 0; i < vector->size() ; i++)
	{
		
		
			std::cout << (*vector)[i] << "\n";
		
	}
}
int main()
{
	int size = 22;
	auto a = find_primes(size);
	auto b = create_container(a);
	print(b);
	std::cout << "hello world" << "\n";
}