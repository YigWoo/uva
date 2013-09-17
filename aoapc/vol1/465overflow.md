Overflow 
========
Write a program that reads an expression consisting of two non-negative integer and an operator. Determine if either integer or the result of the expression is too large to be represented as a "normal" signed integer (type integer if you are working Pascal, type int if you are working in C).

Input
-----
An unspecified number of lines. Each line will contain an integer, one of the two operators + or *, and another integer.

Output
------
For each line of input, print the input followed by 0-3 lines containing as many of these three messages as are appropriate: "first number too big", "second number too big", "result too big".

Sample Input
------------
    300 + 3
    9999999999999999999999 + 11

Sample Output
-------------
    300 + 3
    9999999999999999999999 + 11
    first number too big
    result too big
