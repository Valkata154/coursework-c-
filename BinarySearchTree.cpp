#include <cstring>
#include <iostream>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

// **Constructors **

// Creates an empty binary tree
BinarySearchTree::BinarySearchTree()
{
}

// Creates a binary search tree with an initial word to store
BinarySearchTree::BinarySearchTree(std::string word)
{
	root = new Node;
	root->word = word;
	root->left = nullptr;
    root->right = nullptr;
}

// Deep copy method
Node *copy(const Node *node)
{
	if (node == nullptr)
	{
		return nullptr;
	}
	Node *new_node = new Node;
	new_node->word = node->word;
	new_node->left = copy(node->left);
	new_node->right = copy(node->right);
	
	return new_node;
}

// Creates a binary search tree by copying an existing tree
BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
	:root(copy(rhs.root))
{
}

// Creates a binary search tree from a collection of existing words
BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
	for(int i = 0; i < words.size(); i++)
	{
		insert(words[i]);
	}
}

// Method used to destroy the root
void destroy(Node* root)
{
	if(root != nullptr)
	{
		if(root->left != nullptr)
		{
			destroy(root->left);
		}
		if(root->right != nullptr)
		{
			destroy(root->right);
		}
		delete root;
	}
}

//destructor
BinarySearchTree::~BinarySearchTree()
{
	destroy(root);
}

// **Methods**

// The helper method for the insert method
void insert_helper(Node** root, string word)
{
	if((*root) != nullptr)
	{
		if(word > (*root)->word)
		{
			insert_helper(&(*root)->right,word);
		}
		else if(word < (*root)->word)
		{
			insert_helper(&(*root)->left,word);
		}
	}
	else
	{
		(*root) = new Node;
		(*root)->word = word;
		(*root)->left = nullptr;
		(*root)->right = nullptr;
	}
}

// Method to insert a word in the BinarySearchTree
void BinarySearchTree::insert(std::string word)
{
	insert_helper(&root, word);
}

// The helper method for the exists method
bool exists_helper(std::string word, Node* root)
{
	if(root != nullptr)
	{
		if(root->word == word)
		{
			return true;
		}
		else
		{
			if(word < root->word)
			{
				return exists_helper(word, root->left);
			}
			else
			{
				return exists_helper(word, root->right);
			}
		}
	}
	else
	{
		return false;
	}
}

// Method to check if a word exists in the BinarySearchTree
bool BinarySearchTree::exists(std::string word) const
{
	return exists_helper(word, root); 
}

// Variables used for returning a sentence and managing the spaces between the words
std::string sentence = "";
int counter = 0;

// The helper method for the increment method
void increment_helper(std::string word, Node* root)
{
	if(root != nullptr)
	{
		if(root->word == word)
		{
			root->count += 1;
		}
		else
		{
			if(word < root->word)
			{
				increment_helper(word, root->left);
			}
			else
			{
				increment_helper(word, root->right);
			}
		}
	}
}

// Method that increments the count of a word if it already exists
void BinarySearchTree::increment(std::string word) const
{
	increment_helper(word, root);
}

// The helper method for the output method
void output_helper(Node* root)
{
	if (root != nullptr)
	{
		output_helper(root->left);
		cout << root->word << ": " << root->count << endl;
		output_helper(root->right);
	}
}

// Method that outputs all the words and their count in the BinarySearchTree
void BinarySearchTree::output() const
{
	output_helper(root);
}

// The helper method for the inorder method
std::string inorder_helper(Node* root)
{
	if (root != nullptr)
	{
		inorder_helper(root->left);
		if(counter == 1)
		{
			sentence += root->word;
		}
		else
		{
			sentence += " " + root->word;
		}
		inorder_helper(root->right);
	}
	counter++;
	return sentence;
}

// Method that prints the words in the binary tree inorder
std::string BinarySearchTree::inorder() const
{
	sentence = "";
	counter = 0;
	return inorder_helper(root);
}

// The helper method for the preorder method
std::string preorder_helper(Node* root)
{
	if (root != nullptr)
	{
		sentence += root->word;
		if(counter < 7)
		{
			sentence += " ";
		}
		preorder_helper(root->left);
		preorder_helper(root->right);
	}
	counter++;
	return sentence;
}

// Method that prints the words in the binary tree in preorder
std::string BinarySearchTree::preorder() const
{
	sentence = "";
	counter = 0;
	return preorder_helper(root);
}

// The helper method for the postorder method
std::string postorder_helper(Node* root)
{
	if (root != nullptr)
	{
		postorder_helper(root->left);
		postorder_helper(root->right);
		sentence += root->word;
		if(counter < 10)
		{
			sentence += " ";
		}	
	}
	counter++;
	return sentence;
}

// Method that prints the words in the binary tree in postorder
std::string BinarySearchTree::postorder() const
{
	sentence = "";
	counter = 0;
	return postorder_helper(root);
}
    
// **Operator overloads**
    
// Inserts a new word into the binary tree
BinarySearchTree& BinarySearchTree::operator+(std::string word)
{
	insert(word);
	return *this;
}

// Assignment operator
BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	if(this != &rhs)
	{
		BinarySearchTree temporary(rhs);
		swap(temporary.root, root);
		return *this;
	}
	else
	{
		return *this;
	}
}


