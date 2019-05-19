//hash.cpp


#include <string>
#include <iostream>
#include<cstdlib>
#include "hash.h"
using namespace std;

hashClass::hashClass()
{
    for(int i=0;i<tableSize;i++)
    {
        HashTable[i]= new item;
        HashTable[i]->word ="empty";//intialize each entry in hash table to "empty" and set ptr to NULL
        HashTable[i]->next=NULL;
    }
}

void hashClass::AddItem(string word)    //add item into hashtable
{
    int index= HashKey(word); //get key or index for the word

    if(HashTable[index]->word =="empty")    //if that index in hash table is still empty, then input the word into that index
    {
    HashTable[index]->word= word;
    }

    else //if that hash table index is full, then there is a collision, need chain addressing
    {
        item* Ptr = HashTable[index];   //create pointer pointing to item in index
        item* n= new item; //creating new item, "n", that will store overlapped word, setting its ptr to NULL
        n->word= word;
        n->next=NULL;

        while(Ptr->next !=NULL) //checking the next pointer of the index, if the next ptr is not NULL then not at the end of index, there are more "inputs" in index
        {
            Ptr=Ptr->next; //cycle through all the entries in the index until reach the last one where next=NULL
        }
        Ptr->next=n;//set last ptr of index to n item holding new information and whose next ptr is NULL, linking it to the rest of chain at the current index
    }

}

int hashClass::HashKey(string key)  //Hashkey implementation, key is generated based on ascii addition of chars in word
{
    int hash=0;
    int index;

    for(int i=0;i<key.length();i++)
    {
        hash=hash+(int)key[i]; //(int)key[i] gives ascii value of char at key[i]
       // cout<<"hash= "<<hash<<endl;
    }
    index= hash % tableSize;
    return index;


}

int hashClass::NumberOfItemsInIndex(int index)// counts the # of items in a sepecified index
{
    int count=0;
    if(HashTable[index]->word =="empty") // if word in given index is initialized "empty", then nothing has ever been added so return count which =0
    {
        return count;
    }
    else // if word is not empty, then at least 1 item has been added to index
    {
        count++;
        item* Ptr= HashTable[index]; //create ptr pointing to given index

        while(Ptr->next !=NULL) //if Ptr->next is not Null, then there are still more items in index
        {
            count++; //increase count and set Ptr to next Ptr which is pointed at next item in index,
            Ptr=Ptr->next; //once next =NULL, then reach end of items in index, leave loop.
        }
    }
    return count;
}

bool hashClass::FindWord(string word) //work in progress
{
    int index= HashKey(word); //finds the key that word would be stored in, so if word is in table, it should be at this index
    bool foundWord=false;
    
    item*Ptr = HashTable[index];
    while(Ptr != NULL) //cycle through index depth
    {
        if(Ptr->word ==word) //if word in index =word then foundWord=true
        {
            foundWord=true;
        }
        Ptr=Ptr->next;
    }
    if(foundWord==true) //if found word=true then need to delete word from index to accomidate repeats
    {
        deleteItem(word);
    }
    return foundWord; //function is set to void right now, change to bool
}

void hashClass::deleteItem(string word)
{
    int index= HashKey(word);
    item* deletePtr;
    item* Ptr1;
    item* Ptr2;


    if(HashTable[index]->word==word && HashTable[index]->next ==NULL) //if item with word is the only item in index, then just rename word to empty to delete
    {
        HashTable[index]->word ="empty";
    }

    else if(HashTable[index]->word==word) //if item with word is first item in the index, but there are other items in that index also.
    {
        deletePtr= HashTable[index];
        HashTable[index]=HashTable[index]->next; //sets the start of the index at the next item, unlinking the word we want to delete
        delete deletePtr; //deletes the deletePtr
    }
    else //item with word is not first item
    {
        Ptr1= HashTable[index]->next;
        Ptr2= HashTable[index];

        while(Ptr1 !=NULL &&Ptr1->word != word)// while Ptr1 != NULL or contain the word, cycle through index with Ptr 2 trailing
        {
            Ptr2=Ptr1;  
            Ptr1=Ptr1->next;
        }
        deletePtr= Ptr1; //Ptr 1 is currently pointing to item with word, and Ptr 2 is pointing to item before it
        Ptr1=Ptr1->next; // set Ptr1 to next item, the one after the item with the word
        Ptr2->next=Ptr1;// set the NEXT Ptr of Ptr2 (which was the item before the item containing the word) to Ptr 1, effectlvly unlinking the item with the word
        delete deletePtr;
    }
}