#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include "linkedList.hpp"
#include <string>
#include <iostream>
using namespace std;

class HashTable
{
  public:
	int mod = 5;
	LinkedList<string>* HashTable= new LinkedList<string> [mod];
	int current_load = 0;
 
	void insert(string x)
        {
	for (int i = 0; i < x.length(); i++)
	{
		x[i] = tolower(x[i]);
	}
	if (Find(x) == false)
	{
		HashTable[Hashfunction(x)].Insert(x);
		current_load ++;
		cout << x << " was inserted successfully" << endl;
	}
	else
	{
		cout << x << " was not added successfully" << endl;
	}
	float load_max = 0;
	load_max = (float)current_load / (float)mod;
	if (load_max > 1)
	{
		cout << " current load greater than current mod... rehashing ... " << endl;
		rehash();
	}
	}
	void Delete(string x)
	{
	for (int i = 0; i < x.length(); i++)
                x[i] = tolower(x[i]);
	if (Find(x) == true)
        {
                HashTable[Hashfunction(x)].Delete(x);
                current_load --;
		cout << x << " was deleted successfully" << endl;
        }
        else
        {
                cout << x << " was not deleted successfully" << endl;
        }


	}
	void PrintHash()
	{
		for(int i = 0; i < mod; i ++)
		{
			cout << i << ":";
			HashTable[i].Print();
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
	void rehash()
	{
		string myStr;
		int old_mod = mod;
		mod = NextPrime(mod*2);
		LinkedList<string>* NewHashTable = new LinkedList<string> [mod];
		for (int i =0 ; i < old_mod; i ++)
		{
			for (int j = 0; j < HashTable[i].Size(); j++)
			{
				myStr = HashTable[i].At(j);
				NewHashTable[Hashfunction(myStr)].Insert(myStr);
			}
		}
		delete[] HashTable;
		HashTable = NewHashTable;
		
		cout << "hash table is rehashed" << endl;
	}
	bool Find(string x)
	{
		for (int i = 0; i < x.length(); i++)
                	x[i] = tolower(x[i]);
		if (HashTable[Hashfunction(x)].Contains(x))
		{
			cout << x << " is found at location " << Hashfunction(x) << endl;
			return true;
		}
		else 
		{
			cout << x << " is not found" << endl;
			return false;
		}
	}
	bool isPrime(int num)
	{
    	for (int i = 2; i <= num/2; i++)
    	{
        	if (num % i == 0)     
            		return false;
    	}

    	return true;
	}
	int NextPrime(int num)
	{
    	int nextPrime = num;
    	bool found = false;

    	while (!found)
    	{
        	nextPrime++;
        	if (isPrime(nextPrime))
            	found = true;
    	}

    	return nextPrime;
	}

	void Exit()
	{
		delete[] HashTable;
		
	
	}
    
};

#endif
