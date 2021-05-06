#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct value {
	string name;
	float data;
};

class workWithFile {
protected:
	vector<value> values;
	string expression;
public:
	void fread(string);
	void fwrite(string, float);
};

