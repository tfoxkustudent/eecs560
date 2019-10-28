
#ifndef Heap_HPP
#define Heap_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;



class Heap{

public:

void restoreDownMax(int arr[], int len, int index, int k) {
	int child[k+1];

	while (1)
	{
		for (int i=1; i<=k; i++) {
			if ((k*index + i) < len) {
				child[i] = (k*index +1);
			}
			else {
				child[i] = (-1);
			}
		}
		int max_child = -1, max_child_index ;
		
		for (int i=1; i <=k; i++)
		{
			if (child[i] != -1 && arr[child[i]] > max_child) {
				max_child_index = child[i];
				max_child = arr[child[i]];
			}
		}
		
		if (max_child == -1) {
			break;
		}

		if (arr[index] < arr[max_child_index]) {
			swap(arr[index], arr[max_child_index]);
		}
		index = max_child_index;
	}	
}

void restoreDownMin(int arr[], int len, int index, int k) {
	int child[k+1];

	while (1)
	{
		for (int i=1; i<=k; i++) {
			if ((k*index +1) < len) {
				child[i] = (k*index +1);
			}
			else {
				child[i] = (-1);
			}
		}
		int min_child = -1, min_child_index ;

		for (int i=1; i<=k; i++) {
			if (child[i] != -1 && arr[child[i]] < min_child) {
				min_child_index = child[i];
				min_child = arr[child[i]];
			}
		}
		if (min_child == -1) {
			break;
		}

		if (arr[index] > arr[min_child_index]) {
			swap(arr[index], arr[min_child_index]);
		}
		index = min_child_index;
		 
	}
}

void restoreUpMax(int arr[], int index, int k) {
	int parent = (index-1)/k;
	
	while (parent>=0) {
		if (arr[index] > arr[parent]) {
			swap(arr[index], arr[parent]);
			index = parent;
			parent = (index -1)/k;
		}
		else {
			break;
		}
	}
}

void restoreUpMin(int arr[], int index, int k) {
	int parent = (index-1)/k;

	while (parent>=0) {
		if (arr[index] < arr[parent]) {
			swap(arr[index], arr[parent]);
			index = parent;
			parent = (index-1)/k;
		}
		else {
			break;
		}
	}
	
}

void HeapifyMax(int arr[], int n, int k) {
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = (n-1)/k; i>=0; i--) {
		restoreDownMax(arr, n, i, k);
	}
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << "\nTime it took to heapify the max heap  ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
}

void HeapifyMin(int arr[], int n, int k) {
	auto start = std::chrono::high_resolution_clock::now();
        for (int i = (n-1)/k; i>=0; i--) {
                restoreDownMin(arr, n, i, k);
	}
	auto finish = std::chrono::high_resolution_clock::now();
        std::cout << "\nTime it took to heapify the min heap  ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
}

void InsertMax(int arr[], int* n, int k, int elem) {
	arr[*n] = elem;
	*n = *n+1;
	restoreUpMax(arr, *n-1, k);
}

void InsertMin(int arr[], int* n, int k, int elem) {
        arr[*n] = elem;
        *n = *n+1;
        restoreUpMin(arr, *n-1, k);
}

int DeleteMin(int arr[], int* n, int k) {
	int min = arr[0];
        arr[0] = arr[*n-1];
        *n = *n-1;
        restoreDownMin(arr, *n, 0, k);
        return min;
}

int PQ_DeleteMin(int arr[], int* n, int k) {
        auto start = std::chrono::high_resolution_clock::now();
	int min = arr[0];
        arr[0] = arr[*n-1];
        *n = *n-1;
        restoreDownMin(arr, *n, 0, k);
	auto finish = std::chrono::high_resolution_clock::now();
        std::cout << "\nMin Heap time to delete highest priority ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
        return min;
}

int DeleteMax(int arr[], int* n, int k) {
	int max = arr[0];
        arr[0] = arr[*n-1];
        *n = *n-1;
        restoreDownMax(arr, *n, 0, k);
        return max;	
}

int PQ_DeleteMax(int arr[], int* n, int k) {
	auto start = std::chrono::high_resolution_clock::now();
        int max = arr[0];
        arr[0] = arr[*n-1];
        *n = *n-1;
        restoreDownMax(arr, *n, 0, k);
	auto finish = std::chrono::high_resolution_clock::now();
        std::cout << "\nMax Heap time to delete highest priority ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
        return max;
}


int PQ_HighestMax(int arr[]) {
	//auto start = std::chrono::high_resolution_clock::now();
	int max = arr[0];
	//auto finish = std::chrono::high_resolution_clock::now();
        //std::cout << "\nMax Heap time to find highest priority ";
        //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
	return max;
}

int PQ_HighestMin(int arr[]) {
	//auto start = std::chrono::high_resolution_clock::now();
        int min = arr[0];
	//auto finish = std::chrono::high_resolution_clock::now();
	//std::cout << "\nMin Heap time to find Highest priority ";
        //std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
        return min;
}


int PQ_LowestMax(int arr[], int n) {
	int lowestP = arr[0];
        for (int i=1; i < n; ++i) {
                if (arr[i] < lowestP) {
                        lowestP = arr[i];
                }
        }
        return lowestP;

}

int PQ_LowestMin(int arr[], int n) {
        int lowestP = arr[0];
	for (int i=1; i < n; ++i) {
		if (arr[i] < lowestP) {
			lowestP = arr[i];
		}
	}
        return lowestP;
}


void Level_Order(int arr[], int n) {
	for (int i=0; i < n; i++) {
		cout << arr[i] << " ";
	}
}

void Time_LowestPQMin(int arr[], int n) {
	auto start = std::chrono::high_resolution_clock::now();
	PQ_LowestMin(arr, n);
	auto finish = std::chrono::high_resolution_clock::now();
	std::cout << "\nMin Heap time to find lowest priority ";
	std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
}

void Time_LowestPQMax(int arr[], int n) {
        auto start = std::chrono::high_resolution_clock::now();
        PQ_LowestMax(arr, n);
        auto finish = std::chrono::high_resolution_clock::now();
	std::cout << "\nMax Heap time to find lowest priority ";
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";
}


void Exit(){}


};
#endif
