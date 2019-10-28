#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "binaryTree.hpp"
using namespace std;


int main()
{
        Btree bTree;
	ifstream file("data.txt");
        int value;
        file >> value;
        while (!file.eof())
        {
		bTree.AddItem(value);
		file >> value;
	}

  bool quit = false;
  while (quit == false)
  {

    cout << "********************" << endl;
    cout << "**       MENU     **" << endl;
    cout << "********************" << endl;
    cout << "Choose one operation from the options below:" << endl;
    cout << "1.  IsFull" << endl;
    cout << "2.  AddItem" << endl;
    cout << "3.  Delete" << endl;
    cout << "4.  Leaf" << endl;
    cout << "5.  PrintLeaf" << endl;
    cout << "6.  PrintTreeHeight" << endl;
    cout << "7.  Preorder" << endl;
    cout << "8.  Postorder" << endl;
    cout << "9.  Inorder" << endl;
    cout << "10. Levelorder" << endl;
    cout << "11. Exit" << endl;
    cout << endl;
    int choice;
    cin >> choice;

    cout << endl << endl;

    switch (choice)
    {
      case 1:
	      {
	if (bTree.IsFull() == 1){
		cout << "Output: True" << endl;;
	}
	else{
	cout << "Output: False" << endl;
	}
	break;}
      case 2 :
	      {
        cout << "Please enter the value which you want to enter into the tree. " << endl;
	int y;
	cin >> y;
        bTree.AddItem(y);
        cout << endl;
        break;}
      case 3 :
	      {
	bTree.Delete();
        break;}
      case 4 :
              {
        cout << "Please enter the value which you want to test as a leaf node.";
        int y;
        cin >> y;
        bTree.Leaf(y);
        break;}

      case 5 :
	      {
      	cout << "The leaf nodes are: ";
	bTree.PrintLeaf();
	cout  << endl;
	break;}
      case 6 :
	      {
        cout << "The height of the tree is: ";
	bTree.PrintTreeHeight();
	cout << endl;
        break;}
      case 7 :
	      {
        cout << "Printing in Pre-Order - ";
 	bTree.Preorder();
	cout << endl;
        break;}
      case 8:
	     {
	cout << "Printing in Post-Order - ";
 	bTree.Postorder();
	cout << endl;
	break;}
      case 9:
	     {
	cout << "Printing in In-Order - ";
	bTree.Inorder();
	cout << endl;
	break;}
      case 10:
	      {
	cout << "Printing in Level-Order - ";
	bTree.Levelorder();
	cout << endl;
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
