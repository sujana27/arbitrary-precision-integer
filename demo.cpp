#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include "bigint.hpp"
using namespace std;

int main()
{
    try
    {
        // + operator test cases
        // big int vs + int
        BigInteger bg1("2");
        BigInteger bg2(-52);
        BigInteger bg3 = bg1 + bg2;
        cout << bg1 << "\n";
        cout << bg3 << "\n";

        // big int vs - int
        BigInteger bg4("-243584903589043859043894454353454353454354358490358904385904389445435345435345435");
        BigInteger bg5(-52);
        BigInteger bg6 = bg4 + bg5;
        cout << bg6 << "\n";

        // += operator test cases
        // big int vs - int
        BigInteger bg7("-243584903589043859043894454353454353454354358490358904385904389445435345435345435");
        BigInteger bg8(-534549455);
        bg7 += bg8;
        cout << bg7 << "\n";

        // == operator test cases
        // big int vs - int
        if (bg2 == bg5)
            cout << bg5 << " is equal to " << bg2 << "\n";
        if (bg1 != bg2)
            cout << bg1 << " is not equal to " << bg2 << "\n";

        if (bg2 < bg1)
            cout << bg1 << " is bigger than " << bg2 << "\n";
        if (bg1 > bg2)
            cout << bg2 << " is smaller than " << bg1 << "\n";

        if (bg1 >= bg2)
            cout << bg1 << " is greater or equal than " << bg2 << "\n";

        if (bg2 <= bg1)
            cout << bg2 << " is smaller or equal than " << bg1 << "\n";
        if (bg2 <= bg5)
            cout << bg2 << " is smaller or equal than " << bg5 << "\n";

        BigInteger a("-11");
        BigInteger b(22);
        BigInteger c = a - b;

        cout << a - b << "\n";
        cout << c << "\n";
        a -= b;
        cout << a << "\n";
        cout << -a << "\n";
        cout << a << "\n";
        a += a;
        cout << a << "\n";
        BigInteger b2(-22);
        BigInteger b3(-22);
        b2 = -b2;
        BigInteger d = b2 * b3;
        cout << d << endl;
        // cout << b2 << endl;
        b2 *= b3;
        cout << b2 << endl;

        BigInteger b34;

        BigInteger b02 = b2 + b34;
        cout << b02 << endl;

        // BigInteger bg6 = bg5 + bg3;

        // cout << bg2 << "\n";
        // cout << bg5 << "\n";
        //  cout << bg6 << "\n";
        //    cout << bg3 << "\n";
        //    cout << bg4 << "\n";
        //    cout << bg5 << "\n";
        //    bg += bg2;
        //    cout << bg << "\n";

        // if (bg > bg2)
        //     cout << bg << " is greater than " << bg2 << "\n";
        // else if (bg < bg2)
        //     cout << bg << " is smaller than " << bg2 << "\n";
        // if (bg >= bg2)
        //     cout << bg << " is greater or equal than " << bg2 << "\n";
        // else if (bg <= bg2)
        //     cout << bg << " is smaller or equal than " << bg2 << "\n";
        // if (bg == bg2)
        //     cout << bg << " is equal to " << bg2 << "\n";
        // if (bg != bg2)
        //     cout << bg << " is not equal to " << bg2 << "\n";
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << '\n';
    }
    return 0;
}