#include "tree.h"

int main() {
	tree our_tree;
	string file_name = "inputFile.txt";
	our_tree.fread(file_name);
	our_tree.create_tree();
	string str = "";
	our_tree.print(str, our_tree.get_root(), false);
}