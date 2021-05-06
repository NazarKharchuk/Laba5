#pragma once
#include "workWithFile.h"

struct node {
	string data;
	node* left, * right;
	node(string);
};

class tree: public workWithFile {
	node* root;
public:
	node* get_root() { return root; };
	tree() :root(NULL) {};
	//void create_tree(string);
	//float count();
	void print(string&, node*, bool);
};

