#pragma once
#include <vector>

/// @brief generates an bool vector where the index is set to true if that nummber is a prime all the way upp to the upper bound 'max'.
/// @param max 'max' is the upper bound.
/// @return a poniter to the vector
std::vector<bool>* find_primes(int max);

/// @brief generates a container with all the given primes found by the 'find_primes' funktion
/// @param primes 'primes' is a pointer to a bool vector 
/// @return pointer to the newly created container
std::vector<int>* create_container(std::vector<bool>* primes);