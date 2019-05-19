//hash.h
#include <string>
#include <iostream>
#include<cstdlib>

using namespace std;

//#ifndef HASH_H
//#define HASH_H

class hashClass{
private:
    static const int tableSize =10;

struct item{            //item struct which contatins a word and a pointer to a item, Node
    string word;
    item* next;
};

item* HashTable[tableSize];     //create array Hashtable of type item ptr
                                //so each entry contains ptr to a item
public:
    hashClass();
int HashKey(string key);
void AddItem(string word);
int NumberOfItemsInIndex(int index);
bool FindWord(string word);
void deleteItem(string word);



};