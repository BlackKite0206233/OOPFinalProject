#include <string>;
#include <iostream>
#include <vector>
#include "Integer.h"
#include "Decimal.h"
#include "Complex.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
	Decimal a = "134564561235216.1564";
	Decimal b = "13245.0", c, d, e;
	vector<NumberObject*> num;
	//std::cin >> a;
	c = a / b;
	num.push_back(&a);
	num.push_back(&b);
	num.push_back(&c);
	for (auto &i : num) {
		cout << *i << endl;
	}
	
	
	system("pause");
    return 0;
}

