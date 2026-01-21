*This project has been created as part of the 42 curriculum by macamach*

## Description 
The *push_swap* project is a highly structured algorithmic challenge focused on sorting data. The objective is to sort a stack of integers using a limited set of instructions and a secondary stack, aiming for the lowest possible number of operations.

### The Rules:

* You have two stacks: *a* and *b*. 
* At the start, the stack *a* contains a random number of **unique** poitive and/or negative integers
* Stack *b* is initally empty
* The goal is to sort the numbers in stack *a* in ascending order

TThe program calculates and displays the shortest sequence of instructions required to achieve the sort.

## Instructions

### Compilation
The project compile using a Makefile with the rules:

* all: compiles the push_swap program and the libft library.
* clean: deletes all object files. 
* fclean: deletes all object files and the compiled programs.
* re: cleans and recompiles the entire project.

### Execution

The program takes a list of integers as arguments to initialize stack a. The first argument provided will be at the top of the stack.

```
./push_swap 2 1 3 6 5 8
# or
./push_swap "2 1 3 6 5 8"
#or
./push_swap 10 "2 1 3 6 5 8" 9 11
```
The output will be a list of instructions (e.g., sa, pb, ra) separated by a newlines.

```
./push_swap 2 1 3 6 5 8
ra
pb
rra
pb
pb
sa
pa
pa
pa
```
### Verification
You can verify the results by sending the output of push_swap directly into the checker program:
```
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
## Error Handling

If invalid arguments are provided (e.g., non-integers, duplicates, or numbers exceeding integer limits), the program displays Error followed by a newline on the standard error output.

If there is no arguments, the program return the prompt
If the argument is an empty string return 'Error\n'
If the argumente is a string just with spaces return 'Error\n' 

## Resources:

### External References
* https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0 - Logic for the cost-calculation algorithm.

* https://www.youtube.com/watch?v=wRvipSG4Mmk - Basic concepts for stack manipulation.

* https://valgrind.org/docs/manual/faq.html#faq.deflost - Valgrind manual

## AI Usage
AI tools were used during this project for:
* Researching different sorting strategies and understanding instruction logic.
* Reviewing the README.md for requirements, structure, spelling, and grammar.
* Consulting on coding best practices (e.g., header file organization and memory management).
* Optimizing the Makefile structure.

## Technical Choices and Operations (Additional Section)

### Algorithn Selection

#### Small Sets (<= 12 integers): Selection Sort

1. **Min-Selection:** Identifies the smallest element, rotates it to the top of *a*, and pushes itto *b*

2. **Base Case (3 elements):** This repeats until only 3 elements remain in stack *a*, which are then sorted in a maximum of 2 moves.

3. **Push Back:** Elements are pushed back from *b* to *a* in the correct order.

#### Large Sets (> 12 integers): Cost-Calculation Algorithm 
This approach calculates the "cost" (number of operations like ra, rb, rr) to move each element from *a* to its correct position in *b*. The program executes the operations for the "cheapest" element first.

###  Data Structure: Arrays
I chose to use fixed-size arrays instead of linked lists for the following reasons:

1. Memory Safety: ince the number of integers is known at the start, I allocate memory once, reducing the risk of leaks associated with frequent malloc calls.

2. Reduced Complexity: Arrays avoid complex pointer manipulation, preventing potential segmentation faults.

3. Data Locality: Contiguous memory storage provides better cache performance.

### Allowed instructions

| Instruction | Description                                                                       |
| ----------- |-----------------------------------------------------------------------------------|
| sa / sb     | Swap: Swaps the first 2 elements at the top of stack a or b.                      |
| ss          | Performs sa and sb simultaneously.                                                |
| pa / pb     | Push: Takes the top element of one stack and puts it on top of the other.         |
| ra / rb     | Rotate: Shifts all elements up by 1; the first element becomes the last.          |
| rr          | Performs ra and rb simultaneously.                                                |
| rra / rrb   | Reverse Rotate: Shifts all elements down by 1; the last element becomes the first.|
| rrr         | Performs rra and rrb simultaneously.                                              |

## Example
### Selection-Sort
```
./push_swap 4 0 1 7 9
 4
 0
 1
 7
 9
---  ---
 a    b
----------- ra ----------(1)
 0
 1
 7
 9
 4
---  ---
 a    b
-------- pb + pb --------(2)
7
9      1
4      0
---  ---
 a    b
---------- rra ----------(1)
4
7      1
9      0
---  ---
 a    b
-------- pa + pa --------(2)
 0
 1
 4
 7     
 9     
---  ---
 a    b
Total Movements: (6)
```
### Cost-Sort
```
./push_swap 4 0 1 7 9
 4
 0
 1
 7 
 9
---  ---
 a    b
-------- pb + pb --------(2)
1
7     0
9     4
---  ---
 a    b
 Cost 1 = pb = (1)
 Cost 7 = ra + rb + pb = (3) --> rr + pb = (2)
 Cost 9 = rra + rb + pb = (3)
 Best Number = 1
----------- pb ----------(1)
      1
7     0
9     4
---  ---
 a    b
 Cost 7 = rrb + pb = (2)
 Cost 9 = rrb + rra + pb = (3)
 Best Number = 7
--------- rrb + pb ------(2)
      7
      4
      1
9     0
---  ---
 a    b
 Cost 9 = pb = (1)
 Best Number = 9
----------- pb ----------(1)
      9
      7
      4
      1
      0
---  ---
 a    b
---------- 5pa  ---------(5) 
 0   
 1     
 4     
 7    
 9    
---  ---
 a    b
Total Movements: (11)
```
