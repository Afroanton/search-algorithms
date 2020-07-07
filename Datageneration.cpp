#include "Datageneration.h"
#include <algorithm>

bool* find_primes(int max)
{
	bool* array_pointer = new bool[max + 1];
	std::fill(array_pointer, array_pointer+max, true);
	array_pointer[0] = false;
	array_pointer[1] = false;

	for (int i = 2; i <= sqrt(max); i++)
	{
		if (array_pointer[i])
		{
			for (int j = 2; j * i <= max; j++)
			{
				array_pointer[j * i] = false;
			}
		}
	}
	return array_pointer;
}

