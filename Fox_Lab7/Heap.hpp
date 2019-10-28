
#ifndef Heap_HPP
#define Heap_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
using namespace std;



class Heap{

public: 

void Insert(int x, int arr[], int &m_elem) {
	m_elem++;
	arr[m_elem] = x;
	cout << "m_elem: " << m_elem << "\n";
	BuildHeap(arr, m_elem);
	}


void Delete(int x, int arr[], int *m_elem) {
	for (int i = 1; i < *m_elem+1; i++)
		if (x == arr[i]) {
			int temp = arr[i];
			arr[i] = arr[*m_elem];
			*m_elem--;
			BuildHeap(arr, *m_elem);
		}
}

void BuildHeap(int arr[], int m_elem) {
	for (int i = 1; i < m_elem+1; i++)
		heapify(i, arr, m_elem);
}

void heapify(int loc, int arr[], int m_elem) {
	if (isMinLevel(loc))
		heapifyMin(loc, arr, m_elem);
	else
		heapifyMax(loc, arr, m_elem);
}

void heapifyMin(int loc, int arr[], int m_elem) {
	if (loc > m_elem / 2) return;
	int s = smallest(loc, arr, m_elem);

	if (s != -1 && arr[s] < arr[loc]) {
		int temp = arr[s];
		arr[s] = arr[loc];
		arr[loc] = temp;
		if (loc != 1 && s != loc * 2 && s != (loc * 2) + 1) {
			if (arr[loc] > arr[loc / 2]) {
				arr[loc] = arr[loc / 2];
				arr[loc / 2] = temp;
			}
			heapifyMin(loc, arr, m_elem);
		}
	}
}

void heapifyMax(int loc, int arr[], int m_elem) {
	if (loc > m_elem / 2) return;

	int l = largest(loc, arr, m_elem);


	if (l != -1 && arr[l] > arr[loc]) {
		int temp = arr[l];
		arr[l] = arr[loc];
		arr[loc] = temp;
		if (loc != 1 && l != loc * 2 && l != (loc * 2) + 1) {
			if (arr[loc] < arr[loc / 2]) {
				arr[loc] = arr[loc / 2];
				arr[loc / 2] = temp;
			}
			heapifyMax(loc, arr, m_elem);
		}
	}
}

void levelorder(int arr[], int m_elem) {
	if (m_elem == 0) {
		std::cout << "Heap is empty\n";
		return;
	}
	for (int i = 1; i <= m_elem; i++) {
		std::cout << arr[i];
		if (isPowerOfTwo(i + 1))
			std::cout << "\n";
		else
			std::cout << ", ";
	}
	std::cout << "\n";
}

void findMin(int arr[], int m_elem) {
	if (m_elem != 0)
		std::cout << arr[1] << "\n";
}

void findMax(int arr[], int m_elem) {
	if (m_elem != 0) {
		if (m_elem == 2) {
			std::cout << arr[2] << "\n";
		} else {
			if (arr[2] > arr[3])
				std::cout << arr[2] << "\n";
			else
				std::cout << arr[3] << "\n";
		}
	}
}

int smallest(int loc, int arr[], int m_elem) {
	if (loc * 2 > m_elem) return -1;
	int smallestLoc = loc * 2;

	if (!((loc * 2) + 1 > m_elem) && arr[(loc * 2) + 1] < arr[smallestLoc])
		smallestLoc++;
	int left = smallest(loc * 2, arr, m_elem);
	int right = smallest((loc * 2) + 1, arr, m_elem);
	if (left != -1 && right != -1) {
		if (arr[right] < arr[left])
			smallestLoc = right;
		else
			smallestLoc = left;
	} else {
		if (left != -1 && arr[left] < arr[smallestLoc])
			smallestLoc = left;
		if (right != -1 && arr[right] < arr[smallestLoc])
			smallestLoc = right;
	}
	return smallestLoc;
}

int largest(int loc, int arr[], int m_elem) {
	if (loc * 2 > m_elem) return -1;
	int largestLoc = loc * 2;

	if (!((loc * 2) + 1 > m_elem) && arr[(loc * 2) + 1] > arr[largestLoc])
		largestLoc++;
	int left = largest(loc * 2, arr, m_elem);
	int right = largest((loc * 2) + 1, arr, m_elem);
	if (left != -1 && right != -1) {
		if (arr[right] > arr[left])
			largestLoc = right;
		else
			largestLoc = left;
	} else {
		if (right != -1 && arr[right] > arr[largestLoc])
			largestLoc = right;
		if (left != -1 && arr[left] > arr[largestLoc])
			largestLoc = left;
		}
	return largestLoc;
}

bool isMinLevel(int loc) {
	if (loc == 1) return true;
	int times = 0;
	while (loc != 1) {
		loc = loc / 2;
		times++;
	}
	return (times % 2 == 0) ? true : false;
}

bool isPowerOfTwo(int x) {
	while (x % 2 == 0) x = x / 2;
	return x == 1;
}

void MinLevelElements(int arr[], int m_elem) {
	if (m_elem == 0) {
                std::cout << "Heap is empty\n";
                return;
        }
        for (int i = 1; i <= m_elem+1; i++) {
		if (isMinLevel(i) == true){
                	std::cout << arr[i];
                	if (isPowerOfTwo(i + 1))
                        	std::cout << "\n";
                	else
                        	std::cout << ", ";
		}
        }
        std::cout << "\n";
}

void MaxLevelElements(int arr[], int m_elem) {
if (m_elem == 0) {
                std::cout << "Heap is empty\n";
                return;
        }
        for (int i = 1; i < m_elem+1; i++) {
		if (isMinLevel(i) == false){
                	std::cout << arr[i];
                	if (isPowerOfTwo(i + 1))
                        	std::cout << "\n";
                	else
                        	std::cout << ", ";
		}
        }
        std::cout << "\n";

}

void Exit(){}


};
#endif
