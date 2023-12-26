## BigInteget / Arbitrary Precision Signed Integer

Big - Integer is a set of machine instuction for handling higer order intergers which doesn't fit in premetive(maximum 2^64) type machine instructions C++ language. This code is capable of handling those higher order arbitrary precisions of integer number.

The code is written in C++ 20, and can perform the follwing 14 instructions by overloading those operaotrs that are available in C++:

|Operator   | Instruction  | Return type  |   Example |
|---|---|---|---|
|  + | addition  |   BigInteger |  d = a + b  |
|  - |  subtraction |   BigInteger |  d = a - b |
|  * |  multiplication | BigInteger |  d = a * b |
|  += | addition and assign  |  BigInteger |  a += b |
|  -= |  subtraction  and assign|   BigInteger |  a -= b |
|  *= |  multiplication  and assign|   BigInteger |  a *= b |
|  > | greater  | boolean | a > b |
|  < |  smaller | boolean | a < b |
|  >= |  grater than equal | boolean | a >= b |
|  <= | smaller than equal  |   boolean | a <= b |
|  != |  unequal check |   boolean  | a != b |
|  == |  equal check |  boolean | a == b |
|  = | assignment  |   boolean | a = b |
|  - val |  sign change |    BigInteger |  a = -a|
|  <<|  print |  ostream | cout << a  |

## Files Direcotry

    - arbitrary-precision-integer
        |- bigint.hpp
        |- demo.cpp
        |- readme.md

## How to compile and run

1) Open terminal or cmd in the file direcotry ```cd /file/direcotry/```
2) Compile the code with `g++` or `CLang` like `g++ demo.cpp -o demo.o`
3) Run `./demo.o param1 param2` an example could be `./demo.o 32423 -3284328947832773832`
4) In the follwing stage you will see a bunch of 14 different types of instructions output that mentioned in above.

Here `param1` and `param2` are the supplied command line arguments,  currently the code itself only working with the first 2 parameters, rest of them will be ignored.

// Copyright (c) Sujana Saha. All rights reserved. Licensed under the MIT license.
