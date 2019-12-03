# AVL Tree Data Structures

## Overview
This assignment is an avl tree implementation. 
The tree created is a balanced tree that is organized depending on the key. 
Keys that are already in the tree will have their frequency increased if a new node 
with the same key is inserted.  

## Compilation
type make while inside the A4 folder and to run type ./avltree.
IF YOU DONT USE MAKE: gcc -o avltree avltree.c 
TO RUN : ./avltree

## Usage 
This program is an implementation of an AVL tree which can read in a file which creates a full balanced tree, or the Nodes can be added in manually. Such functions as find and find all which searches the tree for with either a frequency count or search for a specific node. Other functions like height and size are used to find the size and height of the tree. The program loops a menu that accepts a number between 1 and 7. 

## Known Limitations
Program is limited to keys that are of type char *
Remove element
Find requires trees of size 3 or greater

