#pragma once

#include <string>
#include <stack>

#include "NumberObject.h"

using namespace std;
using namespace BigNumber;

class Formula {
private:
    string formulaStr;

	void processString();
	void replaceSign();
	void addSpace();
	void inToPostfix();
	int priority(string);
	string changePowerFormat(string);

public:
    Formula();
    Formula(string&);
    ~Formula();

	Formula operator =(const string&);

    void setFormula(string&);
    NumberObject caculate();
};

