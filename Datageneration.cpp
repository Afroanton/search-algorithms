#include "Datageneration.h"
#include <algorithm>

std::vector<bool>* find_primes(int max)
{
	auto vector_pointer = new std::vector<bool>(max + 1, true);
	(*vector_pointer)[0] = false;
	(*vector_pointer)[1] = false;

	for (int i = 2; i <= sqrt(max); i++)
	{
		if ((*vector_pointer)[i])
		{
			for (int j = 2; j * i <= max; j++)
			{
				(*vector_pointer)[i * j] = false;
			}
		}
	}
	return vector_pointer;
}
 
std::vector<int>* create_container(std::vector<bool>* primes)
{
	std::vector<int>* container = new std::vector<int>;
	for (int i = 0; i < primes->size(); i++)
	{
		if ((*primes)[i])
		{
			container->push_back(i);
		}
	}

	return container;
}

