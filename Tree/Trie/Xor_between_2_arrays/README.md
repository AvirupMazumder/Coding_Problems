### Problem Description

Given two integer array A and B, you have to pick one element from each array such that their xor is maximum.

Return this maximum xor value.



#### Problem Constraints

```
1 <= |A|, |B| <= 10^5

1 <= A[i], B[i] <= 10^9
```


#### Input Format

```
First argument is an integer array A.

Second argument is an integer array B.
```


#### Output Format

```
Return an integer denoting the maximum xor value as described in the question.
```

##### Example Input

```
Input 1:

 A = [1, 2, 3]
 B = [4, 1, 2]
```


##### Example Output

```
Output 1:

 7
```


##### Example Explanation

```
Explanation 1:

 Pick A[2] and B[0] because their xor value is maximum. 3 ^ 4 = 7
```


