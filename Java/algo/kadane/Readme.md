**Kadane's algorithm is used to solve Largest Sum Problem**

Leverage 2 sums - currentMax and globalMax to find the largest sum
e.g.
given Array A = [-2, -3, 4, -1, -2, 1, 5, -3]
the function should return 7 because:

index - 
(2, 3, 4, 5, 6) is a slice of A that has sum 7,

(5, 6) is a slice of A that has sum 6,

(0, 1, 2, 3) is a slice of A that has sum 2,

no other slice of A has sum greater than (2, 3, 4, 5, 6).

So largest sum is 7
