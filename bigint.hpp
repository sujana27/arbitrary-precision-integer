/**
 * @file bigint.hpp
 * @author Sujana Saha (sahas33@mcmaster.ca)
 * @brief bigint functions
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 */

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
    BigInteger &operator+=(const BigInteger &);
    BigInteger &operator-=(const BigInteger &);
    BigInteger &operator*=(const BigInteger &);

    // friend BigInteger &operator+=(BigInteger &, const BigInteger &);
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

/**
 * @brief Construct a new Big Integer:: Big Integer object
 * empty constructor
 */
BigInteger::BigInteger()
{
    number = "0";
    sign = false;
}

/**
 * @brief Construct a new Big Integer:: Big Integer object
 *
 * @param str
 * string constructor
 */
BigInteger::BigInteger(const string &str)
{
    setNumber(str);
}

/**
 * @brief Construct a new Big Integer:: Big Integer object
 *
 * @param num
 * signed int constructor
 */
BigInteger::BigInteger(const int64_t &num)
{
    stringstream sStream;
    string sNum;
    sStream << num;
    sStream >> sNum;

    setNumber(sNum);
}

/**
 * @brief Construct a new Big Integer:: Big Integer object
 *
 * @param bigint
 *  for copy constructor and assignment
 */
BigInteger::BigInteger(const BigInteger &bigint) : number(bigint.number), sign(bigint.sign)
{
    // no operation
}

/**
 * @brief set and validate the string when creating bigint object
 * throws exception when any unwanted character appears in the input string
 * @param str
 */
void BigInteger::setNumber(const string &str)
{
    // validating here and throws not_a_number exception
    for (uint64_t i = 0; i < str.size(); i++)
    {
        if ((i == 0 && str[i] != '-' && !isdigit(str[i])) || (i != 0 && !isdigit(str[i])))
            throw not_a_number;
    }
    if (isdigit(str[0]))
    {
        number = str;
        sign = false;
    }
    else
    {
        number = str.substr(1);
        sign = true;
    }
}

/**
 * @brief essentially a getter
 *
 * @return string
 */
string BigInteger::getNumber() const
{
    return number;
}

/**
 * @brief if there is a sign, acts as getter
 *
 * @return true
 * @return false
 */
bool BigInteger::getSign() const
{
    return sign;
}

/**
 * @brief overload the + operator for the BigInteger object
 * Based on sign I am doing either addition or subtraction
 * Same sign add them
 * different sign: based on their length and sign add / subtract them
 *
 * @param left-hand side operand *this implicitly represented,  BigInteger
 * @return BigInteger
 *
 * String addition idea has been sourced from this resource
 * https://github.com/rgroshanrg/bigint/blob/14455a6a8f533865205ed8f0a5e27e6db02cbf53/bigint_function_definitions.h#L87
 */
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

/**
 * @brief overload the += operator for the BigInteger object
 * Down the road I am invoking the overloaded + operation
 *
 * @param  left-hand side operand *this implicitly represented
 * @param BigInteger
 * @return BigInteger addition result
 */
BigInteger &BigInteger::operator+=(const BigInteger &b)
{
    (*this) = (*this) + b;
    return (*this);
}

/**
 * @brief negation / unary
 * Just only change the sign of the object
 * if the value is zero 0 then we don't do any operation
 * @param  left-hand side operand *this implicitly represented
 * @return BigInteger as negation result
 */
BigInteger BigInteger::operator-()
{
    BigInteger negation;
    negation.number = getNumber();
    if (negation.getNumber().length() >= 1 && negation.getNumber()[0] != '0')
        negation.sign = !getSign();
    return negation;
}

/**
 * @brief subtraction between BigIntegers
 * changing the sing  of the 2nd parameter then down the road addition is happening using the overloaded + operator
 * @param  left-hand side operand *this implicitly represented
 * @param BigInteger b
 * @return BigInteger subtraction result
 */
BigInteger BigInteger::operator-(BigInteger b)
{
    b.sign = !(b.getSign());
    return (*this) + b;
}

/**
 * @brief overload of * operator for BigIntegers for multiplication
 * applying the theory of M * N matrix multiplication index by index
 * if there is carry then forward to the previous bit
 * if there is any leading zero in the front remove them before returning them
 * String multiplication logic has been sourced from here
 * https://leetcode.com/problems/multiply-strings/solutions/4460228/easy-solution-in-c/
 *
 * @param  left-hand side operand *this implicitly represented
 * @param BigInteger b
 * @return BigInteger product
 */
BigInteger BigInteger::operator*(const BigInteger &b)
{
    BigInteger product;
    string multiplicand = getNumber(), multiplier = b.getNumber();
    product.sign = getSign() ^ b.getSign();
    uint64_t n = multiplicand.size(), m = multiplier.size();

    string res(n + m, '0');
    for (uint64_t iIdx = n; iIdx-- > 0;)
    {
        for (uint64_t jIdx = m; jIdx-- > 0;)
        {
            int tSum = (res[1 + iIdx + jIdx] - '0') + (multiplicand[iIdx] - '0') * (multiplier[jIdx] - '0');
            res[iIdx + jIdx] += tSum / 10;
            res[1 + iIdx + jIdx] = tSum % 10 + '0';
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

/**
 * @brief  overloading the *= works as multiplication then assign
 * Down the road it is using the * operator that I have overloaded
 * @param  left-hand side operand *this implicitly represented
 * @param b
 * @return BigInteger *this
 */
BigInteger &BigInteger::operator*=(const BigInteger &b)
{
    (*this) = (*this) * b;
    return (*this);
}

/**
 * @brief  overloading the -= works as subtraction then assign
 * Down the road it is using the - operator that I have overloaded
 * @param  left-hand side operand *this implicitly represented
 * @param b
 * @return BigInteger *this
 */
BigInteger &BigInteger::operator-=(const BigInteger &b)
{
    (*this) = (*this) - b;
    return (*this);
}

/**
 * @brief assignment operator = is being overloaded here
 * if the reference of the two variables are not same then we only assign a <- b
 *
 * @param  left-hand side operand *this implicitly represented
 * @param BigInteger b
 * @return BigInteger *this
 */
BigInteger &BigInteger::operator=(const BigInteger &b)
{
    if (this != &b)
    {
        number = b.getNumber();
        sign = b.getSign();
    }
    return *this;
}
/**
 * @brief output stream << is being overloaded here
 * firstly add the sign and then add the number string
 * @param ostream out
 * @param BigInteger a
 * @return ostream out
 */
ostream &operator<<(ostream &out, const BigInteger &a)
{
    if (a.getSign())
    {
        out << "-" << a.getNumber();
        return out;
    }
    else
    {
        out << a.getNumber();
        return out;
    }
}

/**
 * @brief is equals operator == is being overloaded here
 * compare the signs and compares the value / number for 2 objects, if they carry same value then they are equal
 * @param BigInteger a
 * @param BigInteger b
 * @return true
 * @return false
 */
bool operator==(const BigInteger &a, const BigInteger &b)
{
    return a.getNumber() == b.getNumber() && a.getSign() == b.getSign();
}

/**
 * @brief is not equals operator != is being overloaded here
 * compare the signs and compares the value / number for 2 objects, if they carry same value then they are equal
 * underneath it's actually using the == operator that we have earlier overloaded
 * @param BigInteger a
 * @param BigInteger b
 * @return true
 * @return false
 */
bool operator!=(const BigInteger &a, const BigInteger &b)
{
    return !(a == b);
}

/**
 * @brief is smaller < is being overloaded here
 * Firstly compare the sign of the two variables if right has a negative sign then right is smaller
 * if left has a negative sign then left is smaller
 * in other case compare their length, if one of their length is smaller then that is smaller
 * if both of the sign are negative the we only compare strings lexicographically
 *
 * for lexicographically sorted string I have taken help form this solution of this problem
 * for this I have used c++ string.compare(string) function
 * https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
 *
 * @param  left-hand side operand *this implicitly represented
 * @param BigInteger b
 * @return true
 * @return false
 */
bool BigInteger::operator<(const BigInteger &b)
{

    bool sign_a = getSign(), sign_b = b.getSign();

    if (!sign_a && sign_b)
        return false;
    else if (sign_a && !sign_b)
        return true;
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

/**
 * @brief is greater > is being overloaded here
 * Underneath we are using the == and < operator here that we have overladed earlier
 * @param  left-hand side operand *this implicitly represented
 * @param BigInteger b
 * @return true
 * @return false
 */
bool BigInteger::operator>(const BigInteger &b)
{

    if (!((*this) == b) && !((*this) < b))
        return true;
    return false;
}

/**
 * @brief is greater or equal >= is being overloaded here
 * Underneath we are using the == and > operator here that we have overladed earlier
 * @param  left-hand side operand *this implicitly represented
 * @param b
 * @return true
 * @return false
 */
bool BigInteger::operator>=(const BigInteger &b)
{
    if (((*this) > b) || ((*this) == b))
        return true;
    return false;
}

/**
 * @brief is smaller or equal <= is being overloaded here
 * Underneath we are using the == and < operator here that we have overladed earlier
 * @param  left-hand side operand *this implicitly represented
 * @param b
 * @return true
 * @return false
 */
bool BigInteger::operator<=(const BigInteger &b)
{
    if (((*this) < b) || ((*this) == b))
        return true;
    return false;
}

/**
 * @brief for making two string equal length  we need to add leading zero
 * add the leading zeros and return the string
 * @param string str
 * @param size_t n // number of leading zero to be added
 * @return string
 */
string BigInteger::addZeros(string str, size_t n)
{
    while (n != 0)
    {
        str = "0" + str;
        n--;
    }
    return str;
}

/**
 * @brief this function works underneath of + operator, for making any summation + operator is invoking this function
 *
 * std::to_string(std::stoi(num1) + std::stoi(num2)) but range error because of big size
 * so we had to add the values index by index, it also invokes leading zero for making the string length equal
 *
 * Adding string idea has been sourced form here
 * https://leetcode.com/problems/multiply-strings/solutions/1436603/with-addition-and-subtraction-only-old-school-way/
 * https://leetcode.com/problems/multiply-strings/solutions/1563536/c-simple-solution-w-explanation-and-images-school-optimized-multiplication/
 * @param string x
 * @param string y
 * @return string
 */
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
        result = to_string(carry) + result;

    return result;
}

/**
 * @brief a string to string subtraction is implemented here
 *
 * so we had to subtract the values index by index, it also invokes leading zero for making the string length equal
 * finally it also discard the leading zero, if all of them are zero the keep the last zero only
 * String based subtraction logic has been sourced form this blogs
 * https://leetcode.com/problems/multiply-strings/solutions/1436603/with-addition-and-subtraction-only-old-school-way/
 *
 * @param string x
 * @param string y
 * @return string
 */
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
