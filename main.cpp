//main ransome
// HAVE TO COMPILE WITH "g++ -std=c++11 main.cpp hash.cpp -o main"
#include <string>
#include <iostream>
#include<cstdlib>
#include "hash.h"
#include <vector>
using namespace std;

//test
bool RansomNoteSuccess(vector<string> magazine,vector<string> ransom)
{
hashClass hasho; //create hash called hasho
for(int i=0;i<magazine.size();i++) //fill hashtable with magazine
{
hasho.AddItem(magazine[i]);
}

for(int i=0;i<ransom.size();i++)
{
if(hasho.FindWord(ransom[i])==false)
{
    return false;
}

}

return true;
}


int main()
{
    cout<<"Please enter the number of words in magazine, followed by the number of words in ransom note"<<endl;
int m,n;
cin>>m>>n;
//cout<<"m= "<<m<<" n= "<<n<<endl;
vector<string> magazine(m), ransom(n);
cout<<"please write the "<< m<< " words in the magazine, then hit enter "<<endl;
for(int i=0;i<m;i++)
{
    cin>>magazine[i];
    //cout<<magazine[i]<<endl;
}
cout<<"please write the "<<n<<" words in ransom note, then hit enter"<<endl;
for(int i=0;i<n;i++)
{
    cin>>ransom[i];
   // cout<<ransom[i]<<endl;
}

if(RansomNoteSuccess(magazine,ransom)==true)
{
    cout<<"Success! Can create ransom note with given magazine!"<<endl;
}
else
{
cout<<"Fail! Cannot create ransom note with given magazine!"<<endl;
}











/*
   /*
    int index;
    hashClass hashObj;
    index= hashObj.HashKey("johhny");

cout<<"index= "<<index<<endl;


hashClass hashy;
hashy.AddItem("ballsdeep");
hashy.AddItem("ballsdeep");
int x=hashy.NumberOfItemsInIndex(0);
cout<<x<<endl;
/*for(int i=0;i<10;i++)
{
    int x=hashy.NumberOfItemsInIndex(i);
    cout<<x<<endl;
}

*/


}