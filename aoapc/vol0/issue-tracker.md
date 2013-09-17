## 10055 Hashmat the brave warrior
1. In c++, int is a 4-byte data, which is 32 bits, and the range for signed int is (-32767, 32767), and the range for unsigned int (0, 65535), because the input numer is ensured to be no greater than 2^32, using int will not suffice the requirement. The minimum numerical type used should be long long, which has a range of (-(2^63 - 1), +(2^63 + 1)). refer to [size-of-int-long-etc](http://stackoverflow.com/questions/589575/size-of-int-long-etc) for more infomation.

2. "Each line denote the number of soldiers in Hashmat's army and his opponent's army __or vice versa__. Reading the line carefully, it really counts here.

## 10071 Back to high school physics
No issues

## 10300 Ecological Premium
No issues

## 414 Machine Surface
No issues

## 488 Triangle Wave
Accepted, but too slow. 1.992seconds, try to figure out a way to enhance your permance!

## 457 Linear Cellular Antomata
1. BLANK LINES!! BLANK LINES!! BLANK LINES!! BLANK LINES!! BLANK LINES!! BLANK LINES!! BLANK LINES!! __BE CAREFUL WHEN YOU OUTPUT BLANK LINES, THAT HURTS YOU!__

## 458 decoder
No issues

## 490 Rotate Sentences
1. __Unclear__. How to trim tabs in a cpp string.

    - Problem: using `string::erase` of when encounters a tab lefts one tab in the string.
	- Reason: still thinking.
	- Other way to trim tab in a cpp string: see [remove a tab from a string](http://stackoverflow.com/questions/556277/trim-remove-a-tab-t-from-a-string)

2. About the input and output

    - do not have to consider tab in the input
    - use space as placeholders.
    - you're thinking too much..

## 494 Kindergarten Counint Game
1. "words" are consecutive sequences of letters(upper or lower case). Which means, any non-consecutive letters should be counted as two words. Like, abc123abc, counts for two words.

## 694 Collatz Sequence

1. if A is too large, be careful of integer overflow. For e.g, if you use `int` type for A and L, case: 2147483646 2147483647, a * 3 + 1 will cause range overflow!
