# Push Swap Sorting Project
Fun project focuses on sorting a given set of numbers in ascending order. The numbers are initially placed in **A stack**, and you can use a **B stack** as a helper. The goal is to achieve the highest score by performing the minimum number of actions.

## Visulaizer


## Allowed operations:
- sa (swap a): Swap the first 2 elements at the top of **stack A**.
- sb (swap b): Swap the first 2 elements at the top of **stack B**.
- ss : sa and sb at the same time.
- pa (push a): Take the first element at the top of **B stack** and put it at the top of **A stack**.
- pb (push b): Take the first element at the top of **A stack** and put it at the top of **B stack**.
- ra (rotate a): Shift up all elements of **stack A** by 1.
- rb (rotate b): Shift up all elements of **stack B** by 1.
- rr : ra and rb at the same time.
- rra (reverse rotate a): Shift down all elements of **stack A** by 1.
- rrb (reverse rotate b): Shift down all elements of **stack B** by 1.
- rrr : rra and rrb at the same time.

## My approach:

- first, count how many numbers are in the **A stack**.
- assign each number an index.
- start transferring numbers to **B stack** in chunks of three:
    - The first chunk contains the largest numbers (not sorted yet), followed by the middle, and then the smallest numbers.
- then transfer the numbers back to **A stack**, comparing each number with the one already on top:
    - If the number being transferred is smaller than the current top number, it stays on top. Simultaneously, if the number is larger than the one at the bottom of **A stack**, I move the bottom number to the top and place the current number on top of the former bottom number.
    - If the number being transferred is larger, it is placed at the bottom.

✅***Finally, all numbers are sorted.***
## Usage
1. Clone repository
2. Move to push_swap directory
```bash
cd push_swap
```
4. Run make file
```bash
make
```
6. Run the program (Consider the number in **stack A** in random order: 2 1 3 6 5 8)
```bash
$>./push_swap 2 1 3 6 5 8
```
## Expected output 
```bash
sa
pb
pb
pb
sa
pa
pa
pa
```
