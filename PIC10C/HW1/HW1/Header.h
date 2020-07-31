#pragma once
#include <string>
#include <ostream>
#include <iostream>

class TreeNode
{
public:
	void insert_node(TreeNode* new_node);	//function to insert a node
	void print_nodes() const;	//function to print nodes in order
	void print_nodes_rev() const;	//function to print nodes reversed
	bool find(std::string value) const;	//function to find a text
private:	//data fields
	std::string data;
	TreeNode* left;
	TreeNode* right;
	friend class BinarySearchTree;
};
class BinarySearchTree
{
public:
	BinarySearchTree();
	void insert(std::string data);
	void print() const;
	void printRev() const;	//test function prints in reverse order
	std::string findText(std::string data);
	// **** The Big Three **** //
	// Destructor
	~BinarySearchTree();
	// Copy constructor
	BinarySearchTree(const BinarySearchTree& T);
	// Assignment operator
	BinarySearchTree& operator=(const BinarySearchTree&);
private:
	void kill_tree(TreeNode*);	//destructor helper function
	TreeNode* copy(const TreeNode* Node);	//copy constructor helper
	TreeNode* root;
};