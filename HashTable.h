/*
 *  HashTable.h
 *  Fahim Rashid
 *  12/1/24
 *
 *  CS 15 Project 4 Gerp
 *
 *  interface for HashTable
 *
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <list>
#include <string>
#include <vector>
#include <utility>
#include <functional>
#include <cstring>
#include <iostream>
#include <cctype>
#include <set>
using namespace std; 
struct Node;
struct SameWordNode;

class HashTable{
    public: 

    HashTable();
    // ~HashTable();
    void find(string key, ostream& output, bool IfSense);
    
    int getSize(); 
    vector<string> getFile() const; 
    vector<vector<string>> getDirectory() const;
    void insert(Node node); 
    void insert_hash_in(int index, Node node, string wordlower);
    int bucketsLoaded; 

    struct Node 
    {
        string word;
        //<file,line> number
        vector<pair<int,int>> occurances;
    };

    //struct that contains all variation of a word
    struct SameWordNode {
        string wordInsens; 
        vector<Node>SameWordList; 
    };

    //We need a function to actually read in files here
    SameWordNode formLinkNode(string word, Node occur);
    Node formNode(int LineNum, int FileNum, string word); 
    void insert(Node node); 
    void insert_hash_in(int index, Node node, string wordlower);
    int Dir_Num = 0; 
    vector<vector<string>> DIRECTORY;
    vector<string> Dir_Path; 
    private: 
    
    //directory
    vector<string> FILE;
    //  For all words and values
    vector<list<SameWordNode>>Table; 
    // If collisions happen we add on to this
    list<vector<SameWordNode>>WordList;
    void printNode(Node node); 
    const int TableSize = 1000; 
    void expand(); 
    bool isEqual(pair<int,int> pair1, pair<int,int> pair2);
};
#endif