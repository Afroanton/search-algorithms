#pragma once
#include <chrono>
#include <vector>
#include "Datageneration.h"
#include "search_algorithm.h"

double time_sequential_search(std::vector<int>* search_container);
double time_sequential_search2(std::vector<int>* search_container);
double time_binary_search(std::vector<int>* search_container, int first, int last);
double time_bst_search(Node* tree,int max,int size);
double time_bst_search2(std::vector<int>* search_tree);
double time_hash_search(std::vector<H_node*>* hashtable,int max,int size);