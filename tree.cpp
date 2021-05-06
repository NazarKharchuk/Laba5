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

void tree::create_tree() {
    root = add_element(root, expression);
    //cout << "Creating tree.\n";
}

node* tree::add_element(node* element, string str) {
    string sub_str = "";
    node* temp = new node("");
    element = temp;
    if (str.find_first_of("+-*/") != string::npos) {
        unsigned pos;
        pos = str.find_last_of("+-");
        if (pos != string::npos) {
            element->data = str[pos];
            sub_str = str.substr(pos+1, str.length()-pos-1 );
            element->right = add_element(element->right, sub_str);
            sub_str = str.substr(0, pos);
            element->left = add_element(element->left, sub_str);
        }
        else {
            pos = str.find_last_of("*/");
            if(pos != string::npos){
                element->data = str[pos];
                sub_str = str.substr(pos + 1, str.length() - pos - 1);
                element->right = add_element(element->right, sub_str);
                sub_str = str.substr(0, pos);
                element->left = add_element(element->left, sub_str);
            }
        }
    }
    else {
        element->data = str;
    }
    return element;
}