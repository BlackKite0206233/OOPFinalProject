#pragma once

#include <cmath>
#include <cstdlib>

#include "NumberObject.h"

namespace BigNumber {
    class Integer : public NumberObject {
    private:
        BigNum number;
        bool sign;
        long long int length;

        void toInt();

    protected:
        virtual void strToNum(const string&) override;
        virtual void encode() override;
        virtual void decode() override;

        virtual NumberObject add(const NumberObject&, const NumberObject&) override;
        virtual NumberObject sub(const NumberObject&, const NumberObject&) override;
        virtual NumberObject mul(const NumberObject&, const NumberObject&) override;
        virtual NumberObject div(const NumberObject&, const NumberObject&) override;
        virtual NumberObject power(const NumberObject&, const NumberObject&) override;
        virtual NumberObject minus(const NumberObject&) override;

        virtual void output(const NumberObject&, ostream&) override;
    public:
        Integer();
        Integer(const NumberObject&);
        Integer(string);
        Integer(long long int);
        Integer(BigNum& _number, bool _sign);
        ~Integer();

        bool getSign();
        void setSign(bool);
        long long int getLength();
        void setLength();

        NumberObject sqrt();

        void operator =(const string&);
        void operator =(const char*);

        friend Integer rShift(const Integer&, long long int);
        friend Integer lShift(const Integer&, long long int);
        friend Integer abs(const Integer&);
        friend Integer GCD(const Integer&, const Integer&);
        friend Integer LCM(const Integer&, const Integer&);
        friend Integer factorial(const Integer&);

        friend long long int binSearch(const Integer&, const Integer&, long long int, long long int);
        friend Integer binSearch(const Integer&, Integer&, Integer&);

        friend Integer operator %(const Integer&, const Integer&);

        friend bool operator ==(const Integer&, const Integer&);
        friend bool operator !=(const Integer&, const Integer&);
        friend bool operator <(const Integer&, const Integer&);
        friend bool operator <=(const Integer&, const Integer&);
        friend bool operator >(const Integer&, const Integer&);
        friend bool operator >=(const Integer&, const Integer&);
    };
}

