#pragma once

#include "NumberObject.h"
#include "Integer.h"

class Decimal : public NumberObject {
private:
	Integer numerator, denominator;

	void checkSign();

protected:
	virtual void strToNum(const string&) override;
	virtual void encode() override;
	virtual void decode() override;

	virtual NumberObject add(const NumberObject&, const NumberObject&) override;
	virtual NumberObject sub(const NumberObject&, const NumberObject&) override;
	virtual NumberObject mul(const NumberObject&, const NumberObject&) override;
	virtual NumberObject div(const NumberObject&, const NumberObject&) override;
	virtual NumberObject pow(const NumberObject&, const NumberObject&) override;
	virtual NumberObject minus(const NumberObject&) override;

	virtual void output(ostream&) override;

public:
	Decimal();
	Decimal(const NumberObject&);
	Decimal(string);
	Decimal(int);
	Decimal(const NumberObject&,const NumberObject&);
	~Decimal();

	bool getSign();

	void operator =(const string&);
	void operator =(const char*);
};

