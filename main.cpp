/*
 *  main.cpp
 *  Fahim Rashid Tom Zhou
 *  12/01/24
 *
 *  CS 15 Project 4 Gerp
 *
 *  main file
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include "Gerp.h"
using namespace std;

/*
 * name:      main
 * purpose:  main function
 * arguments: int argc, char *argv[]
 * returns:   none
 * effects:   none
 */
int main(int argc, char *argv[]){
    //Checks if we have the right ammount of arguments
    if(argc != 3){
        cerr << "Usage: ./gerp inputDirectory outputFile" << endl;
        exit(EXIT_FAILURE);
    }else{
        Gerp g(argv[1]);
        g.command_execution(argv[1],argv[2]);
    }
    return 0;
}