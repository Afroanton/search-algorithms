#pragma once
#include <vector>

/// @brief nodes used to create a binary tree
struct Node
{
	Node(int data):data(data), left_child(nullptr), right_child(nullptr) {};
	int data;
	Node* left_child;
	Node* right_child;
};

/// @brief generates an bool vector where the index is set to true if that nummber is a prime all the way upp to the upper bound 'max'.
/// @param max is the larges number that will be checkt if it is a prime or not.
/// @return a pointer to the bool vector
std::vector<bool>* find_primes(int max);

/// @brief generates a container with all the given primes found by the 'find_primes' funktion
/// @param primes 'primes' is a pointer to a bool vector 
/// @return pointer to the newly created container
std::vector<int>* create_container(std::vector<bool>* primes);

/// @brief creates a binary search tree from a sorted container.
/// @param vector is a pointer to a sorted int vector.
/// @param start is the index of the starting element.
/// @param end is the index of the last element. 
/// @return pointer to the root element in the tree.
Node* create_bst(std::vector<int>* vector, int start, int end);