###
### Makefile for Gerp Project
###
### Author:  Fahim Rashid

#Compiler Flags
CXX = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS = -g3
## 
## Build up your Makefile in a similar manner as for Zap. Feel free 
## to use that Makefile to guide you! Note, you do NOT need rules for
## FSTree.o and DirNode.o as those (pre-compiled) object files are 
## provided to you.
## 
## At the end, you can delete this comment!
## 

## add in main.o later
gerp: main.o  DirNode.o FSTree.o Gerp.o HashTable.o
	$(CXX) $(LDFLAGS) -o $@ $^

Gerp.o: Gerp.cpp DirNode.o FSTree.o HashTable.o
	${CXX} ${CXXFLAGS} -c Gerp.cpp

unit_test: unit_test_driver.o FSTree.o DirNode.o HashTable.o Gerp.o
	$(CXX) $(CXXFLAGS) $^ 

processing.o: processing.cpp FSTree.o DirNode.o 
	${CXX} ${CXXFLAGS} -c processing.cpp

main.o: main.cpp Gerp.h HashTable.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

hashExample: hashExample.cpp
	${CXX} ${CXXFLAGS} $^ -o $@

HashTable.o: HashTable.cpp HashTable.h
	${CXX} ${CXXFLAGS} -c HashTable.cpp

##
## Here is a special rule that removes all .o files besides the provided ones 
## (DirNode.o and FSTree.o), all tempcorary files (ending with ~), and 
## a.out produced by running unit_test. First, we find all .o files 
## that are not provided files, then we run rm -f on each found file 
## using the -exec find flag. Second, we delete the temporary files
## and a.out. @ is used to suppress stdout.
## 
## You do not need to modify or further comment this rule!
##
clean:
	@find . -type f \( \
		-name '*.o' ! -name 'FSTree.o' ! -name 'DirNode.o' \
		\) -exec rm -f {} \;
	@rm -f *~ a.out

