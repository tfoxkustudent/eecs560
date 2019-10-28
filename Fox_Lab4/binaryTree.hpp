
#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Node{
        int value;
       Node* left;
       Node* right;
};

class Btree{

public:

Node* root = nullptr;
int numberOfElements = 0;
int binaryRep;
int level;
void AddItem(int x) {
	Node* newNode = new Node();
	newNode->value = x;
	newNode->left = nullptr;
	newNode->right = nullptr;
	Node* p = root;
	bool isInTree = false;
	if(IsInTree(root, x, isInTree) == true)
  	{
    		cout << "Value " << x << " is already in tree, no duplicates allowed" << endl;
    		return;
  	}
	if (numberOfElements == 0) {
		root = newNode;
		numberOfElements++;
		level = 1;
	}
	else {
		if(IsFull()==1){ 
			level++;}
		binaryRep = numberOfElements +1 - (1 << (level -1));
		for (int i=level-1; i >= 1; i--)
		{
			if (i != 1) {
				if ((binaryRep >> (i-1)) % 2 == 0) {
					p = p->left;
                			}
				else {
					p = p->right;
				}
			}
			else {
				if ((binaryRep >> (i-1)) % 2 == 0){
					p->left = newNode;
					numberOfElements++;
					cout<<"Value inserted successfully!"<<endl;
				}	
				else{
					p->right = newNode;
					numberOfElements++;
					cout<<"Value inserted successfully!"<<endl;
				}
				
			}
		}
		
	}
}

int height(){
	return (level - 1);
}



void PrintTreeHeight(){
	cout << height() << endl;
}

bool IsFull(){
	return (((1<<level) -1) == numberOfElements);	
}

bool DeleteIsFull(){
	return (((1<<(level-1)) -1) == numberOfElements);
}

void Delete(){
	Node* p = root;

	binaryRep = numberOfElements - (1 << (level -1));
	int value2delete;
	for (int i= level -1; i >= 1; i--)
	{
		if (i != 1){
			if ((binaryRep >> (i-1)) % 2 == 0) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		else {
			if ((binaryRep >> (i-1)) % 2 == 0){
				value2delete = p->left->value;
				delete p->left;
				p->left = nullptr;
				numberOfElements--;
				cout << "The last value is " << value2delete << ", and it has been deleted" << endl;
			}
			else{
				value2delete = p->right->value;
				delete p->right;
				p->right = nullptr;
				numberOfElements--;
				cout << "The last value is " << value2delete << ", and it has been deleted" << endl;
			}
		}	
	}
	if(DeleteIsFull()==1){level--;}	
}


bool IsInTree(Node* p, int x, bool &isFound)
{
  if (p != nullptr)
  {
    IsInTree(p->left, x, isFound);
    if (p->value == x) {isFound = true;}
    IsInTree(p->right, x, isFound);
  }
  if(isFound != true)
  {
    return false;
  }
  else
    return true;
}


void Leaf(int x){
	Node* p = root;
	bool isLeaf = false;
	if (LeafHelp(p,x,isLeaf)){
		cout << "The node with " << x << " is a leaf node." << endl;
	}
	else{
		cout << "The node with " << x << " is NOT a leaf node." << endl;
	}

}
bool LeafHelp(Node* p, int x, bool &isLeaf){
		
	if (p != nullptr){
	if (p->value == x && p->left == nullptr && p->right == nullptr){
		isLeaf = true;
	}
	
	LeafHelp(p->left, x, isLeaf);
	LeafHelp(p->right, x, isLeaf);
	if (isLeaf != true){
		return false;
	}
	else{
		return true;
	}
	
}
}
void PrintLeaf(){
	Node* p = root;
	PrintLeafHelp(p);
}

void PrintLeafHelp(Node* p){
	if (p->left == nullptr && p->right == nullptr)
                cout << p->value << " ";
	if (p->left != nullptr)
        	PrintLeafHelp(p->left);
        if (p->right != nullptr)
		PrintLeafHelp(p->right);
}

void Preorder(){
	Node* p = root;
	PreorderHelp(p);
}

void PreorderHelp(Node* p){
	cout << p->value << " ";
        if (p->left != nullptr)
		PreorderHelp(p->left);
        if (p->right != nullptr)
		PreorderHelp(p->right);
}
void Postorder(){
	Node* p = root;
	PostorderHelp(p);
}

void PostorderHelp(Node* p){
	if (p->left != nullptr)
		PostorderHelp(p->left);
        if (p->right != nullptr)
		PostorderHelp(p->right);
        cout << p->value << " ";
}

void Inorder(){
	Node* p = root;
	InorderHelp(p);
}

void InorderHelp(Node*p){
	if (p->left != nullptr)
		InorderHelp(p->left);
	cout << p->value << " ";
	if (p->right != nullptr)
		InorderHelp(p->right);
}

void Levelorder(){
	Node* p = root;
	int h = height();
	int i;
	for (i =1; i <= h+1; i++){
		Givenlevel(p,i);
	}
}

void Givenlevel(Node* p, int level){
	if (p == nullptr){return;}
	if (level==1){
		cout << p->value << " ";
	}
	else if (level > 1){
			Givenlevel(p->left,level-1);
			Givenlevel(p->right,level-1);
	}
}

};
#endif
