#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Heap.hpp"
using namespace std;


int main()
{
	Heap myHeap;
	int MinMaxHeap[15000];
	int size = 0;
	ifstream file("data.txt");
        string value;
        file >> value;
        if (value[value.length()-1] == ','){
                value.pop_back();}
	while (!file.eof())
        {
		myHeap.Insert(stoi(value), MinMaxHeap, size);
		file >> value;
		if (value[value.length()-1] == ','){
          		value.pop_back();}

	}

  	bool quit = false;
  	while (quit == false)
  	{

    		cout << "********************" << endl;
    		cout << "**       MENU     **" << endl;
    		cout << "********************" << endl;
    		cout << "Choose one operation from the options below:" << endl;
    		cout << "1.  BuildHeap" << endl;
    		cout << "2.  Insert" << endl;
    		cout << "3.  Delete" << endl;
    		cout << "4.  MinLevelElements" << endl;
    		cout << "5.  MaxLevelElements" << endl;
    		cout << "6.  Exit" << endl;
    		cout << endl << endl;
    		int choice;
    		cin >> choice;

    		cout << endl << endl;

    		switch (choice)
    		{
			case 1 :
				{
				myHeap.BuildHeap(MinMaxHeap, size);
				myHeap.levelorder(MinMaxHeap, size);
				break;
				}
			case 2 :
	      			{
        			cout << "Enter the element to be inserted: ";
				int y;
				cin >> y;
				cout << endl;
        			myHeap.Insert(y,MinMaxHeap, size);
				cout << y << " has been inserted successfully\n";
        			cout << endl;
        			break;}
      			case 3 :
	      			{
				cout << "Enter element to be deleted: ";
			       	int y;
				cin >> y;
				cout << endl;
				myHeap.Delete(y,MinMaxHeap, &size);	
        			break;}
      			case 4 :
              			{
        			myHeap.MinLevelElements(MinMaxHeap, size);
				break;}
      			case 5 :
	      			{
				myHeap.MaxLevelElements(MinMaxHeap, size);
				break;}
      			case 6 :
	      			{
				myHeap.Exit();
				quit = true;
				cout << "Goodbye !" << endl;
				break;}
    				}
	}
  return 0;
}
