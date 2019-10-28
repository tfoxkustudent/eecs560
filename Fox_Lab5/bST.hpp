
#ifndef BINARY_TREE_HPP
#define BINARY_TREE_HPP

#include <iostream>
#include <string>
#include <fstream>
using namespace std;


struct Node{
        char value;
       Node* left;
       Node* right;
};

class bST{

public:

Node* root = nullptr;
int numberOfElements = 0;

void AddItem(char x)
{       
        if (root == nullptr)
        {       
                root = new Node;
                root->value = x;
                numberOfElements++;
		cout << " The element was inserted successfully. " << endl;
        }
        else
        {       
                RecursivePush(x, root);
        }
}

void RecursivePush(char x, Node* ptrCurrent)
{       
        if (x < ptrCurrent->value)
        {       
                if (ptrCurrent->left == nullptr)
                {       
                        ptrCurrent->left = new Node;
                        ptrCurrent->left->value = x;
                        numberOfElements++;
			cout << " The element was inserted successfully. " << endl;
                
                }
                else
                {       
                        RecursivePush(x, ptrCurrent->left);
                }
        }
        else if (x >= ptrCurrent->value)
        {       
                if (ptrCurrent->right == nullptr)
                {       
                        ptrCurrent->right = new Node;
                        ptrCurrent->right->value = x;
                        numberOfElements++;
			cout << " The element was inserted successfully. " << endl;
                }
                else
                {       
                        RecursivePush(x, ptrCurrent->right);
                }
        }
}


void PrintTreeHeight(){
	cout << (GetHeight()-1) << endl;
}

void Delete(char x){

 	Node* deleteMe = FindNode(x);
	if (Contains(x) == 0)
	{
		cout << " Delete failed.  Element not present in tree" << endl;
		return;
	}
	
        if (deleteMe == nullptr)
        {
                cout << "deleteMe is nullptr" << endl << endl;
                return;
        }
        Node* parent = FindParentOfNode(x);
        bool isLeftNode = (parent->left == deleteMe);
	
	
        if (deleteMe->left == nullptr && deleteMe->right == nullptr)
        {
                DeleteNode_NoChildren(deleteMe, parent, isLeftNode);
        }
        else if (deleteMe->left == nullptr)
        {
                DeleteNode_RightChild(deleteMe, parent, isLeftNode);
        }
        else if (deleteMe->right == nullptr)
        {
                DeleteNode_LeftChild(deleteMe, parent, isLeftNode);
        }
        else
        {
                DeleteNode_TwoChildren(deleteMe, parent, isLeftNode);
        }
}

void DeleteNode_NoChildren(Node* deleteMe, Node* parent, bool isLeftNode)
{
        if (deleteMe == root)
        {
                root = nullptr;
        }
        else if (deleteMe->value < parent->value)
        {
                parent->left = nullptr;
        }
        else if (deleteMe->value > parent->value)
        {
                parent->right = nullptr;
        }

        delete deleteMe;
        numberOfElements--;
	cout << "Deletion was successful" << endl;
	return;
}

void DeleteNode_LeftChild(Node* deleteMe, Node* parent, bool isLeftNode)
{
        if (deleteMe == root)
        {
                root = nullptr;
        }
        else if (deleteMe == parent->left)
        {
                parent->left = deleteMe->left;
        }
        else if (deleteMe == parent->right)
        {
                parent->right = deleteMe->right;
        }

        deleteMe->left = nullptr;
        deleteMe->right = nullptr;
        delete deleteMe;
        numberOfElements--;
	cout << "Deletion was successful" << endl;
	return;
}

void DeleteNode_RightChild(Node* deleteMe, Node* parent, bool isLeftNode)
{
        if (deleteMe == root)
        {
                root = nullptr;
        }
        else if (deleteMe == parent->left)
        {
                parent->left = deleteMe->right;
        }
        else if (deleteMe == parent->right)
        {
                parent->right = deleteMe->left;
        }

        deleteMe->left = nullptr;
        deleteMe->right = nullptr;
        delete deleteMe;
        numberOfElements--;
	cout << "Deletion was successful" << endl;
	return;
}

void DeleteNode_TwoChildren(Node* deleteMe, Node* parent, bool isLeftNode)
{
        Node* tempNode = deleteMe->right;
        Node* successor = deleteMe;
        Node* successorParent = deleteMe;

        while (tempNode != nullptr)
        {
                successorParent = successor;
                successor = tempNode;
                tempNode = tempNode->left;
        }
        if (successor != deleteMe->right)
        {
                successorParent->left = successor->right;
                successor->right = deleteMe->right;
	}
        if (deleteMe == root)
        {
                root = successor;
        }
        else if (deleteMe == parent->left)
        {	
                deleteMe = parent->left;
                parent->left = successor;
        }
        else if (deleteMe == parent->right)
        {
                deleteMe = parent->right;
                parent->right = successor;
        }
        successor->left = deleteMe->left;
        deleteMe->left = nullptr;
        deleteMe->right = nullptr;
        delete deleteMe;
        numberOfElements--;
	cout << "Deletion was successful" << endl;
	return;
}

bool Contains(char x)
{
	Node* p = root;
        return RecursiveContains(x, p);
}

bool RecursiveContains(char x, Node* ptrCurrent)
{
        if (ptrCurrent == nullptr)
        {
                return false;
        }

        if (ptrCurrent->value == x)
        {
                return true;
        }

        if (x < ptrCurrent->value)
        {
                RecursiveContains(x, ptrCurrent->left);
        }
        else
        {
                RecursiveContains(x, ptrCurrent->right);
        }
}

Node* FindNode(char x)
{       
	Node* p = root;
        return RecursiveFindNode(x, p);
}

Node* RecursiveFindNode(char x, Node* ptrCurrent)
{
        if (ptrCurrent == nullptr)
        {
                return nullptr;
        }
        else if (x == ptrCurrent->value)
        {
                return ptrCurrent;
        }
        else if (x < ptrCurrent->value)
        {
                RecursiveFindNode(x, ptrCurrent->left);
        }
        else if (x > ptrCurrent->value)
        {
                RecursiveFindNode(x, ptrCurrent->right);
        }
}

Node* FindParentOfNode(char x)
{
        if (root == nullptr)
        {
		return nullptr;
        }
        Node* ptrCurrent = root;
        Node* ptrPrevious = nullptr;

        while (ptrCurrent->value != x)
        {
                ptrPrevious = ptrCurrent;

                if (x < ptrCurrent->value)
                {
                        ptrCurrent = ptrCurrent->left;
                }
                else
                {
                        ptrCurrent = ptrCurrent->right;
                }

                if(ptrCurrent == nullptr)
                {
                        return nullptr;
                }

        }
                        return ptrPrevious;


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
        int h = GetHeight();
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


int GetHeight()     // done
{
        return GetHeightR(root);
}

int GetHeightR(Node* p)
{
	if (p == nullptr)  
        	return 0;  
    	else
    	{  
        	/* compute the depth of each subtree */
        	int lDepth = GetHeightR(p->left);  
        	int rDepth = GetHeightR(p->right);  
      
        	/* use the larger one */
        	if (lDepth > rDepth) { 
            		return(lDepth+1);
	      	}	
        	else {
			return(rDepth+1);
		}	
    }  
}


};
#endif
