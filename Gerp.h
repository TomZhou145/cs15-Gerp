/*
 *  Gerp.h
 *  Fahim Rashid
 *  12/1/24
 *
 *  CS 15 Project 4 Gerp
 *
 *  interface for Gerp
 *
 */

#ifndef GERP_H
#define GERP_H

#include <istream>
#include <string>
#include <iostream>
#include <fstream> 
#include <stdexcept>
#include "FSTree.h"
#include "HashTable.h"
using namespace std;

class Gerp{

public:
    Gerp(const string &rootName); 
    // ~Gerp(); 
void command_execution(const string &inputDirectory, const string &outputFile);
void read_in_text(string directory); 

void search(string word, ofstream &ofile, bool ifSens); 

void readFile(string FileName, string Path); 
string stringOut(pair<int,int> occurances); 
private: 
// void traverseHelper(DirNode *curr, string path);
// void traverseDirectory(FSTree tree);
HashTable Map; 
FSTree directory; 
// void read_in_text_helper();
int filesLoaded = 0; 
string stripNonAlphaNum(string input); 
void traverseDirectory(string directory); 
void traverseHelper(DirNode *curr, string path);

};

#endif