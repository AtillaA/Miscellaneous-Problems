Prime Number Calculator
------------------------
Problem Number: None
Difficulty: Hard


This is a seperate miscellaneous project that consists three different algorithms for detecting prime numbers in a given list of consecutive numbers [2,...,n].

1.) <u>Sieve of Eratosthenes:</u> Iterative approach of marking the multiples of each prime number.
                              - Iterate over the list of numbers [2,...,n]
                              - Mark all multiples of i as composite at each step
                              - Repeat for all numbers up to √n, reamining unmarked numbers are primes

2.) <u>Sieve of Sundaram:</u> Remove numbers from list and transform the remaining.
                              - Create an integer list from 1 to (n-1)/2
                              - Remove numbers of the form (i+j+2ij)
                              - Transform the remaining to get the primes

3.) <u>Sieve of Atkin:</u> Quadratic approach for marking and eliminating multiples of squares.
                              - Create an integer list and mark integers using specific quadratic equations
                              - Eliminate multiples of squares, remaining are primes


Time complexities:
1.) <u>Sieve of Eratosthenes:</u> O(n log log n)
2.) <u>Sieve of Sundaram:</u> O(n log n)
3.) <u>Sieve of Atkin:</u> O(n log n)
