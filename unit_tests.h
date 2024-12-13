/*
 *  unit_test.h
 *  Fahim Rashid
 *  12/1/24
 *
 *  CS 15 Project 4 Gerp
 *
 *  unit_testing the actual functions
 *
 */

#include <cassert>
#include "processing.h"
// #include "HashTable.h"
#include "DirNode.h"
#include "FSTree.h"
// #include "Gerp.h"
// //testing string 1
// void strip_chars1(){
//     string test = "$&#*$#HAGOO$*#$#$(#*";
//     string cleaned = stripNonAlphaNum(test);
//     assert(cleaned == "HAGOO");
// }

// //testing string 2
// void strip_chars2(){
//     string test = "$&#*$#HA#$*GOO$*#$#$(#*";
//     string cleaned = stripNonAlphaNum(test);
//     assert(cleaned == "HA#$*GOO");
// }

// //testing string 3
// void strip_chars3(){
//     string test = "hell1234#*$&*#(&$(@#";
//     string cleaned = stripNonAlphaNum(test);
//     assert(cleaned == "hell1234");
// }

// //testing string 4
// void strip_chars4(){
//     string test = "Aell1234Z#*$&*#(&$(@#";
//     string cleaned = stripNonAlphaNum(test);
//     assert(cleaned == "Aell1234Z");
// }

// testing directory 1
void traverse_directory1(){
    string test_file = "/comp/15/files/proj-gerp-test-dirs/mediumGutenberg";
    // FSTree tree{test_file}; 
    traverseDirectory(test_file); 
}

// void HashTest() { 
//     HashTable Table; 
//     // Table.insert();
// }

// void HashNodeInTest() {
//     HashTable Table; 
//     FSTree tree{"tinyData"}; 
//     HashTable::Node test = Table.formNode("Path",6969,"word1","word2"); 
//     HashTable::Node test2 = Table.formNode("Path2",69692,"WoRd12","word2"); 
//     Table.insert(test);
//     Table.insert(test2); 
// }

// void hash_table_collision() {
//     HashTable Table; 
//     FSTree tree{"tinyData"}; 
//     HashTable::Node test = Table.formNode("Path",6969,"apple"); 
//     HashTable::Node test2 = Table.formNode("Path2",69692,"ApPle"); 
//     HashTable::Node test3 = Table.formNode("Path2",69692,"Banana"); 
//     HashTable::Node test4 = Table.formNode("Path2",69692,"orange"); 
//     HashTable::Node test5 = Table.formNode("Path2",69692,"BaNANA"); 
//     HashTable::Node test6 = Table.formNode("Path2",69692,"pear"); 
//     Table.insert_hash_in(1,test);
//     Table.insert_hash_in(1,test2); 
//     Table.insert_hash_in(1,test3); 
//     Table.insert_hash_in(1,test4); 
//     Table.insert_hash_in(1,test5); 
//     Table.insert_hash_in(1,test6); 
// }


// void GerpFileReadIn() {
//     // Gerp test("tinyData"); //around 2/45 but doesn't work
//     // Gerp test2("mediumGutenberg"); //6second
//     // Gerp test3("smallGutenberg"); //6second
//     Gerp test("largeGutenberg"); //around 2/45 but doesn't work
//     // test.readFile("largeGtemBerg","PATH TBD"); 
// }


// void Test()
// {
//     HashTable Map; 
// Map.insert(Map.formNode(1, 0, "Hello"));
// Map.insert(Map.formNode(1, 0, "HELLO"));
// Map.insert(Map.formNode(2, 0, "hi"));
// Map.insert(Map.formNode(3, 0, "greatting"));


// Map.find("hello", cout); // Case-sensitive
// // Map.find("HELLO", cout); // Case-insensitive
// }



// void paintTree()
// {
//     FSTree(smallGutenberg); 
    
// }