#include "workWithFile.h"

void workWithFile::fread(string file_name) {
	ifstream inFile(file_name);

    if (!inFile.is_open()) return;

    string str;
    value val;
    while (getline(inFile, str)) {
        cout << str << endl;
        if (str.find("=") != string::npos) {
            val.name = str.substr(0, str.find("=") - 1);
            val.data = stof(str.substr(str.find("=") + 2, str.length() - str.find("=") - 3)); //
            values.push_back(val);
        }
        else {
            expression = str.substr(0, str.length() - 1);
        }
    }

    inFile.close();

    /*for (int i = 0; i < values.size(); i++)
        cout << values[i].name << "___" << values[i].data << "___\n";
    cout << expression << "___\n";*/
}
