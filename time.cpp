#include "time.h"
#include "search_algorithm.h"
#include <random>
#include <fstream>
#include <iostream>

std::mt19937 generator{ std::random_device()() };

double time_sequential_search(std::vector<int>* search_container)
{
	

	std::chrono::duration<double> sumtime(0);
	std::chrono::duration<double> time(0);

	std::uniform_int_distribution<long long> dist(0, search_container->back());
	
	std::ofstream file;
	file.open("quicker_sequential_search", std::ios::app);

	double measurements = 50.0;
	double sqrt_time = 0.0;
	for (int i = 0; i < measurements; i++)
	{
		int key = dist(generator);
		auto start = std::chrono::steady_clock::now();
		quicker_sequential_search(search_container, key);
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		sumtime += time;
		sqrt_time = sqrt_time + pow(time.count(), 2);
	}
	auto mean_time = sumtime.count() / measurements;
	auto s = sqrt((sqrt_time - (measurements * pow(mean_time, 2))) / (measurements - 1));

	file << search_container->size() << " " << mean_time << " " << s << "\n";
	file.close();

	return mean_time;
}

double time_sequential_search2(std::vector<int>* search_container)
{


	std::chrono::duration<double> sumtime(0);
	std::chrono::duration<double> time(0);

	std::uniform_int_distribution<long long> dist(0, search_container->back());

	std::ofstream file;
	file.open("sequential_search", std::ios::app);

	double measurements = 50.0;
	double sqrt_time = 0.0;
	for (int i = 0; i < measurements; i++)
	{
		int key = dist(generator);
		auto start = std::chrono::steady_clock::now();
		sequential_search(search_container, key);
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		sumtime += time;
		sqrt_time = sqrt_time + pow(time.count(), 2);
	}
	auto mean_time = sumtime.count() / measurements;
	auto s = sqrt((sqrt_time - (measurements * pow(mean_time, 2))) / (measurements - 1));

	file << search_container->size() << " " << mean_time << " " << s << "\n";
	file.close();

	return mean_time;
}

double time_binary_search(std::vector<int>* search_container, int first, int last)
{
	std::chrono::duration<double> sumtime(0);
	std::chrono::duration<double> time(0);

	std::uniform_int_distribution<long long> dist(0, search_container->back());

	std::ofstream file;
	file.open("binary_search", std::ios::app);

	double measurements = 50.0;
	double sqrt_time = 0.0;
	for (int i = 0; i < measurements; i++)
	{
		int key = dist(generator);
		auto start = std::chrono::steady_clock::now();
		binary_search(search_container,first,last,key);
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		sumtime += time;
		sqrt_time = sqrt_time + pow(time.count(), 2);
	}
	auto mean_time = sumtime.count() / measurements;
	auto s = sqrt((sqrt_time - (measurements * pow(mean_time, 2))) / (measurements - 1));

	file << search_container->size() << " " << mean_time << " " << s << "\n";
	file.close();

	return mean_time;
}

double time_bst_search(Node* tree,int max,int size)
{
	std::chrono::duration<double> sumtime(0);
	std::chrono::duration<double> time(0);

	std::uniform_int_distribution<long long> dist(0, max);

	std::ofstream file;
	file.open("bst_search", std::ios::app);

	double measurements = 50.0;
	double sqrt_time = 0.0;
	for (int i = 0; i < measurements; i++)
	{
		int key = dist(generator);
		auto start = std::chrono::steady_clock::now();
		bst_search(tree,key);
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		sumtime += time;
		sqrt_time = sqrt_time + pow(time.count(), 2);
	}
	auto mean_time = sumtime.count() / measurements;
	auto s = sqrt((sqrt_time - (measurements * pow(mean_time, 2))) / (measurements - 1));

	file << size << " " << mean_time << " " << s << "\n";
	file.close();

	return mean_time;
}

double time_hash_search(std::vector<H_node*>* hashtable,int max,int size)
{
	std::chrono::duration<double> sumtime(0);
	std::chrono::duration<double> time(0);
	std::uniform_int_distribution<long long> dist(0, max);

	std::ofstream file;
	file.open("hash_search", std::ios::app);

	double measurements = 50.0;
	double sqrt_time = 0.0;
	for (int i = 0; i < measurements; i++)
	{
		int key = dist(generator);
		auto start = std::chrono::steady_clock::now();
		hash_search(hashtable,key);
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		sumtime += time;
		sqrt_time = sqrt_time + pow(time.count(), 2);
	}

	auto mean_time = sumtime.count() / measurements;
	auto s = sqrt((sqrt_time - (measurements * pow(mean_time, 2))) / (measurements - 1));
	
	
	file << size << " " << mean_time << " " << s << "\n";
	
	file.close();

	return mean_time;
}

double time_bst_search2(std::vector<int>* search_tree)
{
	std::chrono::duration<double> sumtime(0);
	std::chrono::duration<double> time(0);

	std::uniform_int_distribution<long long> dist(0, search_tree->back());

	std::ofstream file;
	file.open("bst_search2", std::ios::app);

	double measurements = 500.0;
	double sqrt_time = 0.0;
	for (int i = 0; i < measurements; i++)
	{
		int key = dist(generator);
		auto start = std::chrono::steady_clock::now();
		bst_search2(search_tree, key);
		auto end = std::chrono::steady_clock::now();
		time = end - start;
		sumtime += time;
		sqrt_time = sqrt_time + pow(time.count(), 2);
	}
	auto mean_time = sumtime.count() / measurements;
	auto s = sqrt((sqrt_time - (measurements * pow(mean_time, 2))) / (measurements - 1));

	file << search_tree->size() << " " << mean_time << " " << s << "\n";
	file.close();

	return mean_time;
}