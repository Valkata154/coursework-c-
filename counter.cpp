/*
*
*  @author: Valeri Vladimirov 40399682
*  Last Modified: 06/04/2019
*  Purpose: To insert words from text files into a BinarySearchTree and output their count.
*
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>

#include "BinarySearchTree.h"
#include "Node.h"

#define LINE_LENGTH 1000

using namespace std;

int main(int argc, char **argv)
{
	// Declaring all the variables needed for the program.
	string line;
	string word;
	string name = argv[1];
	char *token;
	ifstream myfile (name);
	BinarySearchTree *tree = new BinarySearchTree();
	
	// Looping through the file, checking if the word exists if not, then add to the BST if yes then increment its count.
	if(myfile.is_open())
	{
		// If the file is with sentences check for punctuation.
		if(name == "sentences_test.txt")
		{
			cout << "This is for the sentences_test.txt." << endl;
			while(getline(myfile, line))
			{
				int lenght = line.size();
				for(int i = 0; i < lenght; i++)
				{
					if(!(ispunct(line[i])) && line[i] != ' ' && line[i] != '\n')
					{
						word += line[i];
					}
					else if(word != "")
					{
						if(tree->exists(word))
						{
							tree->increment(word);
						}
						else
						{
							tree->insert(word);
						}
						word = "";
					}
				}
			}
			myfile.close();
		}
		else if(name == "single_words_test.txt")
		{
			cout << "This is for the single_words_test file." << endl;
			while(getline(myfile, line))
			{
				if(tree->exists(line))
				{
					tree->increment(line);
				}
				else
				{
					tree->insert(line);
				}
			}
			myfile.close();
		}
	}
	else
	{
		cout << "Unable to open file." << endl;
	}
	
	// Outputing all the words and their count and deleting the tree.
	tree->output();
	delete(tree);
	
	return 0;
}