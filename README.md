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
        |- input.txt

## How to compile and run

1) Open terminal or cmd in the file direcotry ```cd /file/direcotry/```
2) Compile the code with `g++` or `CLang` like `g++ demo.cpp -o demo.o`
3) Run `./demo.o` 
4) In the follwing stage you will see a bunch of 14 different types of instructions output that mentioned in above.
5) program is capable of reading input files form `input.txt` file.

## How to supply input in inout.txt file
Supply input will be read line by line, which means one number at a line. a set of 2 consecutive valid input perform operations **The number of valid inputs must be a even number** Otherwise the code will skip the the last valid input and do not do further operation with one.

Example input:
```
-23
24
-100
-100
-32432E //invalid and will be skipped
*5435 //invalid and will be skipped
-34320490329402394
34324903249
``` 



Additinal exmaple input are supplied in the input.txt file, it can handle more or less invalid input like 
- `*3242` => any special character inside input is a invalid case
- `343E34` `A3432B` => any alpha-numberic input is a invalid case
- ` 45 ` => capable of removing whitespace form fornt and rear


// Copyright (c) Sujana Saha. All rights reserved. Licensed under the MIT license.
