#ifndef __PROCESSING_H
#define __PROCESSING_H
/*
 *  processing.h
 *  Fahim Rashid
 *  12/1/24
 *
 *  CS 15 Project 4 Gerp
 *
 *  processing.h file
 *
 */
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>

#include "FSTree.h"
using namespace std;

string stripNonAlphaNum(string input);
void traverseDirectory(string tree);
// void traverseDirectory(FSTree tree);
void traverseHelper(DirNode *curr, string path);

#endif 