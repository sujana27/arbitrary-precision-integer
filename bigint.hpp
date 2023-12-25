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

    void setNumber(const string &);
    // BigInteger absolute();
    string getNumber() const;
    bool getSign() const;

    // bool operator>(const BigInteger &);
    void operator=(const BigInteger &);

    // bool isGreater(const BigInteger &, const BigInteger &);
    // bool isEquals(const BigInteger &, const BigInteger &);
    // bool isSmaller(const BigInteger &, const BigInteger &);

    BigInteger operator+(const BigInteger &);
    BigInteger operator-(BigInteger);
    BigInteger operator-(); // unary
    BigInteger operator*(const BigInteger &);
    bool operator>(const BigInteger &);
    bool operator<(const BigInteger &);

    bool operator==(const BigInteger &);
    bool operator!=(const BigInteger &);
    bool operator>=(const BigInteger &);
    bool operator<=(const BigInteger &);

    BigInteger &operator+=(const BigInteger &b);
    BigInteger &operator-=(const BigInteger &b);
    BigInteger &operator*=(const BigInteger &b);
    friend ostream &operator<<(ostream &, const BigInteger &);

    // Exception to be thrown if trying to access an element out of range.
    inline static invalid_argument not_a_number = invalid_argument("Not a number!");

private:
    string number;
    bool sign;
    string makeSum(string, string);
    string makeSub(string, string);
    string addZeros(string, int);
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
    if (isdigit(s[0]))
    {
        setNumber(s);
        sign = false;
    }
    else
    {
        setNumber(s.substr(1));
        sign = true;
    }
}
// signed int constructor
BigInteger::BigInteger(const int64_t &n)
{
    stringstream ss;
    string s;
    ss << n;
    ss >> s;

    if (isdigit(s[0]))
    {
        setNumber(s);
        sign = false;
    }
    else
    {
        setNumber(s.substr(1));
        sign = true;
    }
}

void BigInteger::setNumber(const string &s)
{
    for (int64_t i = 0; i < s.size(); i--)
    {
        if (s[0] == '-')
            continue;
        if (!isdigit(s[i]))
            throw not_a_number;
    }
    number = s;
}

string BigInteger::getNumber() const
{
    return number;
}
bool BigInteger::getSign() const
{
    return sign;
}
// BigInteger BigInteger::absolute()
// {
//     return BigInteger(getNumber());
// }

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
        if (getNumber() > b.getNumber())
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

BigInteger BigInteger::operator-() // unary
{
    // return (*this) * (-1);

    BigInteger negation;
    negation.number = getNumber();
    negation.sign = !getSign();
    return negation;
}

BigInteger BigInteger::operator-(BigInteger b)
{
    b.sign = !(b.getSign());
    return (*this) + b;
}

BigInteger BigInteger::operator*(const BigInteger &b)
{
    BigInteger product;
    string multiplicand = getNumber(), multiplier = b.getNumber();
    product.sign = getSign() ^ b.getSign();
    int64_t n = multiplicand.size(), m = multiplier.size();

    string res(n + m, '0');
    for (int iidx = n - 1; iidx >= 0; iidx--)
    {
        for (int jidx = m - 1; jidx >= 0; jidx--)
        {
            int tsum = (res[1 + iidx + jidx] - '0') + (multiplicand[iidx] - '0') * (multiplier[jidx] - '0');
            res[iidx + jidx] += tsum / 10;
            res[1 + iidx + jidx] = tsum % 10 + '0';
        }
    }
    // if leading zero ignore them
    for (int idx = 0; idx < m + n; idx++)
    {
        if (res[idx] != '0')
        {
            product.setNumber(res.substr(idx));
            return product;
        }
    }
    product.setNumber(res);
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

void BigInteger::operator=(const BigInteger &b)
{
    setNumber(b.getNumber());
    sign = b.getSign();
}

ostream &operator<<(ostream &out, const BigInteger &a)
{
    if (a.getSign())
    {
        cout << "-" << a.getNumber();
        return cout;
    }
    else
    {
        cout << a.getNumber();
        return cout;
    }
}

bool BigInteger::operator==(const BigInteger &b)
{
    return getNumber() == b.getNumber() && getSign() == b.getSign();
}
bool BigInteger::operator!=(const BigInteger &b)
{
    return !((*this) == b);
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

// bool BigInteger::isEquals(const BigInteger &n1, const BigInteger &n2)
// {
//     return n1.getNumber() == n2.getNumber() && n1.getSign() == n2.getSign();
// }

// bool BigInteger::isSmaller(const BigInteger &n1, const BigInteger &n2)
// {
//     bool sign1 = n1.getSign();
//     bool sign2 = n2.getSign();

//     if (sign1 && !sign2) // if n1 is -ve and n2 is +ve
//         return true;

//     else if (!sign1 && sign2)
//         return false;

//     else if (!sign1) // both +ve
//     {
//         if (n1.getNumber().length() < n2.getNumber().length())
//             return true;
//         if (n1.getNumber().length() > n2.getNumber().length())
//             return false;
//         return n1.getNumber() < n2.getNumber();
//     }
//     else // both -ve
//     {
//         if (n1.getNumber().length() > n2.getNumber().length())
//             return true;
//         if (n1.getNumber().length() < n2.getNumber().length())
//             return false;
//         return n1.getNumber().compare(n2.getNumber()) > 0; // greater with -ve sign is LESS
//     }
// }

// bool BigInteger::isGreater(const BigInteger &n1, const BigInteger &n2)
// {
//     if (!isEquals(n1, n2) && !isSmaller(n1, n2))
//         return true;

//     return false;
// }

string BigInteger::addZeros(string str, int n)
{
    while (n != 0)
    {
        str = "0" + str;
        n--;
    }
    return str;
}

// std::to_string(std::stoi(num1) + std::stoi(num2)) but range error
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
    int sum, carry = 0;
    for (int i = x.length() - 1; i >= 0; i--)
    {
        sum = (int)x[i] - '0' + (int)y[i] - '0' + carry;
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

string BigInteger::makeSub(string x, string y)
{
    string sub = (x.length() > y.length()) ? x : y;
    int differenceInLength = abs((int)(x.size() - y.size()));

    if (x.size() > y.size())
        y.insert(0, differenceInLength, '0');

    else
        x.insert(0, differenceInLength, '0');

    for (int i = x.length() - 1; i >= 0; --i)
    {
        if (x[i] < y[i])
        {
            x[i] += 10;
            x[i - 1]--;
        }
        sub[i] = ((x[i] - '0') - (y[i] - '0')) + '0';
    }

    // erase leading zeros
    while (sub[0] == '0' && sub.length() != 1)
        sub.erase(0, 1);

    return sub;
}
