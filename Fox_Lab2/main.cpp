#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "linkedList.hpp"
#include "hash.hpp"
using namespace std;


int main()
{
  ifstream file("data.txt");
  HashTable myTable;
  string value;
  file >> value;
  if (value[value.length()-1] == ',')
	  value.pop_back();
  while (!file.eof())
  {
    myTable.insert(value);
    file >> value;
    if (value[value.length()-1] == ',')
          value.pop_back();


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
    cout << "3.  Find" << endl;
    cout << "4.  Print" << endl;
    cout << "5.  Exit" << endl;
    cout << endl;
    int choice;
    cin >> choice;

    cout << endl << endl;

    switch (choice)
    {
      case 1 :
	      {
        cout << "Enter element to be inserted in list: ";
        string elem;
        cin >> elem;
        myTable.insert(elem);
        cout << endl;
        break;}
      case 2 :
	      {
        cout << "Enter an element to be removed: ";
        string elem;
        cin >> elem;
        myTable.Delete(elem);
        break;}
      case 3 :
	      {
        cout << "Enter an element to be found: ";
        string elem;
	cin >> elem;
	myTable.Find(elem);
        break;}
      case 4 :
	      {
        myTable.PrintHash();
        cout << endl;
        break;}
      case 5 :
	      {
	myTable.Exit();
      	quit = true;
        cout << "Goodbye !" << endl;
        break;}
    }
    cout << endl << endl;

  }
  return 0;
}
