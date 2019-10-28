#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Heap.hpp"
using namespace std;


int main()
{
	Heap myHeap;
	int maxHeap[15000];
	int minHeap[15000];
	ifstream file("data.txt");
        int value;
	int maxNum = 0;
	int minNum = 0;
        file >> value;
        while (!file.eof())
        {
		myHeap.InsertMax(maxHeap, &maxNum, 3, value);
		myHeap.InsertMin(minHeap, &minNum, 3, value);
		file >> value;
	}

  	bool quit = false;
  	while (quit == false)
  	{

    		cout << "********************" << endl;
    		cout << "**       MENU     **" << endl;
    		cout << "********************" << endl;
    		cout << "Choose one operation from the options below:" << endl;
    		cout << "1.  Insert" << endl;
    		cout << "2.  Delete" << endl;
    		cout << "3.  PQ_Highest" << endl;
    		cout << "4.  PQ_Lowest" << endl;
    		cout << "5.  Level_Order" << endl;
    		cout << "6.  Time_LowestPQ" << endl;
    		cout << "7.  Exit" << endl;
    		cout << endl << endl;
    		int choice;
    		cin >> choice;

    		cout << endl << endl;

    		switch (choice)
    		{
      			case 1 :
	      			{
        			cout << "Please enter the value which you want to enter into the tree. " << endl << endl;
				int y;
				cin >> y;
				cout << endl;
        			myHeap.InsertMax(maxHeap, &maxNum, 3, y);
				cout << y << " was inserted successfully into max heap\n";
        			myHeap.InsertMin(minHeap, &minNum, 3, y);
				cout << y << " was inserted successfully into min heap\n";
        			cout << endl;
        			break;}
      			case 2 :
	      			{
				cout << myHeap.DeleteMin(minHeap, &minNum, 3) << " was deleted from min heap\n"; 
				cout << myHeap.DeleteMax(maxHeap, &maxNum, 3) << " was deleted from max heap\n";
        			break;}
      			case 3 :
              			{
				cout << myHeap.PQ_HighestMax(maxHeap) << " is the element with highest priority in max heap\n";
				cout << myHeap.PQ_HighestMin(minHeap) << " is the element with highest priority in min heap\n";
        			break;}

      			case 4 :
	      			{
				cout << myHeap.PQ_LowestMax(maxHeap, maxNum) << " is the element with lowest priority in max heap\n";
				cout << myHeap.PQ_LowestMin(minHeap, minNum) << " is the element with lowest priority in min heap\n";
				cout  << endl;
				break;}
      			case 5 :
	      			{
				cout << " Level order for Max Heap ";
				myHeap.Level_Order(maxHeap, maxNum);
				cout << "\n Level order for Min Heap ";
				myHeap.Level_Order(minHeap, minNum);
				cout << endl;
        			break;}
      			case 6 :
	      			{
				myHeap.Time_LowestPQMax(maxHeap, maxNum);
				myHeap.Time_LowestPQMin(minHeap, minNum);
				cout << endl;
        			break;}
      			case 7:
	      			{
				myHeap.Exit();
				quit = true;
				cout << "Goodbye !" << endl;
				break;}
    				}
	}
  return 0;
}
