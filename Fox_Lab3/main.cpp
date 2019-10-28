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
        string x;
        string z;
        string value;
        file >> value;
        int y;
        int i =1;
        if (value[value.length()-1] == ','){
                value.pop_back();}
        while (!file.eof())
        {
                if (i % 1 == 0){
                        x = value;
			file >> value;
			if (value[value.length()-1] == ','){
                                value.pop_back();}
                        i++;
                }
                if (i % 2 == 0){
                        y = stoi(value);
			file >> value;
			if (value[value.length()-1] == ','){
                                value.pop_back();}
			i++;
                }
                if (i % 3 == 0){
                        z = value;
			file >> value;
			if (value[value.length()-1] == ','){
                                value.pop_back();}
			myTable.insert(x,y,z);
			i = 1;
		}



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
    cout << "3.  FindByName" << endl;
    cout << "4.  FindByRating" << endl;
    cout << "5.  SearchByPrice" << endl;
    cout << "6.  Print" << endl;
    cout << "7.  Exit" << endl;
    cout << endl;
    int choice;
    cin >> choice;

    cout << endl << endl;

    switch (choice)
    {
      case 1 :
	      {
        cout << "Enter restaurant, rating, and price (seperated by spaces): " << endl;
        string x;
	string b;
	string z;
	int y;
        cin >> x;
	cin >> b;
	cin >> z;
	y = stoi(b);
        myTable.insert(x,y,z);
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
        cout << "Enter a name to find: ";
        string name;
        cin >> name;
        myTable.FindByName(name);
        break;}

      case 4 :
	      {
        cout << "Enter a rating to find: ";
        string rating;
	cin >> rating;
	myTable.FindByRating(stoi(rating));
        break;}
      case 5 :
	      {
	cout << "Enter a price to search by: ";
	string price;
	cin >> price;
	myTable.SearchByPrice(price);
	break;}
      case 6 :
	      {
        myTable.Print();
        cout << endl;
        break;}
      case 7 :
	      {
	myTable.Exit();
      	quit = true;
        cout << "Goodbye !" << endl;
        break;}
    }
}
  return 0;
}
