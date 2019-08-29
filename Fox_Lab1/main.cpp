#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "linkedList.hpp"
using namespace std;

int main()
{
  ifstream file("data.txt");

  LinkedList<int> myList;
  int value;
  file >> value;
  while (!file.eof())
  {
    myList.Insert(value);
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
    cout << "3.  Find smallest number" << endl;
    cout << "4.  Find largest number" << endl;
    cout << "5.  Average of numbers" << endl;
    cout << "6.  Merge2Lists" << endl;
    cout << "7.  Print" << endl;
    cout << "8.  ReverseList" << endl;
    cout << "9.  Exit" << endl;

    int choice;
    cin >> choice;
    string mystr;
    int arr[] = {};

    cout << endl << endl;

    switch (choice)
    {
      case 1 :
        cout << "Enter element to be inserted in list: ";
        int element;
        cin >> element;
        myList.Insert(element);
        cout << endl;
        break;
      case 2 :
        cout << "Enter the number to be deleted: ";
        int number;
        cin >> number;
        myList.Delete(number);
        break;
      case 3 :
        cout << "Smallest number: " << myList.Smallest() << endl;
        break;
      case 4 :
        cout << "Largest number: " << myList.Largest() << endl;
        break;
      case 5 :
        cout << "Average: " << myList.Average() << endl;
        break;
      case 6 :
        {
        cin.ignore();
        char newList[256];
        cout << "Enter a new list to be merged" << endl << endl;
        LinkedList<int> sortedList;
        cin.getline(newList, 256);
        string newString(newList);
        stringstream streamedString(newString);
        int insertNum;
        while(!streamedString.eof())
        {
            streamedString >> insertNum;
            myList.Insert(insertNum);
        }
        int size = myList.Size();
        int smallestNum;
        for(int i = 0; i < size; i++)
        {
            smallestNum = myList.Smallest();
            myList.Delete(smallestNum);
            sortedList.Insert(smallestNum);
        }
        int smallestSorted;
        for(int i = 0; i < size; i++)
        {
            smallestSorted = sortedList.Smallest();
            sortedList.Delete(smallestSorted);
            myList.Insert(smallestSorted);
        }
        cout << "Merged List: ";
        myList.Print();
        break;
        }
      case 7 :
        cout << "List: ";
        myList.Print();
        cout << endl;
        break;
      case 8 :
      {
        LinkedList<int> reversedList;
        int size = myList.Size();
        int lastNum;
        for(int i = 0; i < size; i++)
        {
          lastNum = myList.GetLast();
          myList.Delete(lastNum);
          reversedList.Insert(lastNum);
         }
         int reversedNum;
         for(int i = 0; i < size; i++)
         {
            reversedNum = reversedList.GetFirst();
            reversedList.Delete(reversedNum);
            myList.Insert(reversedNum);
         }
         cout << "List: ";
         myList.Print();
        break;
        }
      case 9 :
        quit = true;
        cout << "Goodbye !" << endl;
        break;

    }

    cout << endl << endl;

  }
  return 0;
}
