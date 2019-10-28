#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Heap.hpp"
using namespace std;


int main()
{
	Heap myHeap;
	int max10Heap[15000];
	int min10Heap[15000];
	ifstream file10("10nums.txt");
        int value10;
	int max10Num = 0;
	int min10Num = 0;
        file10 >> value10;
        while (!file10.eof())
        {
		myHeap.InsertMax(max10Heap, &max10Num, 3, value10);
		myHeap.InsertMin(min10Heap, &min10Num, 3, value10);
		file10 >> value10;
	}

	int max50Heap[15000];
        int min50Heap[15000];
        ifstream file50("50nums.txt");
        int value50;
        int max50Num = 0;
        int min50Num = 0;
        file50 >> value50;
        while (!file50.eof())
        {
                myHeap.InsertMax(max50Heap, &max50Num, 3, value50);
                myHeap.InsertMin(min50Heap, &min50Num, 3, value50);
                file50 >> value50;
        }

	int max100Heap[15000];
        int min100Heap[15000];
        ifstream file100("100nums.txt");
        int value100;
        int max100Num = 0;
        int min100Num = 0;
        file100 >> value100;
        while (!file100.eof())
        {
                myHeap.InsertMax(max100Heap, &max100Num, 3, value100);
                myHeap.InsertMin(min100Heap, &min100Num, 3, value100);
                file100 >> value100;
        }

	int max500Heap[15000];
        int min500Heap[15000];
        ifstream file500("500nums.txt");
        int value500;
        int max500Num = 0;
        int min500Num = 0;
        file500 >> value500;
        while (!file500.eof())
        {
                myHeap.InsertMax(max500Heap, &max500Num, 3, value500);
                myHeap.InsertMin(min500Heap, &min500Num, 3, value500);
                file500 >> value500;
        }

	int max1000Heap[15000];
        int min1000Heap[15000];
        ifstream file1000("1000nums.txt");
        int value1000;
        int max1000Num = 0;
        int min1000Num = 0;
        file1000 >> value1000;
        while (!file1000.eof())
        {
                myHeap.InsertMax(max1000Heap, &max1000Num, 3, value1000);
                myHeap.InsertMin(min1000Heap, &min1000Num, 3, value1000);
                file1000 >> value1000;
        }

	int max5000Heap[15000];
        int min5000Heap[15000];
        ifstream file5000("5000nums.txt");
        int value5000;
        int max5000Num = 0;
        int min5000Num = 0;
        file5000 >> value5000;
        while (!file5000.eof())
        {
                myHeap.InsertMax(max5000Heap, &max5000Num, 3, value5000);
                myHeap.InsertMin(min5000Heap, &min5000Num, 3, value5000);
                file5000 >> value5000;
        }

	int max10000Heap[15000];
        int min10000Heap[15000];
        ifstream file10000("10000nums.txt");
        int value10000;
        int max10000Num = 0;
        int min10000Num = 0;
        file10000 >> value10000;
        while (!file10000.eof())
        {
                myHeap.InsertMax(max10000Heap, &max10000Num, 3, value10000);
                myHeap.InsertMin(min10000Heap, &min10000Num, 3, value10000);
                file10000 >> value10000;
        }

  	bool quit = false;
  	while (quit == false)
  	{

    		cout << "********************" << endl;
    		cout << "**       MENU     **" << endl;
    		cout << "********************" << endl;
    		cout << "Choose one operation from the options below:" << endl;
    		cout << "1.  Heapify" << endl;
    		cout << "2.  PQ_Delete" << endl;
    		cout << "3.  PQ_Highest" << endl;
    		cout << "4.  Time_LowestPQ" << endl;
    		cout << "5.  Exit" << endl;
    		cout << endl << endl;
    		int choice;
    		cin >> choice;

    		cout << endl << endl;

    		switch (choice)
    		{
      			case 1 :
	      			{
        			cout << "10 nums \n";
				myHeap.HeapifyMax(max10Heap, max10Num, 3);
        			myHeap.HeapifyMin(min10Heap, min10Num, 3);
				cout << "50 nums \n";
				myHeap.HeapifyMax(max50Heap, max50Num, 3);
                                myHeap.HeapifyMin(min50Heap, min50Num, 3);
				cout << "100 nums \n";
				myHeap.HeapifyMax(max100Heap, max100Num, 3);
                                myHeap.HeapifyMin(min100Heap, min100Num, 3);
				cout << "500 nums \n";
				myHeap.HeapifyMax(max500Heap, max500Num, 3);
                                myHeap.HeapifyMin(min500Heap, min500Num, 3);
				cout << "1000 nums \n";
				myHeap.HeapifyMax(max1000Heap, max1000Num, 3);
                                myHeap.HeapifyMin(min1000Heap, min1000Num, 3);
				cout << "5000 nums \n";
				myHeap.HeapifyMax(max5000Heap, max5000Num, 3);
                                myHeap.HeapifyMin(min5000Heap, min5000Num, 3);
				cout << "10000 nums \n";
				myHeap.HeapifyMax(max10000Heap, max10000Num, 3);
                                myHeap.HeapifyMin(min10000Heap, min10000Num, 3);

        			cout << endl;
        			break;}
      			case 2 :
	      			{
        			cout << "10 nums \n";
                                myHeap.PQ_DeleteMax(max10Heap, &max10Num, 3);
                                myHeap.PQ_DeleteMin(min10Heap, &min10Num, 3);
                                cout << "50 nums \n";
                                myHeap.PQ_DeleteMax(max50Heap, &max50Num, 3);
                                myHeap.PQ_DeleteMin(min50Heap, &min50Num, 3);
                                cout << "100 nums \n";
                                myHeap.PQ_DeleteMax(max100Heap, &max100Num, 3);
                                myHeap.PQ_DeleteMin(min100Heap, &min100Num, 3);
                                cout << "500 nums \n";
                                myHeap.PQ_DeleteMax(max500Heap, &max500Num, 3);
                                myHeap.PQ_DeleteMin(min500Heap, &min500Num, 3);
                                cout << "1000 nums \n";
                                myHeap.PQ_DeleteMax(max1000Heap, &max1000Num, 3);
                                myHeap.PQ_DeleteMin(min1000Heap, &min1000Num, 3);
                                cout << "5000 nums \n";
                                myHeap.PQ_DeleteMax(max5000Heap, &max5000Num, 3);
                                myHeap.PQ_DeleteMin(min5000Heap, &min5000Num, 3);
                                cout << "10000 nums \n";
                                myHeap.PQ_DeleteMax(max10000Heap, &max10000Num, 3);
                                myHeap.PQ_DeleteMin(min10000Heap, &min10000Num, 3);
					
				break;}
      			case 3 :
              			{
				cout << "10 nums \n";
				myHeap.PQ_HighestMax(max10Heap);
				myHeap.PQ_HighestMin(min10Heap);
				cout << "50 nums \n";
                                myHeap.PQ_HighestMax(max50Heap);
                                myHeap.PQ_HighestMin(min50Heap);
				cout << "100 nums \n";
                                myHeap.PQ_HighestMax(max100Heap);
                                myHeap.PQ_HighestMin(min100Heap);
				cout << "500 nums \n";
                                myHeap.PQ_HighestMax(max500Heap);
                                myHeap.PQ_HighestMin(min500Heap);
				cout << "1000 nums \n";
                                myHeap.PQ_HighestMax(max1000Heap);
                                myHeap.PQ_HighestMin(min1000Heap);
				cout << "5000 nums \n";
                                myHeap.PQ_HighestMax(max5000Heap);
                                myHeap.PQ_HighestMin(min5000Heap);
				cout << "10000 nums \n";
                                myHeap.PQ_HighestMax(max10000Heap);
                                myHeap.PQ_HighestMin(min10000Heap);
        			break;}
      			case 4 :
	      			{
				cout << "10 nums \n";
				myHeap.Time_LowestPQMax(max10Heap, max10Num);
				myHeap.Time_LowestPQMin(min10Heap, min10Num);
				cout << "50 nums \n";
                                myHeap.Time_LowestPQMax(max50Heap, max50Num);
                                myHeap.Time_LowestPQMin(min50Heap, min50Num);
				cout << "100 nums \n";
                                myHeap.Time_LowestPQMax(max100Heap, max100Num);
                                myHeap.Time_LowestPQMin(min100Heap, min100Num);
				cout << "500 nums \n";
                                myHeap.Time_LowestPQMax(max500Heap, max500Num);
                                myHeap.Time_LowestPQMin(min500Heap, min500Num);
				cout << "1000 nums \n";
                                myHeap.Time_LowestPQMax(max1000Heap, max1000Num);
                                myHeap.Time_LowestPQMin(min1000Heap, min1000Num);
				cout << "5000 nums \n";
                                myHeap.Time_LowestPQMax(max5000Heap, max5000Num);
                                myHeap.Time_LowestPQMin(min5000Heap, min5000Num);
				cout << "10000 nums \n";
                                myHeap.Time_LowestPQMax(max10000Heap, max10000Num);
                                myHeap.Time_LowestPQMin(min10000Heap, min10000Num);
				cout << endl;
        			break;}
      			case 5:
	      			{
				myHeap.Exit();
				quit = true;
				cout << "Goodbye !" << endl;
				break;}
    				}
	}
  return 0;
}
