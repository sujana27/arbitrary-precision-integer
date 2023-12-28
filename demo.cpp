/**
 * @file demo.cpp
 * @author Sujana Saha (sahas33@mcmaster.ca)
 * @brief bigint based tests are added here for 14 different types of operations
 * @version 0.1
 * @date 2023-12-27
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "bigint.hpp"
using namespace std;

/**
 * @brief all types of tests between the BigIntegers are tested here in this function
 *
 * @param BigInteger variable1
 * @param BigInteger variable2
 */
void doOperations(BigInteger variable1, BigInteger variable2)
{
    BigInteger result;
    bool resultBool;

    cout << "\n========================================begin===============================================\n";

    // << output
    cout << "===================================== Operator : [ << ]  ===================================\n";
    try
    {

        cout << " The value of variable1 : " << variable1 << "\n";
        cout << " The value of variable2 : " << variable2 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // + addition
    cout << "===================================== Operator : [ + ] ======================================\n";
    try
    {
        result = variable1 + variable2;
        cout << "The addition result of " << variable1 << " and " << variable2 << " is " << result << "\n";

        result = variable2 + variable1;
        cout << "The addition result of " << variable2 << " and " << variable1 << " is " << result << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // - subtraction
    cout << "===================================== Operator : [ - ] ======================================\n";
    try
    {
        result = variable1 - variable2;
        cout << "The subtraction result of " << variable1 << " and " << variable2 << " is " << result << "\n";

        result = variable2 - variable1;
        cout << "The subtraction result of " << variable2 << " and " << variable1 << " is " << result << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // * multiplication
    cout << "===================================== Operator : [ * ] ======================================\n";
    try
    {
        result = variable1 * variable2;
        cout << "The multiplication result of " << variable1 << " and " << variable2 << " is " << result << "\n";

        result = variable2 * variable1;
        cout << "The multiplication result of " << variable2 << " and " << variable1 << " is " << result << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // += addition and assign
    cout << "===================================== Operator : [ += ] ======================================\n";
    try
    {
        cout << "The addition and assign result of " << variable1 << " and " << variable2 << " is ";
        variable1 += variable2;
        cout << variable1 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // -= subtraction and assign
    cout << "===================================== Operator : [ -= ] ======================================\n";
    try
    {
        cout << "The subtraction and assign result of " << variable1 << " and " << variable2 << " is ";
        variable1 -= variable2;
        cout << variable1 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // -= multiplication and assign
    cout << "===================================== Operator : [ *= ] ======================================\n";
    try
    {
        cout << "The multiplication and assign result of " << variable1 << " and " << variable2 << " is ";

        variable1 *= variable2;
        cout << variable1 << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // > is greater than
    cout << "===================================== Operator : [ > ] ======================================\n";
    try
    {
        resultBool = variable1 > variable2;
        cout << "Is  " << variable1 << " greater than  " << variable2 << " : " << resultBool << "\n";

        resultBool = variable2 > variable1;
        cout << "Is  " << variable2 << " greater than  " << variable1 << " : " << resultBool << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // < is smaller than
    cout << "===================================== Operator : [ < ] ======================================\n";
    try
    {
        resultBool = variable1 < variable2;
        cout << "Is  " << variable1 << " smaller than  " << variable2 << " : " << resultBool << "\n";

        resultBool = variable2 < variable1;
        cout << "Is  " << variable2 << " smaller than  " << variable1 << " : " << resultBool << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // >= is greater than equal
    cout << "===================================== Operator : [ >= ] ======================================\n";
    try
    {
        resultBool = variable1 >= variable2;
        cout << "Is  " << variable1 << " greater than equal  " << variable2 << " : " << resultBool << "\n";

        resultBool = variable2 >= variable1;
        cout << "Is  " << variable2 << " greater than equal  " << variable1 << " : " << resultBool << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // <= is smaller than equal
    cout << "===================================== Operator : [ <= ] ======================================\n";
    try
    {
        resultBool = variable1 <= variable2;
        cout << "Is  " << variable1 << " smaller than equal  " << variable2 << " : " << resultBool << "\n";

        resultBool = variable2 <= variable1;
        cout << "Is  " << variable2 << " smaller than equal  " << variable1 << " : " << resultBool << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // == is equal  to
    cout << "===================================== Operator : [ == ] ======================================\n";
    try
    {
        resultBool = variable1 == variable2;
        cout << "Is  " << variable1 << " is equal  to  " << variable2 << " : " << resultBool << "\n";

        resultBool = variable2 == variable1;
        cout << "Is  " << variable2 << " is equal  to " << variable1 << " : " << resultBool << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // != is not equal  to
    cout << "===================================== Operator : [ != ] ======================================\n";
    try
    {
        resultBool = variable1 != variable2;
        cout << "Is  " << variable1 << " is not equal  to  " << variable2 << " : " << resultBool << "\n";

        resultBool = variable2 != variable1;
        cout << "Is  " << variable2 << " is not equal  to " << variable1 << " : " << resultBool << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // - val / +/- sign change  / negation
    cout << "===================================== Operator : [ -val ] ======================================\n";
    try
    {
        result = -variable1;
        cout << " The negation of " << variable1 << " is  : " << result << "\n";

        result = -variable2;
        cout << " The negation of " << variable2 << " is  : " << result << "\n";
    }
    catch (const exception &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "========================================endl===============================================\n";
}
/**
 * @brief main execution function
 *
 * @return int
 */

int main()
{
    // initialize with empty/default constructor
    BigInteger bigint1;
    BigInteger bigint2;
    BigInteger temp_obj;

    int64_t intValue;
    string stringValue;
    string line;
    ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        cerr << "Error opening the file.\n\n";
        return 1;
    }
    int counter = 0;
    while (getline(inputFile, line))
    {

        istringstream iss(line);
        // ignore empty lines
        if (line.length() == 0)
            continue;
        // validating the input with the constructor if there is any special char available in the input
        try
        {
            temp_obj = BigInteger(line);
        }
        catch (const exception &e)
        {
            cerr << e.what() << line << "\n";
            continue;
        }

        //  we can essentially don't need this since inputs are coming as a string
        // however we have used it as per project  requirement, but this is a redundant of the object
        if (iss >> intValue) // input is integer convertible then invoke signed integer constructor
        {
            if (counter == 0)
                bigint1 = BigInteger(intValue);
            else
                bigint2 = BigInteger(intValue);
        }
        else // everything else considered as string constructor
        {
            if (counter == 0)
                bigint1 = temp_obj;
            else
                bigint2 = temp_obj;
        }

        // will consider only 2 inputs as a pair to do the operations
        counter++;
        if (counter >= 2)
        {
            counter = 0;
            try
            {
                doOperations(bigint1, bigint2);
            }
            catch (const exception &e)
            {
                cerr << e.what() << '\n';
            }
        }
    }

    return 0;
}