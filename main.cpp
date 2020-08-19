#include <iostream>
#include "Datageneration.h"
#include "search_algorithm.h"
#include <chrono>


void print(std::vector<int>* vector)
{
	for (int i = 0; i < vector->size() ; i++)
	{	
			std::cout << (*vector)[i] << "\n";
	}
}

void preOrder(Node* node)
{
	if (node == nullptr)
		return;
	std::cout << node->data << " ";
	preOrder(node->left_child);
	preOrder(node->right_child);
}

int main()
{
	


	int size = 1000000;
	auto a = find_primes(size);
	auto b = create_container(a);
	auto tree = create_bst(b,0,b->size()-1);
	
	//std::cout << "PreOrder Traversal of constructed BST \n";
	//preOrder(tree);

	std::chrono::duration<double> time1(0);
	std::chrono::duration<double> time2(0);
	std::chrono::duration<double> time3(0);
	std::chrono::duration<double> time4(0);
	std::chrono::duration<double> time5(0);

	auto start1 = std::chrono::steady_clock::now();
	sequential_search(b, 702607);
	auto end1 = std::chrono::steady_clock::now();

	auto start2 = std::chrono::steady_clock::now();
	quick_sequential_search(b, 702607);
	auto end2 = std::chrono::steady_clock::now();

	auto start3 = std::chrono::steady_clock::now();
	quicker_sequential_search(b, 702607);
	auto end3 = std::chrono::steady_clock::now();
	
	auto start4 = std::chrono::steady_clock::now();
	binary_search(b,0,b->size()-1, 702607);
	auto end4 = std::chrono::steady_clock::now();

	auto start5 = std::chrono::steady_clock::now();
	bst_search(tree, 702607);
	auto end5 = std::chrono::steady_clock::now();

	time1 = end1 - start1;
	time2 = end2 - start2;
	time3 = end3 - start3;
	time4 = end4 - start4;
	time5 = end5 - start5;

	std::cout << "sequential_search: " << time1.count() << "\n" << "quick_sequential_search: " << time2.count() << "\n" << "quicker_sequential_search: " << time3.count()
		<< "\n" << "binary_search: " << time4.count() << "\n" << "binary_search_tree: " << time5.count() << "\n";
		
		;
	//print(b);

	//std::cout << "hello world" << "\n";
}