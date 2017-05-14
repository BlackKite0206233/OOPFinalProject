#include "Computer.h"



Computer::Computer() {
}


Computer::~Computer() {
}



map<string, NumberObject> Computer::variableSet = map<string, NumberObject>();



NumberObject Computer::getVar(const string& _varName) {
    string varName = _varName;
    auto it = variableSet.find(varName);

    if(it == variableSet.end())
        throw "varable not found";
    
    return variableSet[varName];
}

vector<pair<string, string>> Computer::getVarList() {
	vector<pair<string,string>> varList;
	stringstream ss;

	for (auto &i : variableSet) {
		ss.str("");
		ss.clear();

		ss << i.second;
		string str;

		getline(ss, str);
		varList.push_back(pair<string, string>(i.first, str));
	}
		

	return varList;
}

void Computer::setVar(const string& _varName) {
    string varName = _varName;

    variableSet[varName] = NumberObject(0);
}

void Computer::setVar(const string& _varName, const string& _varVal) {
    string varName = _varName;
    auto it = variableSet.find(varName);
    string varVal = _varVal;

	try {
		Formula f(varVal);
		variableSet[varName] = f.caculate();
	}
	catch (const char* errMsg) {
		variableSet[varName] = NumberObject(0);
		throw errMsg;
	}
}

void Computer::setVar(const string& _varName, const NumberObject& _varVal) {
    string varName = _varName;
	NumberObject varVal = _varVal;

    variableSet[varName] = varVal;
}


void Computer::setFormula(const string& _formula) {
	try {
		this->f = _formula;
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

void Computer::caculate() {
	try {
		this->result = this->f.caculate();
	}
	catch (const char* errMsg) {
		throw errMsg;
	}
}

NumberObject Computer::getResult() {
    return this->result;
}