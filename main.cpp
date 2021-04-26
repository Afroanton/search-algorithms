#include <iostream>
#include "Datageneration.h"
#include "search_algorithm.h"
#include "time.h"
#include <chrono>
#include <string>
#include <fstream>


#define COUNT 10 

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

void print2DUtil(Node* root, int space)
{
	// Base case  
	if (root == NULL)
		return;

	// Increase distance between levels  
	space += COUNT;

	// Process right child first  
	print2DUtil(root->right_child, space);

	// Print current node after space  
	// count  
	std::cout << std::endl;
	for (int i = COUNT; i < space; i++)
		std::cout << " ";
	std::cout << root->data << "\n";

	// Process left child  
	print2DUtil(root->left_child, space);
}

void print_file(std::string filename)
{
	std::ifstream file;
	file.open(filename);
	std::string content;
	std::cout << filename << "\n" << "N      T(s)      S" << "\n";
	while (!file.eof())
	{
		std::getline(file, content);
		std::cout << content << "\n";
	}
	file.close();
}

// Wrapper over print2DUtil()  
void print2D(Node* root)
{
	// Pass initial space count as 0  
	print2DUtil(root, 0);
}

int main()
{
	/*
	* int measurements = 5; 
	auto mean_time = (3.0 + 5 + 7 + 8 + 14) / measurements;
	auto sqrt_time = pow(3, 2) + pow(5, 2) + pow(7, 2) + pow(8, 2) + pow(14, 2);
	auto s = sqrt((sqrt_time - (measurements * pow(mean_time, 2))) / (measurements - 1));
	std::cout << s << "\n";
	*/
	
	std::cout << "test" << "\n";
	remove("quicker_sequential_search");
	remove("sequential_search");
	remove("binary_search");
	remove("bst_search");
	remove("bst_search2");
	remove("hash_search");

	//std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

	//auto tree = create_bst2(&v, 0, v.size()-1); 
	//print(tree);
	//bst_search2(tree, 16);

	int size = 2000000000;
	auto a = find_primes(size);
	int n = 20;
	int search_size = pow(2, n) - 1;
	
	

	std::cout << "elements " << "time" << "\n";
	while (n < 27)
	{
		
		auto b = create_container(a,search_size);
		auto tree1 = create_bst(b, 0, b->size() - 1);
		auto tree2 = create_bst2(b,0, b->size() - 1);
		auto hashtable = create_hashtable(b);
		time_sequential_search2(b);
		time_sequential_search(b);
		time_binary_search(b, 0, b->size() - 1);
		time_bst_search(tree1,b->back(),b->size());
		time_bst_search2(tree2);
		time_hash_search(&hashtable,b->back(),b->size());
		n++;
		search_size = pow(2, n) - 1;
	}
	
	print_file("quicker_sequential_search");
	print_file("sequential_search");
	print_file("binary_search");
	print_file("bst_search");
	print_file("bst_search2");
	print_file("hash_search");
	




	
	
	//std::cout << "PreOrder Traversal of constructed BST \n";
	//preOrder(tree);



	

	
		
	//print2D(tree);
	//print(b);

	//std::cout << "hello world" << "\n";
}