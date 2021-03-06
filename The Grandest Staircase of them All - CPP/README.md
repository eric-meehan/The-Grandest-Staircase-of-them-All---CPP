The Grandest Staircase of them All
======================

This problem was presented to me through the Google FooBar challenge.  Though the directions specify a Java or Python solution, this program was written in C++ to illustrate competency in that language.

This program was compiled on MacOS Catalina 10.15.7 with GCC using the command:
g++ main.cpp -o main.exe

With her LAMBCHOP doomsday device finished, Commander Lambda is preparing for her debut on the galactic stage - but in order to make a grand entrance, she needs a grand staircase! As her personal assistant, you've been tasked with figuring out how to build the best staircase EVER.

Lambda has given you an overview of the types of bricks available, plus a budget. You can buy different amounts of the different types of bricks (for example, 3 little pink bricks, or 5 blue lace bricks). Commander Lambda wants to know how many different types of staircases can be built with each amount of bricks, so she can pick the one with the most options.

Each type of staircase should consist of 2 or more steps. No two steps are allowed to be at the same height - each step must be lower than the previous one. All steps must contain at least one brick. A step's height is classified as the total amount of bricks that make up that step. For example, when N = 3, you have only 1 choice of how to build the staircase, with the first step having a height of 2 and the second step having a height of 1: (# indicates a brick)

```
#
##
21
```

When N = 4, you still only have 1 staircase choice:

```
#
#
##
31
```

But when N = 5, there are two ways you can build a staircase from the given bricks. The two staircases can have heights (4, 1) or (3, 2), as shown below:

```
#
#
#
##
41
```
```
#
##
##
32
```


Languages
=========

To provide a Python solution, edit solution.py

To provide a Java solution, edit solution.java

Test cases
==========

Test Case One:

Inputs:
```
(int) n = 3
```
Output:
```
(int) 1
```

Test Case Two:

Inputs:
```
(int) n = 200
```
Output:
```
(int) 487067745
```
