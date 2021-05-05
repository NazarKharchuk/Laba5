#pragma once
#include "readFile.h"

using namespace std;

struct node {
	string data;
	node* left, * right;
	node(string);
};

class tree{
	node* root;
public:
	node* get_root() { return root; };
	tree() :root(NULL) {};
	//void create_tree(string);
	//float count();
	void print(string&, node*, bool);
};

