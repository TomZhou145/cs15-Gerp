/*
 *  Gerp.cpp
 *  Fahim Rashid Tom Zhou
 *  12/1/24
 *
 *  CS 15 Project 4 Gerp
 *
 *  implementation for Gerp
 *
 */

#include "Gerp.h"
#include "FSTree.h"
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>

//Gerp Constructor
//input: the naeme of the directory
Gerp::Gerp(const string &rootName){
//    try{
//     FSTree Directory(rootName); 
//     directory = Directory; 
//    }catch(const runtime_error &e){
//     cerr << "Could not build index, reason:\nDirectory \" ";
//     cerr << rootName << "\" not found: could not build tree\n"; 
//     exit(EXIT_FAILURE); 
//    }

    read_in_text(rootName); 
}

//command_execution
//function: command loop for the program
//input: the string of input and output directory
//output: none
void Gerp::command_execution(const string &inputDirectory, 
const string &outputFile){
    ofstream ofile(outputFile);
    if(ofile.fail()){
        //ADD THINGS HERE
        exit(EXIT_FAILURE);
    }
    string cmd;
    cout << "Query? "; 
    while(cin >> cmd and cmd != "@q" and cmd != "@quit"){
        cout << "Query? ";
       if(cmd == "@i" or cmd == "@insensitive"){
        cin >> cmd; 
        search(stripNonAlphaNum(cmd),ofile,false); 
       }
       else if(cmd == "@f")
        {
            string newOutputFile;
            cin >> newOutputFile;
            ofile.close();
            ofile.open(newOutputFile);
             if(ofile.fail()){
                //ADD THINGS HERE
                exit(EXIT_FAILURE);
            }
            
        }
        else
        {
            //regular case
            search(stripNonAlphaNum(cmd), ofile, true); 
        }
    }
    cout << "Goodbye! Thank you and have a nice day." << endl;
}

//search
//function: search and output the correct word's place in the directory
//input: the word, the output filestream, bool if Sens (true for sensitive,
//false for insensitive)
//output: none
void Gerp::search(string word, ofstream &ofile, bool ifSens)
{
        Map.find(word, ofile, ifSens);
    return; 
}

//read_in_text
//function: bounce function to read-in text
//input: none
//output: none
void Gerp::read_in_text(string directory)
{
    traverseDirectory(directory); 
    return; 
}

/*
 * name:      stripNonAlphaNum
 * purpose:  takes away all nonalpha nums from an input
 * arguments: string input
 * returns:   string of the finalized string
 * effects:   none
 */
string Gerp::stripNonAlphaNum(string input){
    int length = input.length() - 1; 
    //empty case
    if (input.empty())
    {
        return input; 
    }
    //clear end trail
    while (not isdigit(input[length]) and not isalpha(input[length]))
    {
        input.erase(length, 1); 
        length -= 1; 
        //if string left is empty
        if(input.empty())
        {
            return input; 
        }
    }
    //clear start
    while (not isdigit(input[0]) and not isalpha(input[0]))
    {
        input.erase(0, 1); 
        length -= 1; 
         //if string left is empty
        if(input.empty())
        {
            return input; 
        }
    }
    return input; 
}

/*
 * name:      traverseDirectory
 * purpose:  recurses through all directories printing out files and subDir
 * arguments: string directory
 * returns:   none
 * effects:   none
 */
void Gerp::traverseDirectory(string directory){
    //Recursion here??
    //We see hat DirNode is a tree so we keep traversign until theres no more
    //child elements and then we print the path through recursion?? we can
    //return path/new path or something
    try{
        FSTree Directory(directory); 
        // directory = Directory; 
        DirNode *root = Directory.getRoot();
        string path = directory + "/";
        traverseHelper(root, path);
        }catch(const runtime_error &e){
        cerr << "Could not build index, reason:\nDirectory \" ";
        cerr << directory << "\" not found: could not build tree\n"; 
    exit(EXIT_FAILURE); 
   }
    return;
}

/*
 * name:      traverseHelper
 * purpose:  helper for recursion
 * arguments: DirNode *curr, string path
 * returns:   none
 * effects:   none
 */
void Gerp::traverseHelper(DirNode *curr, string path){
    //if the tree is empty, if its not conitnue
    //if if tis directory is empty if it is return path
    //if it has files then we return path + that path

    if(curr->isEmpty()){
        return;
    }
    if(curr->hasSubDir()){
        for(int i = 0; i < curr->numSubDirs(); i++){
            DirNode *subDir = curr->getSubDir(i);
            string newPath = path + subDir->getName() + "/"; 
            
            traverseHelper(subDir, newPath);
        }
    }
    if(curr->hasFiles()){
        for(int i = 0; i < curr->numFiles(); i++){
            readFile(path + curr->getFile(i),path + curr->getFile(i)); 
        }
    }
}








//reads in ONE txt file
//    //directory
//     vector<vector<string>> DIRECTORY;
//     vector<string> file;

//readFile
//function: reads a whole file while given a file name
//input: string of filename, string of Path
//output: none
void Gerp::readFile(string FileName, string Path)
{
    
    ifstream file(FileName); 
    if (file.fail())
    {
        cerr << "Error: could not open file " << FileName << endl;
        exit(EXIT_FAILURE);
    }
    int lineNumber = 1; 
    string line,word; 
    vector<string> new_file; 
    while(getline(file,line))
    {
        
        new_file.push_back(line); 
        istringstream WORD(line);
        while (WORD >> word)
        {

            word = stripNonAlphaNum(word); 
            if(not word.empty()){
            Map.insert(Map.formNode(lineNumber,Map.Dir_Num,word)); 
            }
        }
        lineNumber++; 
    }
    file.close();
    Map.DIRECTORY.push_back(new_file);
    Map.Dir_Path.push_back(Path); 
    Map.Dir_Num++; 
    Map.getFile().clear(); 
    return; 
}


string Gerp::stringOut(pair<int,int> occurances)
{
    //path:lineNum: LINE
    return Map.DIRECTORY[occurances.first][occurances.second] + "\n"; 
}