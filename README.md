# Student Information

- Name: Sujana Saha
- Student Id: 400546546
- Course: CSE701: Scientific Computing
- Project: Arbitrary Precision Signed Integer

## BigInteger / Arbitrary Precision Signed Integer

Big - Integer is a set of machine instruction for handling higher order integers which doesn't fit in primitive(maximum `2^64-1` unsigned) type machine instructions C++ language. This code is capable of handling those higher order arbitrary precisions of integer number.

## Intuition and Approach

If we can store the number as a string in the BigInteger object and it's sign, then we can implement the operations character by character. Whenever it will be un equal then in that case we can add leading zeros to make them equal so that the operation handling would be smoother.

For example: for a given input as `-400` and `400000` the operation will look like 
```
sign 000400
sign 400000
-----------
sign output
```


The code is written in C++ 20, and can perform the following 14 instructions by overloading those operators that are available in C++:

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

## Files Directory

    - arbitrary-precision-integer
        |- bigint.hpp
        |- demo.cpp
        |- readme.md
        |- input.txt

## How to compile and run

1) Open terminal or cmd in the file directory ```cd /file/directory/```
2) Compile the code with `g++` or `CLang` like `g++ demo.cpp -o demo.o`
3) Run `./demo.o`
4) In the following stage you will see a bunch of 14 different types of instructions output that mentioned in above.
5) program is capable of reading input files form `input.txt` file.

## How to supply input in input.txt file

Supply input will be read line by line, which means one number at a line. a set of 2 consecutive valid input perform operations **The number of valid inputs must be a even number** Otherwise the code will skip the the last valid input and do not do further operation with one. Here are a sample of multiple inputs-

```
-23
24
-100
-100
-32432E //invalid and will be skipped
*5435 //invalid and will be skipped
ghfl%45#^$#!  // invalid case and will be skipped
-34320490329402394
34324903249

```

Additional example input are supplied in the input.txt file, it can handle more or less invalid input like 
- `*3242` => any special character inside input is a invalid case
- `343E34` `A3432B` => any alpha-numeric input is a invalid case


## Warnings
The whole code is warning free and has been tested to with `"-Wall",
                "-Wextra",
                "-Wconversion",
                "-Wsign-conversion",
                "-Wshadow",
                "-Wpedantic"
                "-std=c++20"` compiler arguments.


## Sample Input:
```
-std=c++20
ghfl%45#^$#!
-12
23
```


## Sample Output 

```

Not a valid input: -std=c++20
Not a valid input: ghfl%45#^$#!

========================================begin===============================================
===================================== Operator : [ << ]  ===================================
 The value of variable1 : -12
 The value of variable2 : 23
===========================================================================================

===================================== Operator : [ + ] ======================================
The addition result of -12 and 23 is 11
The addition result of 23 and -12 is 11
===========================================================================================

===================================== Operator : [ - ] ======================================
The subtraction result of -12 and 23 is -35
The subtraction result of 23 and -12 is 35
===========================================================================================


===================================== Operator : [ * ] ======================================
The multiplication result of -12 and 23 is -276
The multiplication result of 23 and -12 is -276
===========================================================================================

===================================== Operator : [ += ] ======================================
The addition and assign result of -12 and 23 is 11
===========================================================================================

===================================== Operator : [ -= ] ======================================
The subtraction and assign result of 11 and 23 is -12
===========================================================================================

===================================== Operator : [ *= ] ======================================
The multiplication and assign result of -12 and 23 is -276
===========================================================================================

===================================== Operator : [ > ] ======================================
Is  -276 greater than  23 : 0
Is  23 greater than  -276 : 1
===========================================================================================

===================================== Operator : [ < ] ======================================
Is  -276 smaller than  23 : 1
Is  23 smaller than  -276 : 0
===========================================================================================

===================================== Operator : [ >= ] ======================================
Is  -276 greater than equal  23 : 0
Is  23 greater than equal  -276 : 1
===========================================================================================

===================================== Operator : [ <= ] ======================================
Is  -276 smaller than equal  23 : 1
Is  23 smaller than equal  -276 : 0
===========================================================================================

===================================== Operator : [ == ] ======================================
Is  -276 is equal  to  23 : 0
Is  23 is equal  to -276 : 0
===========================================================================================

===================================== Operator : [ != ] ======================================
Is  -276 is not equal  to  23 : 1
Is  23 is not equal  to -276 : 1
===========================================================================================

===================================== Operator : [ -val ] ======================================
 The negation of -276 is  : 276
 The negation of 23 is  : -23
========================================endl===============================================
```




# References
[1] https://github.com/rgroshanrg/bigint/blob/14455a6a8f533865205ed8f0a5e27e6db02cbf53/bigint_function_definitions.h#L87

[2] https://leetcode.com/problems/multiply-strings/solutions/4460228/easy-solution-in-c/

[3] https://leetcode.com/problems/multiply-strings/solutions/1436603/with-addition-and-subtraction-only-old-school-way/
 
[4] https://leetcode.com/problems/multiply-strings/solutions/1563536/c-simple-solution-w-explanation-and-images-school-optimized-multiplication/

// Copyright (c) Sujana Saha. All rights reserved. Licensed under the MIT license.
