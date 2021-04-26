#include "search_algorithm.h"
#include <iostream>

void sequential_search(std::vector<int>* search_container,int key)
{
	for (int i = 0; i < search_container->size(); i++)
	{
		if (key == (*search_container)[i])
		{
			//std::cout << "element found" << "\n";
			return;
		}
	}
	//std::cout << "element not found" << "\n";

}

void quick_sequential_search(std::vector<int>* search_container, int key)
{
	int i = 0;
	search_container->push_back(key);

	while (true)
	{
		if (key == (*search_container)[i])
		{
			break;
		}
		i++;
	}
	search_container->pop_back();

	if (i == search_container->size())
	{
		//std::cout << "element not found" << "\n";
	}
	else
	{
		//std::cout << "element found" << "\n";
	}
}

void quicker_sequential_search(std::vector<int>* search_container, int key)
{
	int i = 0;
	search_container->push_back(key);
	// 2 3 5 4
	while (true)
	{
		
		if (key == (*search_container)[i])
		{
			break;
		}
		else if(key == (*search_container)[i+1])
		{
			i++;
			break;
		}
		i = i+2;
	}
	search_container->pop_back();

	if (i == search_container->size())
	{
		//std::cout << "element not found" << "\n";
	}
	else
	{
		//std::cout << "element found" << "\n";
	}
}


void binary_search(std::vector<int>* search_container,int first,int last, int key)
{


	if (last >= first)
	{
		int mid = (last + first) / 2;
		if (key < (*search_container)[mid])
		{
			
			binary_search(search_container, first, mid-1, key);
		}
		else if (key > (*search_container)[mid])
		{
			
			binary_search(search_container, mid+1, last, key);
		}
		else
		{
			//std::cout << "element found" << (*search_container)[mid] <<"\n";
			return;
		}
	}
	else
	{
		//std::cout << "element not found" << "\n";
	}
}

void bst_search(Node* root, int key)
{
	Node* pointer = root;
	while (pointer != nullptr)
	{
		if (key < pointer->data)
		{
			pointer = pointer->left_child;
		}
		else if(key > pointer->data)
		{
			pointer = pointer->right_child;
		}
		else
		{
			//std::cout << "element found " << pointer->data << "\n";
			return;
		}
	}
	//std::cout << "element not found" << "\n";
	return;
}

void bst_search2(std::vector<int>* tree, int key)
{
	int size = tree->size();
	int i = 0;
	while (i <= size)
	{
		if (key < (*tree)[i])
		{
			i = i * 2 + 1;
		}
		else if (key > (*tree)[i])
		{
			i = i * 2 + 2;
		}
		else
		{
			//std::cout << "element found!!" << "\n";
			return;
		}
	}
		//std::cout << "element not found" << "\n";
		return;
}


void hash_search(std::vector<H_node*>* hashtable, int key)
{
	int key_pos = key % hashtable->size();
	int i = 0;
	
	while ((*hashtable)[key_pos] != nullptr)
	{
		if ((*hashtable)[key_pos]->data == key)
		{
			//std::cout << "element found " << (*hashtable)[key_pos]->data << " " << i << "\n";
			return;
		}
		else
		{
			(*hashtable)[key_pos] = (*hashtable)[key_pos]->next;
			i++;
		}
	}

	//std::cout << "element not found" << "\n";
}



