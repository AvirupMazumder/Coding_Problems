### Problem Description
 
 
Given a set of digits (A) in sorted order, find how many numbers can be formed using these digits such that its length is B and whose value is less than the number C.

NOTE: All numbers can only have digits from the given set. 


#### Problem Constraints
```
0 <= |A| <= 10
1 <= B <= 9
0 <= C <= 1e9
0 <= A[i] <= 9
```

#### Input Format
```
The first argument is an integer array A.
The second argument is an integer B.
The third argument is an integer C.
```

#### Output Format
```
Return an integer.
```

Example Input
```
Input 1:

A = [0, 1, 5]
B = 1
C = 2

Input 2:

A = [0, 1, 2, 5]
B = 2
C = 21
```


Example Output
```
Output 1:

2

Output 2:

5
```


Example Explanation
```
Explanation 1:

0 and 1 are possible 

Explanation 2:

10, 11, 12, 15, 20 are possible
```
