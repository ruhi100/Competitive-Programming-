# Partially Increasing Array Queries

An array B of size M is considered partially increasing if there exists an index i such that:

1 < i < M
B[i-1] ≤ B[i] ≤ B[i+1]

For example, [1,2,4,8], [1,2,8,4], [7,6,5,5,7] are partially increasing, while [1,2,1,3], [1,2], [7,6,5,6] are not.

Given an array A of size N and Q queries, each containing a pair of integers L and R, you need to print the length of the longest partially increasing subsequence of the subarray [AL, AL+1, AL+2, …, AR]. Print -1 if no partially increasing subsequence exists.

Note: A subsequence of an array is obtained by removing several (possibly, 0) elements from it. For example, [1,2,4], [2,3], [1,2,3,4] are subsequences of [1,2,3,4], but [4,2], [5] are not.


#### Input Format

* The first line contains a single integer T, representing the number of test cases.
* Each test case is composed of multiple lines.
    * The first line of each test case contains two space-separated integers N and Q, indicating the size of the array and the number of queries.
    * The next line contains N space-separated integers A1, A2, ..., AN, describing the array.
    * Each of the following Q lines contains two space-separated integers L and R, specifying the queries.

#### Output Format


For each test case, output Q lines. The i-th line should represent the answer for the i-th query.

#### Constraints:

* 1 ≤ T ≤ 5 × 10^4
* 3 ≤ N ≤ 2 × 10^5
* 1 ≤ Ai ≤ 10^9
* 1 ≤ Q ≤ 2 × 10^5
* 1 ≤ Li ≤ Ri ≤ N
* The sum of N and Q over all test cases won't exceed 2 × 10^5.


 |  Input  |  Output  |
 | ------- | -------- |
 |   1     |  4  |
 |   5 3   |  -1 |
 |   8 9 8 10 11   |  3 |
 |   2 5 |     |
 |   4 5 |     |
 |   1 4 |     |


 #### Explanation

 The given array is A = [8, 9, 8, 10, 11].

##### Query 1:

The subarray is [9, 8, 10, 11]. This subarray is partially increasing as it contains [8, 10, 11] as a subarray. Therefore, the answer is 4.

##### Query 2:

The subarray is [10, 11], but being of length 2, it can't be partially increasing. Hence, the answer is -1.

##### Query 3:

The subarray is [8, 9, 8, 10]. While the subarray itself is not partially increasing, we can choose the subsequence [8, 9, 10] which is partially increasing. Therefore, the answer is 3.