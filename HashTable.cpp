/*
 *  HashTable.cpp
 *  Fahim Rashid Tom Zhou
 *  12/1/24
 *
 *  CS 15 Project 4 Gerp
 *
 *  implementation for HashTable
 *
 */
 #include "HashTable.h"
 #include <cctype>

//HashTable Constructor
HashTable::HashTable(){
    Table.resize(TableSize);
    bucketsLoaded = 0; 
}

//getFile
//function: FILE getter
//input: none
//output: FILE vector
vector<string> HashTable::getFile() const
{
    return FILE; 
} 
//find
//function: provies a word and find the associated vector of words 
//input: string word, and outstream
//output: none
void HashTable::find(string key, ostream &output, bool IfSense) {
    string lower = key;
    for (char &c : lower) {
        c = tolower(c);
    }
    int index = hash<string>{}(lower) % TableSize;
    for (list<SameWordNode>::iterator it = Table[index].begin();
         it != Table[index].end(); it++) {

        if (lower == it->wordInsens) {
            // Use a set to keep track of already outputted lines
            set<pair<int, int>> uniqueOccurances;

            if (IfSense) {
                for (int i = 0; i < it->SameWordList.size(); i++) {
                    if (it->SameWordList[i].word == key) {
                        for (int word = 0; 
                    word < it->SameWordList[i].occurances.size(); word++) {
            pair<int, int> occurance = it->SameWordList[i].occurances[word];
                    if (uniqueOccurances.insert(occurance).second) {
                    output << Dir_Path[occurance.first] << ":"
                    << occurance.second << ": "
                << DIRECTORY[occurance.first][occurance.second - 1] << endl;
                            }
                        }
                    }
                }
            } else {
                for (int i = 0; i < it->SameWordList.size(); i++) {
                    for (int word = 0; word < it->SameWordList[i].occurances.size(); word++) {
                        pair<int, int> occurance = it->SameWordList[i].occurances[word];
                        if (uniqueOccurances.insert(occurance).second) {
                            output << Dir_Path[occurance.first] << ":"
                                   << occurance.second << ": "
                                   << DIRECTORY[occurance.first][occurance.second - 1] << endl;
                        }
                    }
                }
            }
            return;
        }
    }

    if (IfSense) {
        output << key << " Not Found. Try with @insensitive or @i." << endl;
    } else {
        output << key << " Not Found." << endl;
    }
}

//formNode
//function: creates a node with all given information
//input: integer line number, file number, the string word
//output: a formed Node
HashTable::Node HashTable::formNode(int LineNum, int FileNum,
string word)
{
    pair<int,int> occur; 
    occur.first = FileNum; 
    occur.second = LineNum; 
    Node node; 
    node.occurances.push_back(occur); 
    node.word = word; 
    return node; 
} 

//formLinkNode
//function: creates a Link node with all given information
//input: the word insensitive case, a occurance node
//output: a formed LinkNode
HashTable::SameWordNode HashTable::formLinkNode(string word, Node occur)
{
    vector<Node> list; 
    SameWordNode node; 
    node.wordInsens = word; 
    list.push_back(occur); 
    node.SameWordList = list; 

    return node; 
}

//insert
//function: inserts a given node into the HashTable
//input: a node
//output: none
void HashTable::insert(Node node){
     
    string lower = node.word; 
    for (char &c : lower) {
        c = tolower(c);
    }
    if (!lower.empty()){
    int index = hash<string>{}(lower) % TableSize; 
    insert_hash_in(index,node,lower); 
    }
    return; 
}

//insert_hash_in
//function: inserts a given node into the HashTable helper function
//input: a node, an index number, a lower cased word
//output: none
void HashTable::insert_hash_in(int index, Node node, string wordlower)
{
    if (Table[index].empty())
    {
        SameWordNode WordVarList = formLinkNode(wordlower, node); 
        Table[index].push_back(WordVarList); 
        bucketsLoaded++;  
        expand(); 
    }
    else
    {
        for(list<SameWordNode>::iterator it = Table[index].begin(); 
        it != Table[index].end(); it++)
        {
            if(it->wordInsens == wordlower)
            {
                for (int i = 0; i < it->SameWordList.size(); i++)
                {
                    if (it->SameWordList[i].word == node.word)
                    {
                        pair<int, int> new_occurance;
                        new_occurance.first = node.occurances[0].first;
                        new_occurance.second = node.occurances[0].second;
                        it->SameWordList[i].occurances.push_back(new_occurance);
                        bucketsLoaded++; 
                        expand(); 
                        return; 
                    }
                    else
                    {
                        it->SameWordList.push_back(node);
                        bucketsLoaded++; 
                        expand(); 
                        return; 
                    }
                }
            }
        }
        SameWordNode WordVarList = formLinkNode(node.word, node); 
        Table[index].push_back(WordVarList); 
        bucketsLoaded++; 
        expand(); 
        return; 
    }
}

//getSize
//function: return size of HashTable
//input: none
//output: the integer of the table size
int HashTable::getSize()
{
    return Table.size(); 
}

//expand
//function: hashtable expansion function
//input: none
//output: none
void HashTable::expand()
{
    int loadFactor = Table.size() * 3 / 4; 
    
    if (bucketsLoaded == loadFactor)
    {
        vector<list<SameWordNode>> oldTable = Table;
        int size = Table.size(); 
        size = 2 * size; 
        Table.clear();
        Table.resize(size); 
        for(int i = 0; i < oldTable.size(); i++)
        {
            //list
            for (list<SameWordNode>::iterator it = oldTable[i].begin(); 
            it != oldTable[i].end(); it++)       
            {
                for (int k = 0; k < it->SameWordList.size(); k++)
                {
                    //copying old into new
                    insert(it->SameWordList[k]);
                }
            }
        }

        }
            
        return; 
}


//isEqual
//function: compare if two pair of integers are equal
//input: two pairs of integers
//output: true or false
bool HashTable::isEqual(pair<int,int> pair1, pair<int,int> pair2)
{
    return (pair1.first == pair2.first) and (pair1.second == pair2.second); 
}