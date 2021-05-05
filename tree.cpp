#include "tree.h"

node::node(string str) {
	data = str;
	left = right = NULL;
}

void tree::print(string& str, node* root, bool isLeft) {
    if (root != NULL)
    {
        cout << str;
        cout << (isLeft ? "+-->" : "--->");
        cout << "(" << root->data << ")" << endl;
        string str2;
        str2 = str + (isLeft ? "|    " : "     ");
        print(str2, root->left, true);
        str2 = str + (isLeft ? "|    " : "     ");
        print(str2, root->right, false);
    }
}

