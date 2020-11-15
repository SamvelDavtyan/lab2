#include <iostream>
#include "algorithms.h"
#include <time.h>
#include <fstream>

using namespace std;



int main()
{
	srand(time(0));
	int size = 10, minus;
	double average;
	int* array_for_tests; 
	clock_t start_time, end_time, result_time;
	ofstream of("Time_test_result.txt");
	double result[10];
	of << "Result for QuickSort: " << endl;
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			array_for_tests = new int[size];
			for (int k = 0; k < size; k++)
			{
				minus = -1;
				if (rand() % 10 > 4)
					minus = 1;
				array_for_tests[k] = rand() * minus;
			}
			start_time = clock();
			QuickSort(array_for_tests, 0, size - 1);
			end_time = clock();
			result_time = end_time - start_time;
			result[j] = ((double)result_time * 1000 / CLOCKS_PER_SEC);
			of << result[j] << " ";
			delete[] array_for_tests;
		}
		average = 0;
		for (int j = 0; j < 10; j++)
			average += result[j];
		average /= 10;
		of << "for " << size << " elements. " << " Average: " << average << '\n';
		size *= 10;
	}
	size = 10;
	of << "Result for BubbleSort: " << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			array_for_tests = new int[size];
			for (int k = 0; k < size; k++)
			{
				array_for_tests[k] = rand();
			}
			start_time = clock();
			BubbleSort(array_for_tests, size);
			end_time = clock();
			result_time = end_time - start_time;
			result[j] = ((double)result_time * 1000 / CLOCKS_PER_SEC);
			of << result[j] << " ";
			delete[] array_for_tests;
		}
		average = 0;
		for (int j = 0; j < 10; j++)
			average += result[j];
		average /= 10;
		of << "for " << size << " elements. " << " Average: " << average << '\n';
		size *= 10;
	}
	of.close();
}