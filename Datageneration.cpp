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

std::vector<int>* create_container(std::vector<bool>* primes,int size)
{
	int counter = 0;
	std::vector<int>* container = new std::vector<int>;
	for (int i = 0; i < primes->size() && counter < size; i++)
	{
		if ((*primes)[i])
		{
			container->push_back(i);
			counter++;
		}
	}

	return container;
}



Node* create_bst(std::vector<int>* vector, int start, int end)
{

	if (start <= end)
	{
		int mid = (start + end) / 2;
		Node* root = new Node((*vector)[mid]);
		root->left_child = create_bst(vector, start, mid - 1);
		root->right_child = create_bst(vector, mid + 1, end);
		return root;
	}
	else
	{
		return nullptr;
	}

}

std::vector<int>* create_bst2(std::vector<int>* vector, int start, int end)
{
	std::vector<int>* bst = new std::vector<int>(vector->size());
	int pos = 0;
	int mid = (start + end) / 2;
	(*bst)[pos] = (*vector)[mid];
	

	
	create_child(bst, vector, start, mid-1, 2*pos+1);
	create_child(bst, vector, mid + 1, end, 2*pos+2);

	return bst;
}

void create_child(std::vector<int>* bst,std::vector<int>* vector, int start,int end,int pos)
{
	if (start <= end)
	{
		int mid = (start + end) / 2;
		(*bst)[pos] = (*vector)[mid];
		//pos++;
		create_child(bst, vector, start, mid - 1, 2*pos+1);
		create_child(bst, vector, mid + 1, end, 2*pos+2);
	}

}


std::vector<H_node*> create_hashtable(std::vector<int>* vector)
{
	int size = vector->size()*2;
	std::vector<H_node*>hashtable(size);
	for (auto i : *vector)
	{
		
		H_node* node = new H_node(i);
		int key = i % size;
		if (hashtable[key] == nullptr)
		{
			hashtable[key] = node;
		}
		else
		{
			H_node* node2 = hashtable[key];
			while (node2->next != nullptr)
			{
				node2 = node2->next;
			}
			hashtable[key]->next = node;
		}
	}
	return hashtable;
}
