 An Implementation of BigInteger library in C++

 #ifndef BigInteger_H_INCLUDED
#define BigInteger_H_INCLUDED

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

#define absBig BigInteger::absBigInteger
#define factBig BigInteger::factBigInteger
#define maxBig BigInteger::maxBigInteger
#define minBig BigInteger::minBigInteger
#define to_Big BigInteger::to_BigInteger
#define revBig BigInteger::revBigInteger
#define countBig BigInteger::countBigInteger
#define eraseBig BigInteger::eraseBigInteger
#define isPaliBig BigInteger::isPaliBigInteger
#define sortBig BigInteger::sortBigInteger
#define powBig BigInteger::powBigInteger

class BigInteger {

    private:
        string str;

    public:

    BigInteger ()
    {
        str = "0";
    }

    BigInteger (string s)
    {
        if(!isInputCorrect(s)) {
            cerr << "Invalid Input.. Please Use Valid BigInteger" << endl;
            exit(0);
        }
        str = s;        
    }
      BigInteger (int n)
    {
        ostringstream convertstr;
        convertstr << n;
        str = convertstr.str();
    }

    BigInteger (long long int n)
    {
        ostringstream convertstr;
        convertstr << n;
        str = convertstr.str();
    }
}