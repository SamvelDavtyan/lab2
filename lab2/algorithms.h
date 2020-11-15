#pragma once

void swap(int& a, int& b); // O(1)
void PrintArray(int* A, int size); // O(n)
void PrintArray(char* A, int size); // O(n)
bool correct(int* A, int size); // O(n)
int BinarySearch(int* A, int size, int search_num); // O(log_2(n))
void BubbleSort(int* A, int size); // O(n^2)
void QuickSort(int* A, int low, int high); // O(n*log(n))
void BogoSort(int* A, int size); // O(n*n!)
void CountingSort(char* A, int size); // O(max+n)

