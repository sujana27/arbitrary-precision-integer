#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

class BigInteger
{
public:
    // Constructor with no argument to create a zero integer.
    BigInteger();

    // Constructor that takes a signed 64-bit integer converts it to an arbitrary-precision integer.
    BigInteger(const int64_t &);

    // Constructor that takes a string of digits and converts it to an arbitrary - precision integer.
    BigInteger(const string &);

    BigInteger(const BigInteger &);

    void setNumber(const string &);
    string getNumber() const;
    bool getSign() const;

    BigInteger operator+(const BigInteger &);
    BigInteger operator-(BigInteger);
    BigInteger operator-(); // sign change
    BigInteger operator*(const BigInteger &);
    bool operator>(const BigInteger &);
    bool operator<(const BigInteger &);
    BigInteger &operator=(const BigInteger &);

    bool operator>=(const BigInteger &);
    bool operator<=(const BigInteger &);
    BigInteger &operator+=(const BigInteger &b);
    BigInteger &operator-=(const BigInteger &b);
    BigInteger &operator*=(const BigInteger &b);

    friend bool operator==(const BigInteger &, const BigInteger &);
    friend bool operator!=(const BigInteger &, const BigInteger &);
    friend ostream &operator<<(ostream &, const BigInteger &);

    // Exception to be thrown if trying to access an element out of range.
    inline static invalid_argument not_a_number = invalid_argument("Not a valid input: ");
    inline static runtime_error rt_error_unknown = runtime_error("Something went wrong during execution!");

private:
    string number;
    bool sign;
    string makeSum(string, string);
    string makeSub(string, string);
    string addZeros(string, size_t);
};

// empty constructor
BigInteger::BigInteger()
{
    number = "0";
    sign = false;
}
// string constructor
BigInteger::BigInteger(const string &s)
{
    setNumber(s);
}

// signed int constructor
BigInteger::BigInteger(const int64_t &num)
{
    stringstream sStream;
    string sNum;
    sStream << num;
    sStream >> sNum;

    setNumber(sNum);
}

BigInteger::BigInteger(const BigInteger &bigint) : number(bigint.number), sign(bigint.sign)
{
    // no operation
    // just for copy constructor
}

void BigInteger::setNumber(const string &s)
{
    // validating here and throws not_a_number exception
    for (uint64_t i = 0; i < s.size(); i++)
    {
        if ((i == 0 && s[i] != '-' && !isdigit(s[i])) || (i != 0 && !isdigit(s[i])))
            throw not_a_number;
    }
    if (isdigit(s[0]))
    {
        number = s;
        sign = false;
    }
    else
    {
        number = s.substr(1);
        sign = true;
    }
}

string BigInteger::getNumber() const
{
    return number;
}
bool BigInteger::getSign() const
{
    return sign;
}

/*--------------------------------------------------------
| String addition idea has been sourced from this resource
| https://github.com/rgroshanrg/bigint/blob/14455a6a8f533865205ed8f0a5e27e6db02cbf53/bigint_function_definitions.h#L87
---------------------------------------------------------*/
BigInteger BigInteger::operator+(const BigInteger &b)
{
    BigInteger addition;
    if (getSign() == b.getSign())
    {
        addition.setNumber(makeSum(getNumber(), b.getNumber()));
        addition.sign = getSign();
    }
    else
    {
        if (BigInteger(getNumber()) > BigInteger(b.getNumber()))
        {
            addition.setNumber(makeSub(getNumber(), b.getNumber()));
            addition.sign = getSign();
        }
        else
        {
            addition.setNumber(makeSub(b.getNumber(), getNumber()));
            addition.sign = b.getSign();
        }
    }
    if (addition.getNumber() == "0")
        addition.sign = false;

    return addition;
}

BigInteger &BigInteger::operator+=(const BigInteger &b)
{
    (*this) = (*this) + b;
    return (*this);
}

// negation / unary
BigInteger BigInteger::operator-()
{
    BigInteger negation;
    negation.number = getNumber();
    if (negation.getNumber().length() >= 1 && negation.getNumber()[0] != '0')
        negation.sign = !getSign();
    return negation;
}

BigInteger BigInteger::operator-(BigInteger b)
{
    b.sign = !(b.getSign());
    return (*this) + b;
}

/* -------------------------------------------------------------------------------
| String multiplication logic has been sourced from here
| https://leetcode.com/problems/multiply-strings/solutions/4460228/easy-solution-in-c/
-----------------------------------------------------------------------------------*/
BigInteger BigInteger::operator*(const BigInteger &b)
{
    BigInteger product;
    string multiplicand = getNumber(), multiplier = b.getNumber();
    product.sign = getSign() ^ b.getSign();
    uint64_t n = multiplicand.size(), m = multiplier.size();

    string res(n + m, '0');
    for (uint64_t iidx = n; iidx-- > 0;)
    {
        for (uint64_t jidx = m; jidx-- > 0;)
        {
            int tsum = (res[1 + iidx + jidx] - '0') + (multiplicand[iidx] - '0') * (multiplier[jidx] - '0');
            res[iidx + jidx] += tsum / 10;
            res[1 + iidx + jidx] = tsum % 10 + '0';
        }
    }
    // if leading zero ignore them
    if (res.length() > 0 && res[0] == '0')
    {
        res = res.substr(1);
    }
    product.number = res;
    return product;
}
BigInteger &BigInteger::operator*=(const BigInteger &b)
{
    (*this) = (*this) * b;
    return (*this);
}

BigInteger &BigInteger::operator-=(const BigInteger &b)
{
    (*this) = (*this) - b;
    return (*this);
}

BigInteger &BigInteger::operator=(const BigInteger &b)
{
    if (this != &b)
    {
        number = b.getNumber();
        sign = b.getSign();
    }
    return *this;
}

ostream &operator<<(ostream &out, const BigInteger &a)
{
    if (a.getSign())
    {
        out << "-" << a.getNumber();
        return cout;
    }
    else
    {
        out << a.getNumber();
        return out;
    }
}

bool operator==(const BigInteger &a, const BigInteger &b)
{
    return a.getNumber() == b.getNumber() && a.getSign() == b.getSign();
}
bool operator!=(const BigInteger &a, const BigInteger &b)
{
    return !(a == b);
}
bool BigInteger::operator<(const BigInteger &b)
{

    bool sign_a = getSign(), sign_b = b.getSign();

    if (sign_a && !sign_b)
        return true;

    else if (!sign_a && sign_b)
        return false;

    else if (!sign_a)
    {
        if (getNumber().length() < b.getNumber().length())
            return true;
        if (getNumber().length() > b.getNumber().length())
            return false;
        return getNumber() < b.getNumber();
    }
    else
    {
        if (getNumber().length() > b.getNumber().length())
            return true;
        if (getNumber().length() < b.getNumber().length())
            return false;
        return getNumber().compare(b.getNumber()) > 0;
    }
}

bool BigInteger::operator>(const BigInteger &b)
{

    if (!((*this) == b) && !((*this) < b))
        return true;
    return false;
}

bool BigInteger::operator>=(const BigInteger &b)
{
    if (((*this) > b) || ((*this) == b))
        return true;
    return false;
}

bool BigInteger::operator<=(const BigInteger &b)
{
    if (((*this) < b) || ((*this) == b))
        return true;
    return false;
}

string BigInteger::addZeros(string str, size_t n)
{
    while (n != 0)
    {
        str = "0" + str;
        n--;
    }
    return str;
}

/*------------------------------------------------------------------------
| Adding string idea has been sourced form here
| https://leetcode.com/problems/multiply-strings/solutions/1436603/with-addition-and-subtraction-only-old-school-way/
| https://leetcode.com/problems/multiply-strings/solutions/1563536/c-simple-solution-w-explanation-and-images-school-optimized-multiplication/
// std::to_string(std::stoi(num1) + std::stoi(num2)) but range error
// so we had to add the values index by index
--------------------------------------------------------------------------*/
string BigInteger::makeSum(string x, string y)
{
    if (x.length() > y.length())
    {
        y = addZeros(y, x.length() - y.length());
    }
    if (x.length() < y.length())
    {
        x = addZeros(x, y.length() - x.length());
    }

    string result = "";
    uint64_t sum, carry = 0;
    for (uint64_t idx = x.length(); idx-- > 0;)
    {
        sum = (uint64_t)x[idx] - '0' + (uint64_t)y[idx] - '0' + carry;
        if (sum > 9)
        {
            result = to_string(sum % 10) + result;
            carry = sum / 10;
        }
        else
        {
            result = to_string(sum) + result;
            carry = 0;
        }
    }

    if (carry != 0)
    {
        result = to_string(carry) + result;
    }
    return result;
}

/*------------------------------------------------------------------------
| String based subtraction logic has been sourced form this blogs
| https://leetcode.com/problems/multiply-strings/solutions/1436603/with-addition-and-subtraction-only-old-school-way/
--------------------------------------------------------------------------*/
string BigInteger::makeSub(string x, string y)
{
    string sub = (x.length() > y.length()) ? x : y;

    if (x.length() > y.length())
    {
        y = addZeros(y, x.length() - y.length());
    }
    if (x.length() < y.length())
    {
        x = addZeros(x, y.length() - x.length());
    }

    for (uint64_t idx = x.length(); idx-- > 0;)
    {
        if (x[idx] < y[idx])
        {
            x[idx] += 10;
            x[idx - 1]--;
        }
        sub[idx] = ((x[idx] - '0') - (y[idx] - '0')) + '0';
    }

    // erase leading zeros
    while (sub[0] == '0' && sub.length() != 1)
        sub.erase(0, 1);

    return sub;
}
