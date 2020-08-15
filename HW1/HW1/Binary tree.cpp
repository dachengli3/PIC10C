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

BinarySearchTree::BinarySearchTree()	//default const
{
	root = NULL;
}	

void BinarySearchTree::insert(std::string data)	//insertion of node
{
	TreeNode* new_node = new TreeNode;
	new_node->data = data;
	new_node->left = NULL;
	new_node->right = NULL;	//declaring blank areas on either side
	if (root == NULL)
		root = new_node;
	else
		root->insert_node(new_node);
}

void BinarySearchTree::print() const
{
	if (root!=NULL)	//recursive loop that runs through ordered BST and prints everything
		root->print_nodes();
}

void BinarySearchTree::printRev() const
{
	if (root != NULL)	//recursive loop that runs through ordered BST and prints everything
		root->print_nodes_rev();
}

std::string BinarySearchTree::findText(std::string data)	//test function to see if a string could be located
{
	if (root->find(data))
	{
		return "I found it!";
	}
	return "Can't find it dude";
}

BinarySearchTree::~BinarySearchTree()	//destructor
{
	kill_tree(root);
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree & tree)	//copy constructor
{
	root = NULL;
	copy(tree.root);
}

BinarySearchTree & BinarySearchTree::operator=(const BinarySearchTree &Tree)	//assignment operator
{
	if (this != &Tree)
	{
		kill_tree(root);	//recursive loop that runs through everything and copies it
		root = NULL;
		copy(Tree.root);
	}
	return *this;
}

void BinarySearchTree::kill_tree(TreeNode *node)	//destructor helper function
{
	if (node != nullptr)
	{
		kill_tree(node->left);
		kill_tree(node->right);	//recursive function that deletes the least to highest values
		delete node;
	}
}

TreeNode * BinarySearchTree::copy(const TreeNode * node)	//assignment operator helper function
{
	if (node)
	{
		insert(node->data);	//copies least to greatest value
		copy(node->left);
		copy(node->right);
	}
	return nullptr;
}

void TreeNode::insert_node(TreeNode * new_node)
{
	if (new_node->data < data)
	{
		if (left == NULL)	//code from textbook
			left = new_node;
		else
			left->insert_node(new_node);
	}
	else if (data < new_node->data)
	{
		if (right == NULL)
			right = new_node;
		else
			right->insert_node(new_node);
	}
}

void TreeNode::print_nodes() const
{
	if (left != NULL)
		left->print_nodes();	//prints least to greatest
	std::cout << data << "\n";
	if (right != NULL)
		right->print_nodes();
}

void TreeNode::print_nodes_rev() const
{
	if (right != NULL)
		right->print_nodes_rev();
	std::cout << data << "\n";
	if (left != NULL)
		left->print_nodes_rev();	//prints greatest to least
}

bool TreeNode::find(std::string value) const
{
	if (value < data)
	{
		if (left == NULL)
			return false;
		else
			return left->find(value);
	}
	else if (data < value)
	{
		if (right == NULL)
			return false;
		else
			return right->find(value);
	}
	else
		return true;
}

int main()
{
	//check default constructor
	BinarySearchTree mybst;

	//Creating BST w data
	mybst.insert("Hi");
	mybst.insert("Hello");
	mybst.insert("Hey");
	mybst.insert("Hola");

	//check copy constructor
	BinarySearchTree mybst2(mybst);

	//check assign operator
	mybst = mybst2;

	//test for printability and functionality
	mybst.print();
	std::cout << std::endl;
	mybst2.print();
	std::cout << std::endl;
	mybst2.printRev();
	std::cout << std::endl;
	std::cout<<mybst2.findText("Cat");
	return 0;
}