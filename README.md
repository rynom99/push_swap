*This project has been created as part of the 42 curriculum by \<mnououal\> and \<malshare\>.*

# push_swap

## Description

This project was developed with roles split between the authors: `mnououal` handled the structure and application design, while `malshare` implemented the sorting algorithms.

`push_swap` is a C program that sorts a list of integers using only two stacks.

The program supports three sorting strategies:
- `simple` for small sorted inputs
- `medium` for moderate-sized inputs
- `complex` for larger, highly disordered inputs

## Instructions

### Compilation

From the project root directory, run:

```sh
make
```

This command compiles all source files and generates the executable `push_swap`.

### Execution

Run the program with integer arguments:

```sh
./push_swap [--bench] [--simple|--medium|--complex|--adaptive] <numbers...>
```

Examples:

```sh
./push_swap 3 1 2
./push_swap --simple 5 2 4 1 3
./push_swap --bench --adaptive 12 5 9 1 8 3
```

### Flags

- `--simple` : force the simple sorting strategy
- `--medium` : force the medium sorting strategy
- `--complex` : force the complex sorting strategy
- `--adaptive` : default mode, chooses strategy automatically
- `--bench` : print benchmark statistics instead of the move sequence

## Algorithm

### Simple algorithm

Implemented in `simple_algorithm.c`, this strategy is selected for small inputs or when the input disorder is very low.

How it works:
- Repeatedly find the minimum value in `stack_a`
- Rotate `stack_a` until the minimum is on top
- Push the minimum to `stack_b`
- Continue until only 3 values remain in `stack_a`
- Sort the remaining 2 or 3 elements using dedicated case handling
- Push the values back from `stack_b` to `stack_a`

### Medium algorithm

Implemented in `medium_algorithm.c`, this strategy is chosen for moderate-sized inputs and when the disorder is not high.

How it works:
- Assign rank values to all elements
- Calculate a pivot from the current range of ranks
- Partition `stack_a` by pushing lower-ranked elements to `stack_b`
- Rotate `stack_b` for better placement of smaller elements
- When `stack_a` reaches 5 or fewer elements, sort it with case-specific routines
- Push elements back from `stack_b` to `stack_a` in descending rank order

### Complex algorithm

Implemented in `complex_algorithm.c`, this strategy is designed for larger and more disordered inputs.

How it works:
- Assign rank values to all elements
- Determine a chunk size based on input length
- Push elements from `stack_a` to `stack_b` in rank-based chunks
- Keep only a small sorted subset in `stack_a`
- Once the subset is manageable, sort it directly
- Move values back from `stack_b` to `stack_a` by selecting the largest available rank and minimizing rotations

### Adaptive mode

The default adaptive mode selects the algorithm based on the input disorder calculated by `ft_disorder`:
- low disorder → simple algorithm
- medium disorder → medium algorithm
- high disorder → complex algorithm

## Resources

- Youtube
- Unit test

### AI usage

AI assistance was used only for documentation tasks in this repository. The README content and project explanation were generated with AI support, while the source code logic remained unchanged.

## Project structure

- `main.c` — program entry and algorithm selection
- `ft_push_swap_helper.c` — CLI parsing, validation, and stack initialization
- `simple_algorithm.c` — minimal-case sorting strategy
- `medium_algorithm.c` — pivot-based partitioning strategy
- `complex_algorithm.c` — chunked rank-based sorting strategy
- `dumb_algorithm.c` — case-specific handlers for small stack sizes
- `stack.c` — stack management and operation executor
- `push.c`, `swap.c`, `rotate.c`, `reverse_rotate.c` — operation implementations
- `push_swap.h` — shared types and function declarations
- `Makefile` — build commands

