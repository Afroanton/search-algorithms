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
int main()
{
	int size = 100000;
	auto a = find_primes(size);
	auto b = create_container(a);

	std::chrono::duration<double> time1(0);
	std::chrono::duration<double> time2(0);
	std::chrono::duration<double> time3(0);
	std::chrono::duration<double> time4(0);

	auto start1 = std::chrono::steady_clock::now();
	sequential_search(b, 3571);
	auto end1 = std::chrono::steady_clock::now();

	auto start2 = std::chrono::steady_clock::now();
	quick_sequential_search(b, 3571);
	auto end2 = std::chrono::steady_clock::now();

	auto start3 = std::chrono::steady_clock::now();
	quicker_sequential_search(b, 3571);
	auto end3 = std::chrono::steady_clock::now();
	
	auto start4 = std::chrono::steady_clock::now();
	binary_search(b,0,b->size()-1, 3571);
	auto end4 = std::chrono::steady_clock::now();

	time1 = end1 - start1;
	time2 = end2 - start2;
	time3 = end3 - start3;
	time4 = end4 - start4;

	std::cout << "sequential_search: " << time1.count() << "\n" << "quick_sequential_search: " << time2.count() << "\n" << "quicker_sequential_search: " << time3.count() 
		<< "\n" << "binary_search: " << time4.count() << "\n"
		
		;
	//print(b);

	//std::cout << "hello world" << "\n";
}