
// /*
//  *  processing.cpp
//  *  Fahim Rashid
//  *  12/1/24
//  *
//  *  CS 15 Project 4 Gerp
//  *
//  *  processing.cpp implementation file
//  *
//  */

// #include "processing.h"

// // /*
// //  * name:      stripNonAlphaNum
// //  * purpose:  takes away all nonalpha nums from an input
// //  * arguments: string input
// //  * returns:   string of the finalized string
// //  * effects:   none
// //  */
// // string stripNonAlphaNum(string input){
// //     int length = input.length() - 1; 
// //     //empty case
// //     if (input.empty())
// //     {
// //         return input; 
// //     }
// //     //clear end trail
// //     while (!isdigit(input[length]) and !isalpha(input[length]))
// //     {
// //         input.erase(length, 1); 
// //         length -= 1; 
// //         //if string left is empty
// //         if(input.empty())
// //         {
// //             return input; 
// //         }
// //     }
// //     //clear start
// //     while (!isdigit(input[0]) and !isalpha(input[0]))
// //     {
// //         input.erase(0, 1); 
// //         length -= 1; 
// //          //if string left is empty
// //         if(input.empty())
// //         {
// //             return input; 
// //         }
// //     }
// //     return input; 
// // }


// /*
//  * name:      traverseDirectory
//  * purpose:  recurses through all directories printing out files and subDir
//  * arguments: string directory
//  * returns:   none
//  * effects:   none
//  */
// void traverseDirectory(string directory){
//     //Recursion here??
//     //We see hat DirNode is a tree so we keep traversign until theres no more
//     //child elements and then we print the path through recursion?? we can
//     //return path/new path or something
//     try{
//         FSTree Directory(directory); 
//         // directory = Directory; 
//          DirNode *root = Directory.getRoot();
//         string path = directory + "/";
//         traverseHelper(root, path);
//         }catch(const runtime_error &e){
//         cerr << "Could not build index, reason:\nDirectory \" ";
//         cerr << directory << "\" not found: could not build tree\n"; 
//     exit(EXIT_FAILURE); 
//    }
//     return;
// }



// /*
//  * name:      traverseHelper
//  * purpose:  helper for recursion
//  * arguments: DirNode *curr, string path
//  * returns:   none
//  * effects:   none
//  */
// void traverseHelper(DirNode *curr, string path){
//     //if the tree is empty, if its not conitnue
//     //if if tis directory is empty if it is return path
//     //if it has files then we return path + that path
//     // cout << "INSIDE\n"; 
//     if(curr->isEmpty()){
//         return;
//     }
//     if(curr->hasSubDir()){
//         for(int i = 0; i < curr->numSubDirs(); i++){
//             DirNode *subDir = curr->getSubDir(i);
//             string newPath = path + subDir->getName() + "/"; 
            
//             traverseHelper(subDir, newPath);
//         }
//     }
//     if(curr->hasFiles()){
//         for(int i = 0; i < curr->numFiles(); i++){
//             cout << path + curr->getFile(i) << endl;
//             // readFile(path + curr->getFile(i),path + curr->getFile(i)); 
//         }
//     }
// }