#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "linkedList.hpp"
#include <string>
#include <iostream>
#include <list>
using namespace std;

struct Table
{
	string name;
	int rating;
	string price;
};
class HashTable
{
  public:
	int mod = 31;
	Table* QuadTable= new Table [mod];
	Table* DoubleTable = new Table [mod];
	int current_load = 0;
 
	void insert(string x, int y, string z)
        {
	for (int i = 0; i < x.length(); i++)
	{
		x[i] = tolower(x[i]);
	}
		int i;
		bool insertQuad = false;
                bool insertDouble = false;
		for (i = 0; i < mod; i++)
		{
			if (QuadTable[i].name == x)
			{
				insertQuad = true;
				cout << "Quadratic probing: " << x << " is duplicated, can't be added to the hash table." << endl;
				
			}
		}
		for (i = 0; i < mod; i++)
		{
			if (DoubleTable[i].name == x)
			{
				insertDouble = true;
				cout << "Double hashing: " << x << " is duplicated, can't be added to the hash table." << endl;
			}
		}
		int hx = Hashfunction(x);
		int j = 0;
		int R = 29;
		int hplusx = 0;
		int hash_value = 0;
		while (insertQuad == false){
			if(QuadTable[hx].name == "")
			{
				QuadTable[hx].name = x;
				QuadTable[hx].rating = y;
				QuadTable[hx].price = z;
                		cout << x << " was inserted successfully at index " << hx << " using quadratic probing" << endl;
				insertQuad = true;
			}	
			else if (j < 32)
			{
				j++;
				hx = (Hashfunction(x) + j *j) % mod;
			}
			else if (j > 32)
			{
			cout << x << " could not be inserted using quadratic probing" << endl;
			insertQuad = true;
			}
			}
		hx = Hashfunction(x);
		hplusx = R - (hx % R);
		i = 0;
		while (insertDouble == false){
			
			if(DoubleTable[hx].name == "")
			{
				DoubleTable[hx].name = x;
				DoubleTable[hx].rating = y;
				DoubleTable[hx].price = z;
				cout << x << " was inserted successfully at index " << hx << " using double hashing" << endl;
				insertDouble = true;
			}
			else if (i < 32)
			{
				i++;
				hx = (hx + i*hplusx) % mod;
			}
			else if (i > 32)
			{
				cout << x << "could not be inserted using double hashing" << endl;
				insertDouble = true;
			}
		}
	}
	

	void Delete(string x)
	{
		bool deleteQuad = false;
		bool deleteDouble = false;
		for (int i = 0; i < mod; i++){
			if (QuadTable[i].name == x){
			deleteQuad = true;
			QuadTable[i].name = "";
			QuadTable[i].rating = 0;
			QuadTable[i].price = "";
			cout << x << " has been successfully deleted from Quadratic Probing Table" << endl;	
			}
		}
		if (deleteQuad == false)
			cout << x << " has been failed to delete from Quadratic Probing Table" << endl;
		for (int i = 0; i < mod; i++){
			if (DoubleTable[i].name == x){
				deleteDouble = true;
				DoubleTable[i].name = "";
				DoubleTable[i].rating = 0;
				DoubleTable[i].price = "";
				cout << x << " has been successfully deleted from Double hashing table" << endl;
			}
		}
		if (deleteDouble == false)
			cout << x << " has been failed to delete from Double Hashing Table" << endl;
              	

		}
	void Print()
	{
		cout << "<OUTPUT FOR QUADRATIC PROBING>" << endl << endl;
		for(int i = 0; i < mod; i ++)
		{
			cout << "INDEX[" << i << "]:   ";
			cout << QuadTable[i].name << ", " << QuadTable[i].rating << ", " << QuadTable[i].price;
			cout << endl;
		}
		cout << "<OUTPUT FOR DOUBLE HASHING>" << endl << endl;
                for(int i = 0; i < mod; i ++)
                {
                        cout << "INDEX[" << i << "]:   ";
                        cout << DoubleTable[i].name << ", " << DoubleTable[i].rating << ", " << DoubleTable[i].price;
                        cout << endl;
                }
	}
	int Hashfunction(string inserted_key)
	{
		int hash_value = 0;
		for( int i = 0; i < inserted_key.length(); i++) 
		{
			hash_value += static_cast<int>(inserted_key[i]);
			
		}
		return hash_value % mod;
	}
	
	void FindByName(string x)
	{
                bool findQuad = false;
                bool findDouble = false;
                for (int i = 0; i < mod; i++){
                        if (QuadTable[i].name == x){
                        findQuad = true;
                        cout << x << " has been found at location " << i << " in the  Quadratic Probing Table" << endl;
                        }
                }
                if (findQuad == false)
                        cout << x << " has not been found in the Quadratic Probing Table" << endl;
                for (int i = 0; i < mod; i++){
                        if (DoubleTable[i].name == x){
                                findDouble = true;
                                cout << x << " has been found at location " << i << " in the Double Hashing Table" << endl;
                        }
                }
                if (findDouble == false)
                        cout << x << " has not been found in the Double Hashing Table" << endl;
	}
	void FindByRating(int rating)
	{
	
		list<string> listofquadnames;
		list<string> listofdoublenames;
		for (int i = 0; i < mod; i++){
			string x;
			if (QuadTable[i].rating == rating){
				x = QuadTable[i].name;
				listofquadnames.push_back(x);
			}
		}
		if (!listofquadnames.empty()){
			cout << "Quadratic probing: ";
			for (string str : listofquadnames)
				cout << str << ",";
			cout << endl;
		}
		else
		{
			cout << "Quadratic probing: No restaurants found by rating: " << rating << endl;
		}
		for (int i = 0; i < mod; i++){
                        string x;
                        if (DoubleTable[i].rating == rating){
                                x = DoubleTable[i].name;
                                listofdoublenames.push_back(x);
                        }
		}
                if (!listofdoublenames.empty()){
                        cout << "Double Hashing: ";
                        for (string str : listofdoublenames)
                                cout << str << ",";
                        cout << endl;
                }
                else
                {
                        cout << "Double Hashing: No restaurants found by rating: " << rating << endl;
                }
	}		
	void SearchByPrice(string price)
	{
		list<string> listofquadnames;
                list<string> listofdoublenames;
                for (int i = 0; i < mod; i++){
                        string x;
                        if (QuadTable[i].price == price){
                                x = QuadTable[i].name;
                                listofquadnames.push_back(x);
                        }
		}
                if (!listofquadnames.empty()){
                        cout << "Quadratic probing: ";
                        for (string str : listofquadnames)
                                cout << str << ",";
                        cout << endl;
                }
                else
                {
                        cout << "Quadratic probing: No restaurants found by price: " << price << endl;
                }
                for (int i = 0; i < mod; i++){
                        string x;
                        if (DoubleTable[i].price == price){
                                x = DoubleTable[i].name;
                                listofdoublenames.push_back(x);
                        }
		}
                if (!listofdoublenames.empty()){
                        cout << "Double Hashing: ";
                        for (string str : listofdoublenames)
                                cout << str << ",";
                        cout << endl;
                }
                else
                {
                        cout << "Double Hashing: No restaurants found by price: " << price << endl;
                }
	}		
           	
	void Exit()
	{
		delete[] QuadTable;
		delete[] DoubleTable;
		
	
	}
    
};

#endif
