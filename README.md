# Overview

This coursework contains two parts. In Part A you will build a library
class that implements a binary search tree data structure for storing string
data for ecient searching. In Part B you will use
your binary search tree class to implement an efficient program to count the
frequency of each word in a text file.

# 2 Part A: The binary search tree library
You will be provided with four files – two header files, a supporting C++ file
for the implementation of the BinarySearchTree class, and a test file to test
the BinarySearchTree class. Your task is to complete the implementation of the methods and operator overloads in the BinarySearchTree
class, as specified in Tables 1 and 2, so that it passes all of the tests
in the test.cpp file. You must not modify the test.cpp file.The BinarySearchTree class should be built as a library file, allowing it
to be reused in other applications.

**Operator** | **Example** | **Description**
-------------|-------------|-----------------
'+' | tree = tree + ‘‘hello’’ | Inserts a new word into the binary tree.
'-' | tree1 = tree2 | Copy assignment operator. Deletes the nodes in tree1, freeing memory, and then makes deep copies of all of the nodes in tree2.

**Method** | **Description** 
-------------|-------------
BinarySearchTree() | Creates an empty binary search tree.
BinarySearchTree(std::string word) | Creates a binary search tree with an initial word to store.
BinarySearchTree(const BinarySearchTree &rhs) | Creates a binary search tree by copying an existing binary search tree. This must be a deep copy, not a reference.
BinarySearchTree(vector<std::string> &words) | Creates a binary search tree from a vector of words. 
~BinarySearchTree() | Destructor for a binary search tree. Releases the memory occupied by all of its nodes. 
void insert(std::string word) | Adds a word to the binary search tree. If the word already exists in the tree then nothing happens
bool exists(std::string word) | Returns true if the word is in the tree, false otherwise.
std::string inorder() | Generates a string containing the words in the tree in alphabetic order
std::string preorder() | Generates a string containing the words in the tree in pre-order fashion. 
std::string postorder() | Generates a string containing the words in the tree in postorder fashion

# Part B: Using your library to implement a word counter application

Your task is to write an application that reads in a text file and outputs to
the console the number of times that each word in that file occurs.

You must use your binary search tree to do this. You should add
an int variable to the Node struct called count. Note that you do not need
to change any of the methods and operators that you have written for Part
A. Your application should then use the following procedure to count words:

1. Make a binary search tree object.

2. Extract a word from the input file.

3. Check if that word exists in the binary search tree. If not, add it to the
tree and set the count field of the Node to 1. If the word already exists
in the tree, add one to the count field of the Node in which it occurs.
