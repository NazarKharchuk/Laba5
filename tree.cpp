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

float tree::recursive_count(node* element) 
{
    if (element->data == "+") 
    {
        float num, num1, num2;
        num1 = recursive_count(element->left);
        num2 = recursive_count(element->right);
        num = num1 + num2;
        //cout << num1 << "___num1 + num2___" << num2 << "___result ___" << num << endl;
        return(num);
    }

    if (element->data == "-") 
    {
        float num, num1, num2;
        num1 = recursive_count(element->left);
        num2 = recursive_count(element->right);
        num = num1 - num2;
        //cout << num1 << "___num1 - num2___" << num2 << "___result ___" << num << endl;
        return(num);
    }

    if (element->data == "*") 
    {
        float num, num1, num2;
        num1 = recursive_count(element->left);
        num2 = recursive_count(element->right);
        num = num1 * num2;
        //cout << num1 << "___num1 * num2___" << num2 << "___result ___" << num << endl;
        return(num);
    }

    if (element->data == "/") 
    {
        float num, num1, num2;
        num1 = recursive_count(element->left);
        num2 = recursive_count(element->right);
        if (num2 != 0) 
        {
            num = num1 / num2;
            return(num);
        }
        else 
        {
            cout << "Error : X / 0!!!";
            return(0);
        }
        //cout << num1 << "___num1 / num2___" << num2 <<"___result ___"<<num << endl;
    }

    if (element->data != "+" && element->data != "-" && element->data != "*" && element->data != "/") 
    {
        float num;
        for (int i = 0; i < values.size(); i++) 
        {
            if (values[i].name == element->data) 
            {
                num = values[i].data;
                //cout << num << "___num"<< endl;
                return (num);
                break;
            }
        }
        return (stof(element->data));
    }
}

float tree::count() 
{
    float num = recursive_count(root);
    return(num);
}

void tree::delete_tree(node* element)
{
    if (element != NULL) {
        delete_tree(element->left);
        delete_tree(element->right);
        delete element;
    }
}