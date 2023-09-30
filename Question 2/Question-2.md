# Minimize Xor Difference

Given two integers A and B.

Find any integer X (0 ≤ X < 2^30^) such that the absolute difference between (A⊕X) - (B⊕X) is minimized. 

The symbol ⊕ represents the bitwise XOR operation, and |A| denotes the absolute value of A. 

If there are multiple X values that minimize the expression, you can output any of them.


#### Input Format

* The first line contains a single integer T, representing the number of test cases.
* Each test case is represented by a single line containing two space-separated integers A and B.

#### Output Format

For each test case, print on a new line the integer X (0 ≤ X < 2^30^) that minimizes the given expression. In the case of multiple possible answers, you can output any of them.

#### Constraints:

* 1 ≤ T ≤ 10^5^
* 1 ≤ A,B ≤ 2^30^


 |  Input  |  Output  |
 | ------- | -------- |
 |   4     |  4  |
 |   1 2   |  0  |
 |   3 3   |  11 |
 |   5 1   |  8  |
 |   0 1 5 |     |


 #### Explanation

 ##### Test Case 1:

The absolute difference |(4⊕1)−(4⊕2)| equals |5−6|=1. It's proven that the difference cannot be less than 1. Note that there are multiple acceptable answers; for example, X=0 or X=3 would also be valid.

##### Test Case 2:

The absolute difference |(3⊕0)−(3⊕0)| is |3−3|=0, which represents the minimum possible difference.

##### Test Case 3:

The absolute difference |(5⊕11)−(1⊕11)| is |14−10|=4, which is the optimal outcome.

##### Test Case 4:

The absolute difference |(0⊕8)−(15⊕8)| is |8−7|=1.