#pragma once
#include <vector>
#include "Datageneration.h"

/// @brief classic sequential search on a int vector
/// @param container is the vector that's gonna be searched
/// @param key is the value that's being lookt for
void sequential_search(std::vector<int>* container,int key);

/// @brief optimized sequential search on a int vector
/// @param container is the vector that's gonna be searched
/// @param key is the value that's being lookt for
void quick_sequential_search(std::vector<int>* container, int key);

/// @brief super optimized sequential search on a int vector
/// @param container is the vector that's gonna be searched
/// @param key is the value that's being lookt for
void quicker_sequential_search(std::vector<int>* container, int key);

/// @brief classic binary search on a int vector
/// @param search_container is the vector that's gonna be searched
/// @param first index of the first element in the vector
/// @param last index of the last element in the vector
/// @param key is the value that's being lookt for
void binary_search(std::vector<int>* search_container, int first, int last, int key);

/// @brief searching thru a binary search tree.
/// @param root is a pointer to the root element of a binary search tree
/// @param key is the value that's being lookt for
void bst_search(Node* root, int key);


