#pragma once
#include "workWithFile.h"

struct node {
	string data;
	node* left, * right;
	node(string);
};

class tree : public workWithFile {
	node* root;
	node* add_element(node*, string);
	float recursive_count(node*);
public:
	node* get_root() { return root; };
	tree() :root(NULL) {};
	void create_tree();
	float count();
	void delete_tree(node*);
	void print(string&, node*, bool);

};

