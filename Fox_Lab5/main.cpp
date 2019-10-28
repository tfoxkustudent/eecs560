#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "bST.hpp"
using namespace std;


int main()
{
        bST bST;
	ifstream file("data.txt");
        char value;
        file >> value;
        while (!file.eof())
        {
		bST.AddItem(value);
		file >> value;
	}

  bool quit = false;
  while (quit == false)
  {

    cout << "********************" << endl;
    cout << "**       MENU     **" << endl;
    cout << "********************" << endl;
    cout << "Choose one operation from the options below:" << endl;
    cout << "1.  AddItem" << endl;
    cout << "2.  Delete" << endl;
    cout << "3.  Leaf" << endl;
    cout << "4.  PrintLeaf" << endl;
    cout << "5.  PrintTreeHeight" << endl;
    cout << "6.  Preorder" << endl;
    cout << "7.  Postorder" << endl;
    cout << "8.  Inorder" << endl;
    cout << "9.  Levelorder" << endl;
    cout << "10. SearchItem" << endl;
    cout << "11. Exit" << endl;
    cout << endl;
    int choice;
    cin >> choice;

    cout << endl << endl;

    switch (choice)
    {
      case 1 :
	      {
        cout << "Please enter the value which you want to enter into the tree. " << endl;
	char y;
	cin >> y;
        bST.AddItem(y);
        cout << endl;
        break;}
      case 2 :
	      {
	cout << "Please enter the value which you want to delete from the tree. " << endl;
	char y;
	cin >> y;
	bST.Delete(y);
        break;}
      case 3 :
              {
        cout << "Please enter the value which you want to test as a leaf node.";
        int y;
        cin >> y;
        bST.Leaf(y);
        break;}

      case 4 :
	      {
      	cout << "The leaf nodes are: ";
	bST.PrintLeaf();
	cout  << endl;
	break;}
      case 5 :
	      {
        cout << "The height of the tree is: ";
	bST.PrintTreeHeight();
	cout << endl;
        break;}
      case 6 :
	      {
        cout << "Printing in Pre-Order - ";
 	bST.Preorder();
	cout << endl;
        break;}
      case 7:
	     {
	cout << "Printing in Post-Order - ";
 	bST.Postorder();
	cout << endl;
	break;}
      case 8:
	     {
	cout << "Printing in In-Order - ";
	bST.Inorder();
	cout << endl;
	break;}
      case 9:
             {
        cout << "Printing in Level-Order - ";
        bST.Levelorder();
        cout << endl;
        break;}
      case 10:
	      {
	cout << "Enter a value to check in the tree: " << endl;
	char x;
	cin >> x;
	if (bST.Contains(x) == 1){
		cout << " The Character is present in the tree. " << endl;
	}
 	else {
		cout << " The Character is not present in the tree. " << endl;
	}
        break;}
      case 11:
	      {
	//Exit();
	quit = true;
	cout << "Goodbye !" << endl;
	break;}
    }
}
  return 0;
}
