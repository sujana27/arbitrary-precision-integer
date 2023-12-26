#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "bigint.hpp"
using namespace std;

void doOperations(BigInteger variable1, BigInteger variable2)
{
    BigInteger result;
    bool resultBool;

    cout << "========================================begin===============================================\n\n";

    // << output
    cout << "===================================== Opreator : [ << ]  ===================================\n";
    try
    {

        cout << " The value of variable2 should be showed in cli is : " << variable1 << "\n\n";
        cout << " The value of variable2 should be showed in cli is : " << variable2 << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // + addition
    cout << "===================================== Opreator : [ + ] ======================================\n";
    try
    {
        result = variable1 + variable2;
        cout << "The additon result of " << variable1 << " and " << variable2 << " is " << result << "\n\n";

        result = variable2 + variable1;
        cout << "The additon result of " << variable2 << " and " << variable1 << " is " << result << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // - subtraction
    cout << "===================================== Opreator : [ - ] ======================================\n";
    try
    {
        result = variable1 - variable2;
        cout << "The subtraction result of " << variable1 << " and " << variable2 << " is " << result << "\n\n";

        result = variable2 - variable1;
        cout << "The subtraction result of " << variable2 << " and " << variable1 << " is " << result << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // * multiplication
    cout << "===================================== Opreator : [ * ] ======================================\n";
    try
    {
        result = variable1 * variable2;
        cout << "The multiplication result of " << variable1 << " and " << variable2 << " is " << result << "\n\n";

        result = variable2 * variable1;
        cout << "The multiplication result of " << variable2 << " and " << variable1 << " is " << result << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // * multiplication

    // += addition and assign
    cout << "===================================== Opreator : [ += ] ======================================\n";
    try
    {
        result = variable1;
        result += variable2;
        cout << "The addition and assign result of " << variable1 << " and " << variable2 << " is " << result << "\n\n";

        result = variable2;
        result += variable1;
        cout << "The addition and assign result of " << variable2 << " and " << variable1 << " is " << result << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // -= subtraction and assign
    cout << "===================================== Opreator : [ -= ] ======================================\n";
    try
    {
        result = variable1;
        result -= variable2;
        cout << "The subtraction and assign result of " << variable1 << " and " << variable2 << " is " << result << "\n\n";

        result = variable2;
        result -= variable1;
        cout << "The subtraction and assign result of " << variable2 << " and " << variable1 << " is " << result << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // -= multiplication and assign
    cout << "===================================== Opreator : [ *= ] ======================================\n";
    try
    {
        result = variable1;
        result *= variable2;
        cout << "The multiplication and assign result of " << variable1 << " and " << variable2 << " is " << result << "\n\n";

        result = variable2;
        result *= variable1;
        cout << "The multiplication and assign result of " << variable2 << " and " << variable1 << " is " << result << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // > is greater than
    cout << "===================================== Opreator : [ > ] ======================================\n";
    try
    {
        resultBool = variable1 > variable2;
        cout << "Is  " << variable1 << " greater than  " << variable2 << " : " << resultBool << "\n\n";

        resultBool = variable2 > variable1;
        cout << "Is  " << variable2 << " greater than  " << variable1 << " : " << resultBool << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // < is smaller than
    cout << "===================================== Opreator : [ < ] ======================================\n";
    try
    {
        resultBool = variable1 < variable2;
        cout << "Is  " << variable1 << " smaller than  " << variable2 << " : " << resultBool << "\n\n";

        resultBool = variable2 < variable1;
        cout << "Is  " << variable2 << " smaller than  " << variable1 << " : " << resultBool << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // >= is greater than equal
    cout << "===================================== Opreator : [ >= ] ======================================\n";
    try
    {
        resultBool = variable1 >= variable2;
        cout << "Is  " << variable1 << " greater than equal  " << variable2 << " : " << resultBool << "\n\n";

        resultBool = variable2 >= variable1;
        cout << "Is  " << variable2 << " greater than equal  " << variable1 << " : " << resultBool << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // <= is smaller than equal
    cout << "===================================== Opreator : [ <= ] ======================================\n";
    try
    {
        resultBool = variable1 <= variable2;
        cout << "Is  " << variable1 << " smaller than equal  " << variable2 << " : " << resultBool << "\n\n";

        resultBool = variable2 <= variable1;
        cout << "Is  " << variable2 << " smaller than equal  " << variable1 << " : " << resultBool << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // == is equal  to
    cout << "===================================== Opreator : [ == ] ======================================\n";
    try
    {
        resultBool = variable1 == variable2;
        cout << "Is  " << variable1 << " is equal  to  " << variable2 << " : " << resultBool << "\n\n";

        resultBool = variable2 == variable1;
        cout << "Is  " << variable2 << " is equal  to " << variable1 << " : " << resultBool << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // != is not equal  to
    cout << "===================================== Opreator : [ != ] ======================================\n";
    try
    {
        resultBool = variable1 != variable2;
        cout << "Is  " << variable1 << " is not equal  to  " << variable2 << " : " << resultBool << "\n\n";

        resultBool = variable2 != variable1;
        cout << "Is  " << variable2 << " is not equal  to " << variable1 << " : " << resultBool << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "===========================================================================================\n\n";

    // - val / +/- sign cahnge  / negation
    cout << "===================================== Opreator : [ -val ] ======================================\n";
    try
    {
        result = -variable1;
        cout << " The negation of " << variable1 << " is  : " << result << "\n\n";

        result = -variable2;
        cout << " The negation of " << variable2 << " is  : " << result << "\n\n";
    }
    catch (const invalid_argument &e)
    {
        cerr << e.what() << '\n';
    }
    cout << "========================================endl===============================================\n\n";
}

int main(int argc, char *argv[])
{
    BigInteger bigint1;
    BigInteger bigint2;

    if (argc < 3)
    {
        cout << "Number of command-line arguments: " << argc << " \n You must supply at least 2 input"
             << "\n\n";
    }
    else
    {
        try
        {
            bigint1 = BigInteger(string(argv[1]));
            bigint2 = BigInteger(string(argv[2]));
            doOperations(bigint1, bigint2);
        }
        catch (const invalid_argument &e)
        {
            cerr << e.what() << '\n';
        }
    }

    return 0;
}