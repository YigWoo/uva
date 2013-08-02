Decode The Tape
===============

Your boss has just unearthed a roll of old computer tapes. The tapes have holes in them and might contain some sort of useful information. It falls to you to figure out what is written on them.

Input
-----
The input will contain one tape.

Output
------
Output the message that is written on the tape.

Sample Input
---------------
	# A ' '(space) might denote 0
	# A 'o'(oh) might denote 1
	# A '.'(dot) denote nothing. eliminate it.
	___________
	| o   .  o| A 0100 0001
	|  o  .   |   0010 0000
	| ooo .  o| q
	| ooo .o o| u
	| oo o.  o| i
	| oo  . oo| c
	| oo o. oo| k
	|  o  .   | 
	| oo  . o | b
	| ooo . o | r
	| oo o.ooo| o
	| ooo .ooo| w
	| oo o.oo | n
	|  o  .   | 
	| oo  .oo | f
	| oo o.ooo| o
	| oooo.   | x
	|  o  .   | 
	| oo o. o | j
	| ooo .o o| u
	| oo o.o o| m
	| ooo .   | p
	| ooo . oo| s
	|  o  .   | 
	| oo o.ooo| o
	| ooo .oo | v
	| oo  .o o| e
	| ooo . o | r
	|  o  .   | 
	| ooo .o  | t
	| oo o.   | h
	| oo  .o o| e
	|  o  .   | 
	| oo o.o  | l
	| oo  .  o| a
	| oooo. o | z
	| oooo.  o| y
	|  o  .   | 
	| oo  .o  | d
	| oo o.ooo| o 0110 1111
	| oo  .ooo| g 0110 0111
	|  o o.oo | . 0010 1110
	|    o. o |\n 0000 1010
	___________


Sample Output
---------------
	A quick brown fox jumps over the lazy dog.
