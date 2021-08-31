# push_swap
In this project I got acquainted with the concept of the complexity of the algorithm.

The principe of sorting i used is desribed in this page https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a.

The Push_swap project is a very simple and highly effective algorithm project: data will
need to be sorted. I have at my disposal a set of int values, 2 stacks and a set of
instructions to manipulate both stacks.

I Wrote a program in C called push_swap which calculates and displays
on the standard output the smallest program using Push_swap instruction language that
sorts the integer arguments received.

Common rules:
• The game is composed of 2 stacks named a and b.
• To start with:
◦ a contains a random number of either positive or negative numbers without
any duplicates.
◦ b is empty
• The goal is to sort in ascending order numbers into stack a.
• To do this you have the following operations at your disposal:
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.

To check the work of the program:
1. make
2. ./push_swap "some random int values" (e.g ./push_swap 2 1 3 6 5 8) | wc -l(to check the quantity of completed operations). 
Also you can use something like that   "ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG".  
checker_Mac let you know know if the stack is sorted. 
